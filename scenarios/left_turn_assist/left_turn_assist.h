#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class LeftTurnAssist : public Scenario {
 public:
  LeftTurnAssist() = default;
  virtual ~LeftTurnAssist() = default;

  bool Condition(const impl::EgoImpl &ego_impl,
                 const impl::EnvImpl &env_impl) override;

  // const RoadsideSafetyMessage &msg
  bool Notify() override;

 private:

};

}  // namespace scenario
}  // namespace shudao
