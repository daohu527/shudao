#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class RedLightViolationWarning : public Scenario<RoadsideSafetyMessage> {
 public:
  RedLightViolationWarning() = default;
  virtual ~RedLightViolationWarning() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
