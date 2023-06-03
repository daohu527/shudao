#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class LeftTurnAssist : public Scenario<RoadsideSafetyMessage> {
 public:
  LeftTurnAssist() = default;
  virtual ~LeftTurnAssist() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
