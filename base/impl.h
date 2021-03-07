#pragma once

#include <vector>

#include "base/vec3d.h"


namespace shudao {
namespace base {

template <class T>
class Impl {
 public:
  virtual std::vector<T> GetNearBy(Vec3d point, double distance) = 0;


};


}
}
