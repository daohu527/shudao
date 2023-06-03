#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class EmergencyBraking : public Scenario<BasicSafetyMessage> {
 public:
  EmergencyBraking() = default;
  virtual ~EmergencyBraking() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
