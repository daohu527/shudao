#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class EmergencyBrakeWarning : public Scenario<BasicSafetyMessage> {
 public:
  EmergencyBrakeWarning() = default;
  virtual ~EmergencyBrakeWarning() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
