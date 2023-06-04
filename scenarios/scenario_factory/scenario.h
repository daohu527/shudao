#pragma once

#include "impl/ego_impl.h"
#include "impl/env_impl.h"

namespace shudao {
namespace scenario {

template<class Msg>
class Scenario {
 public:
  virtual bool Condition(const impl::EgoImpl &ego_impl,
                         const impl::EnvImpl &env_impl) = 0;

  virtual bool Notify(const Msg &msg) = 0;
};

}  // namespace scenario
}  // namespace shudao
