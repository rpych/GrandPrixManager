#include "DriversData.hpp"
#include "CarsData.hpp"
#include "../model/Driver.hpp"
#include <algorithm>

namespace gp::data
{

std::map<std::string, model::Driver> DriversData::initDriversData()
{
  std::map<std::string, model::Driver> driversTmp;
  driversTmp.emplace("Lewis Hamilton", model::Driver(1, "Lewis Hamilton", 0.95, CarsData::getCar("Mercedes")));
  driversTmp.emplace("George Russell", model::Driver(2, "George Russell", 0.87, CarsData::getCar("Mercedes")));
  driversTmp.emplace("Charles Leclerc", model::Driver(3, "Charles Leclerc", 0.87, CarsData::getCar("Ferrari")));
  driversTmp.emplace("Carlos Sainz", model::Driver(4, "Carlos Sainz", 0.78, CarsData::getCar("Ferrari")));
  return driversTmp;
}

std::map<std::string, model::Driver> DriversData::drivers{initDriversData()};

std::shared_ptr<model::ADriver> DriversData::getDriver(const std::string& name)
{
  const auto& res = std::find_if(drivers.begin(), drivers.end(), [&name](const auto& driver)
   {
     if(driver.first == name) return true;
     else return false;
   });
  if(res != drivers.end())
  {
    return std::make_shared<model::Driver>(model::Driver((*res).second));
  }
}

}