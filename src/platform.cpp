#include "platform.hpp"

#include "bindable.hpp"
#include "definition.hpp"
#include "source.hpp"

#include <iostream>

Platform::Platform() = default;

Platform::Platform(const PlatformDefinition &definition) : label_(definition.label()), priority_(definition.priority())
{
    for (auto &componentPath : definition.components())
    {
        Definition definition(componentPath);

        std::list<std::unique_ptr<Component>> tmpList;
        tmpList.emplace_back(definition.makeComponent());

        auto source = dynamic_cast<Source *>(tmpList.back().get());
        if (source)
        {
            labelMap[source->label()] = source;
        }

        components.merge(tmpList, [](auto &a, auto &b) {
            // Is a ordered before b?
            return a->priority() > b->priority();
        });
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

unsigned int Platform::priority() const
{
    return priority_;
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
