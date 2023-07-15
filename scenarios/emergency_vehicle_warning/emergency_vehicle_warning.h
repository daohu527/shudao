#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class EmergencyVehicleWarning : public Scenario {
 public:
  EmergencyVehicleWarning() = default;
  virtual ~EmergencyVehicleWarning() = default;

  bool Condition(const impl::EgoImpl &ego_impl,
                 const impl::EnvImpl &env_impl) override;

  // const RoadSideInformation &msg
  bool Notify() override;

 private:

};

}  // namespace scenario
}  // namespace shudao
