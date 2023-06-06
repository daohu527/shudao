#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class EmergencyVehicleWarning : public Scenario<RoadSideInformation> {
 public:
  EmergencyVehicleWarning() = default;
  virtual ~EmergencyVehicleWarning() = default;

  void Condition() override;
  
  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
