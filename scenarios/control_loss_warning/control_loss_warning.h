#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ControlLossWarning : public Scenario<BasicSafetyMessage> {
 public:
  ControlLossWarning() = default;
  virtual ~ControlLossWarning() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
