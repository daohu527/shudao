#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class AbnormalVehicleWarning : public Scenario {
 public:
  AbnormalVehicleWarning() = default;
  virtual ~AbnormalVehicleWarning() = default;

  bool Condition(const impl::EgoImpl &ego_impl,
                 const impl::EnvImpl &env_impl) override;

  // const BasicSafetyMessage &msg
  bool Notify() override;

 private:

};

}  // namespace scenario
}  // namespace shudao
