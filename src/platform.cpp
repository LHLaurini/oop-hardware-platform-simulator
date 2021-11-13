#include "platform.hpp"

#include "bindable.hpp"
#include "definition.hpp"
#include "source.hpp"

#include <fstream>

Platform::Platform() = default;

Platform::Platform(const std::filesystem::path &path)
{
    std::ifstream stream(path);
    if (!stream)
    {
        throw std::runtime_error("failed to open file " + path.string());
    }

    for (std::string line; std::getline(stream, line);)
    {
        Definition definition(line);
        components.emplace_back(definition.makeComponent());

        auto source = dynamic_cast<Source *>(components.back().get());
        if (source)
        {
            labelMap[source->label()] = source;
        }
    }

    for (auto &component : components)
    {
        auto bindable = dynamic_cast<Bindable *>(component.get());
        if (bindable)
        {
            bindable->bind(*labelMap.at(bindable->sourceLabel()));
        }
    }
}

void Platform::simulate()
{
    for (auto &component : components)
    {
        component->simulate();
    }
}
