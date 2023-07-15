#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class BlindSpotWarning : public Scenario {
 public:
  BlindSpotWarning() = default;
  virtual ~BlindSpotWarning() = default;

  bool Condition(const impl::EgoImpl &ego_impl,
                 const impl::EnvImpl &env_impl) override;

  bool Notify() override;

 private:

};

}  // namespace scenario
}  // namespace shudao
