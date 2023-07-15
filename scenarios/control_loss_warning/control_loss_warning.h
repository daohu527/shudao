#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ControlLossWarning : public Scenario {
 public:
  ControlLossWarning() = default;
  virtual ~ControlLossWarning() = default;

  bool Condition(const impl::EgoImpl &ego_impl,
                 const impl::EnvImpl &env_impl) override;

  bool Notify() override;

 private:

};

}  // namespace scenario
}  // namespace shudao
