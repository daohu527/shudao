#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class SpeedLimitWarning : public Scenario {
 public:
  SpeedLimitWarning() = default;
  virtual ~SpeedLimitWarning() = default;

  void Condition() override;

  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
