#pragma once

#include <vector>

#include "base/point3d.h"


namespace shudao {
namespace base {

template <class T>
class Impl {
 public:
  virtual std::vector<T> GetNearBy(Point3D point, double distance) = 0;


};


}
}
