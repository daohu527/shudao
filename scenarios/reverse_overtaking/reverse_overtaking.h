#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ReverseOvertaking : public Scenario<BasicSafetyMessage> {
 public:
  ReverseOvertaking() = default;
  virtual ~ReverseOvertaking() = default;

  void Condition() override;
  
  void Notify(const BasicSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
