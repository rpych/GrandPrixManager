#pragma once
#include <string>
#include <map>
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
  static std::map<std::string, model::Driver> drivers;
  static std::map<std::string, model::Driver> initDriversData();
public:
  static std::shared_ptr<model::ADriver> getDriver(const std::string& name);
  DriversData() = delete;
};

}