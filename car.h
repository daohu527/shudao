#pragma once

#include <vector>

namespace shudao {
namespace app {

class Car {
 public:
  Car();
  virtual ~Car();

  bool Init();

 private:
  std::shared_ptr<GrpcServer> server_;
};

}  // namespace app
}  // namespace shudao
