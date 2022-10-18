#pragma once
#include <string>
#include <map>
#include <vector>
#include <memory>

namespace gp::model
{
  class ADriver;
  class Driver;
}

namespace gp::data
{

class DriversData
{
  static std::vector<std::string> driversNames;
  static std::map<std::string, model::Driver> drivers;
  static std::vector<std::string> initDriversNames();
  static std::map<std::string, model::Driver> initDriversData();
public:
  static std::shared_ptr<model::ADriver> getDriver(const std::string& name);
  static std::vector<std::string>& getDriversNames();
  DriversData() = delete;
};

}