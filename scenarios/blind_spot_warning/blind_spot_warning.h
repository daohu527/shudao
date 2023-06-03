#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class BlindSpotWarning : public Scenario<BasicSafetyMessage> {
 public:
  BlindSpotWarning() = default;
  virtual ~BlindSpotWarning() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
