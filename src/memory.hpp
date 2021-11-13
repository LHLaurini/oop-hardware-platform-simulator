#pragma once

#include "bindable.hpp"
#include "component.hpp"
#include "datavalue.hpp"
#include "memorydefinition.hpp"
#include "source.hpp"

#include <ctime>
#include <memory>
#include <optional>
#include <string>

class Memory : public Component, public Source, public Bindable
{
  public:
    Memory();
    Memory(const MemoryDefinition &definition);

    // getters
    std::string label() const override;
    unsigned int size() const;
    std::time_t accessTime() const;
    Source &source() const override;
    std::string sourceLabel() const override;

    // methods
    void bind(Source &source) override;
    void simulate() override;
    DataValue read() override;

  private:
    std::size_t nextPosition(std::size_t);
    void write(double value);

    std::string sourceLabel_;
    std::optional<Source *> source_;
    unsigned int size_;
    std::time_t accessTime_;
    std::string label_;
    std::unique_ptr<double[]> data;
    int numWait;
    std::size_t readHead;
    std::size_t writeHead;
};