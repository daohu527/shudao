#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class EmergencyVehicle : public Scenario<RoadSideInformation> {
 public:
  EmergencyVehicle() = default;
  virtual ~EmergencyVehicle() = default;

  void Condition() override;
  
  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
