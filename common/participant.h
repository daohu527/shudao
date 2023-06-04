#pragma once

#include <string>
#include <memory>


#include "lib/point3d.h"
#include "lib/vec2d.h"

namespace shudao {
namespace common {

class Participant {
 public:
  Participant();
  virtual ~Participant();

 protected:
  std::string id;

  lib::Point3D pos;
  lib::Vec2D vec;
  lib::Vec2D acc;

  int l;
  int w;
  int h;
};

typedef ParticipantPtr std::shared_ptr<Participant>;

}  // namespace common
}  // namespace shudao
