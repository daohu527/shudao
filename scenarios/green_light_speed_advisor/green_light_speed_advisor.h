#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class GreenLightSpeedAdvisor : public Scenario {
 public:
  GreenLightSpeedAdvisor() = default;
  virtual ~GreenLightSpeedAdvisor() = default;

  void Condition() override;

  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
