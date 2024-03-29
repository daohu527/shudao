#pragma once

#include <vector>

namespace shudao {
namespace app {

class RSU {
 public:
  RSU();
  virtual ~RSU();

  bool Init();

 private:
  std::shared_ptr<MQTTServer> mqtt_server_;
};

}  // namespace app
}  // namespace shudao
