#include "DriversData.hpp"
#include "CarsData.hpp"
#include "../model/Driver.hpp"
#include <algorithm>

namespace gp::data
{

std::vector<std::string> DriversData::initDriversNames()
{
  std::vector<std::string> driversNamesTmp{"Lewis Hamilton", "George Russell", "Charles Leclerc", "Carlos Sainz", 
                                           "Max Verstappen", "Sergio Perez", "Fernando Alonso", "Esteban Ocon"};
  return driversNamesTmp;
}

std::map<std::string, model::Driver> DriversData::initDriversData()
{
  std::map<std::string, model::Driver> driversTmp;
  driversTmp.emplace("Lewis Hamilton", model::Driver(1, "Lewis Hamilton", 0.94, CarsData::getCar("Mercedes")));
  driversTmp.emplace("George Russell", model::Driver(2, "George Russell", 0.87, CarsData::getCar("Mercedes")));
  driversTmp.emplace("Charles Leclerc", model::Driver(3, "Charles Leclerc", 0.87, CarsData::getCar("Ferrari")));
  driversTmp.emplace("Carlos Sainz", model::Driver(4, "Carlos Sainz", 0.82, CarsData::getCar("Ferrari")));
  driversTmp.emplace("Max Verstappen", model::Driver(5, "Max Verstappen", 0.94, CarsData::getCar("Red Bull")));
  driversTmp.emplace("Sergio Perez", model::Driver(6, "Sergio Perez", 0.84, CarsData::getCar("Red Bull")));
  driversTmp.emplace("Fernando Alonso", model::Driver(7, "Fernando Alonso", 0.92, CarsData::getCar("Alpine")));
  driversTmp.emplace("Esteban Ocon", model::Driver(8, "Esteban Ocon", 0.79, CarsData::getCar("Alpine")));
  return driversTmp;
}

std::vector<std::string> DriversData::driversNames{initDriversNames()};

std::map<std::string, model::Driver> DriversData::drivers{initDriversData()};

std::vector<std::string>& DriversData::getDriversNames()
{
  return driversNames;
}

std::shared_ptr<model::ADriver> DriversData::getDriver(const std::string& name)
{
  const auto& res = std::find_if(drivers.begin(), drivers.end(), [&name](const auto& driver)
   {
     return driver.first == name;
   });
  if(res != drivers.end())
  {
    return std::make_shared<model::Driver>(model::Driver((*res).second));
  }
  return std::shared_ptr<model::Driver>(nullptr);
}

}