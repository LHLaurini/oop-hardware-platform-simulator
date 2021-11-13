#include "platform.hpp"

#include "bindable.hpp"
#include "definition.hpp"
#include "source.hpp"

#include <iostream>

Platform::Platform() = default;

Platform::Platform(const PlatformDefinition &definition) : label_(definition.label())
{
    for (auto &componentPath : definition.components())
    {
        Definition definition(componentPath);
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

std::string Platform::label() const
{
    return label_;
}

void Platform::simulate(bool verbose)
{
    if (verbose)
    {
        std::clog << "Platform '" << label_ << "'\n\n";
    }

    for (auto &component : components)
    {
        component->simulate(verbose);
    }
}
