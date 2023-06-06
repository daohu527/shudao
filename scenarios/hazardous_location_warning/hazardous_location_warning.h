#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class HazardLocationWarning : public Scenario<RoadsideSafetyMessage> {
 public:
  HazardLocationWarning() = default;
  virtual ~HazardLocationWarning() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
