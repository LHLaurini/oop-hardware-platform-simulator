#pragma once

#include "bindable.hpp"
#include "component.hpp"
#include "datavalue.hpp"
#include "displaydefinition.hpp"
#include "source.hpp"

#include <optional>
#include <string>

class Display : public Component, public Bindable
{
  public:
    Display();
    Display(const DisplayDefinition &definition);

    // getters
    int refresh() const;
    Source &source() const override;
    std::string sourceLabel() const override;
    unsigned int priority() const override;

    // methods
    void bind(Source &source) override;
    void simulate(bool) override;

  private:
    std::string sourceLabel_;
    std::optional<Source *> source_;
    int refresh_;
    int numWait;
    unsigned int priority_;
};