#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class OutOfControl : public Scenario<BasicSafetyMessage> {
 public:
  OutOfControl() = default;
  virtual ~OutOfControl() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
