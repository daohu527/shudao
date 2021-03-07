#pragma once

#include "base/impl.h"
#include "vehicles/vehicle.h"

namespace shudao {
namespace vehicles {

class VehicleImpl : public shudao::base::Impl<Vehicle> {
 public:
  using Vec3d = shudao::base::Vec3d;
  using VehicleCache = shudao::base::ExpireLRUCache<std::string, Vehicle>;

  void AddVehicle();
  void GetVehicle(std::string vehicle_id) const;

  std::vector<Vehicle> GetNearBy(Vec3d point, double distance) override;

 private:
  VehicleCache vehicle_cache_;
};

}
}
