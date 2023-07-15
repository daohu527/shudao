#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class TrafficJamWarning : public Scenario {
 public:
  TrafficJamWarning() = default;
  virtual ~TrafficJamWarning() = default;

  void Condition() override;

  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
