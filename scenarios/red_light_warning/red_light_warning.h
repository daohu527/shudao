#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class RedLightWarning : public Scenario<RoadsideSafetyMessage> {
 public:
  RedLightWarning() = default;
  virtual ~RedLightWarning() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
