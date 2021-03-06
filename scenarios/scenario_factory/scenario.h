#pragma once

namespace shudao {
namespace scenario {

class Scenario {
 public:
  virtual void Condition() = 0;
  virtual void Notify() = 0;
};

}
}