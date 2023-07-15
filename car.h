#pragma once

#include <vector>

#include "network/grpc_server.h"

namespace shudao {
namespace app {

class Car {
 public:
  Car();
  virtual ~Car();

  bool Init();

 private:
  std::shared_ptr<network::GrpcServer> server_;
};

}  // namespace app
}  // namespace shudao
