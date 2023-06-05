#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class AbnormalVehicle : public Scenario<BasicSafetyMessage> {
 public:
  AbnormalVehicle() = default;
  virtual ~AbnormalVehicle() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
