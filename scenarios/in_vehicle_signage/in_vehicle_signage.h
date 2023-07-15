#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class InVehicleSignage : public Scenario {
 public:
  InVehicleSignage() = default;
  virtual ~InVehicleSignage() = default;

  void Condition() override;

  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
