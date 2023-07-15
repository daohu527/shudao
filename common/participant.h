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
  std::string id_;

  lib::Point3D pos_;
  lib::Vec2D vec_;
  lib::Vec2D acc_;

  float l_;
  float w_;
  float h_;
};

typedef ParticipantPtr std::shared_ptr<Participant>;

}  // namespace common
}  // namespace shudao
