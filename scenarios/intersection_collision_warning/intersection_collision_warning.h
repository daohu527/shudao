#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class IntersectionCollisionWarning : public Scenario<RoadsideSafetyMessage> {
 public:
  IntersectionCollisionWarning() = default;
  virtual ~IntersectionCollisionWarning() = default;

  void Condition() override;
  
  void Notify(const RoadsideSafetyMessage &msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
