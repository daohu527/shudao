#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ForwardCollision : public Scenario<ForwardCollisionMsg> {
 public:
  ForwardCollision() = default;
  virtual ~ForwardCollision() = default;

  void Condition() override;
  
  void Notify(ForwardCollisionMsg* msg) override;

 private:

};

}  // namespace scenario
}  // namespace shudao
