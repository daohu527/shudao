#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class VehicleNearFieldPayment : public Scenario {
 public:
  VehicleNearFieldPayment() = default;
  virtual ~VehicleNearFieldPayment() = default;

  void Condition() override;

  void Notify(const RoadSideInformation &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
