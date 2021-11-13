#pragma once

#include "bindable.hpp"
#include "component.hpp"
#include "datavalue.hpp"
#include "source.hpp"

#include <optional>
#include <queue>
#include <string>

class BusDefinition;

class Bus : public Component, public Source, public Bindable
{
  public:
    Bus();
    Bus(const BusDefinition &definition);

    // getters
    std::string label() const override;
    unsigned int width() const;
    std::string sourceLabel() const override;
    Source &source() const override;

    // methods
    void bind(Source &source) override;
    DataValue read() override;
    void simulate(bool verbose);

  private:
    std::string sourceLabel_;
    std::optional<Source *> source_;
    unsigned int width_;
    std::string label_;
    unsigned int numTimesRead;
    std::queue<double> pending;
    std::queue<double> ready;
};