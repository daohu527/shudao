#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ReverseOvertakingWarning : public Scenario {
 public:
  ReverseOvertakingWarning() = default;
  virtual ~ReverseOvertakingWarning() = default;

  void Condition() override;

  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
