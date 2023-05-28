#pragma once

#include <vector>

#include "lib/vec3d.h"


namespace shudao {
namespace lib {

template <class T>
class Impl {
 public:
  virtual std::vector<T> GetNearBy(Vec3d point, double distance) = 0;


};


}
}
