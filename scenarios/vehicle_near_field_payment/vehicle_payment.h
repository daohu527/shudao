#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class VehiclePayment : public Scenario<RoadSideInformation> {
 public:
  VehiclePayment() = default;
  virtual ~VehiclePayment() = default;

  void Condition() override;
  
  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
