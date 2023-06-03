#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class InVehicleSigns : public Scenario<RoadSideInformation> {
 public:
  InVehicleSigns() = default;
  virtual ~InVehicleSigns() = default;

  void Condition() override;
  
  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
