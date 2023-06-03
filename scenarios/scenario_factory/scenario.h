#pragma once

namespace shudao {
namespace scenario {

template<class Msg>
class Scenario {
 public:
  virtual void Condition() = 0;
  virtual void Notify(const Msg &msg) = 0;
};

}  // namespace scenario
}  // namespace shudao
