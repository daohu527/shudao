#pragma once

#include "scenarios/scenario_factory/scenario.h"

namespace shudao {
namespace scenario {

class ForwardCollision : public Scenario {
 public:
  ForwardCollision() = default;
  virtual ~ForwardCollision() = default;

  void Condition() override;
  void Notify() override;

 private:

};

}  // namespace scenario
}  // namespace shudao
