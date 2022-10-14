#pragma once
#include <map>
#include <string>
#include <memory>

namespace gp::model
{
  class ACar;
  class Car;
}

namespace gp::data
{

class CarsData
{
  static std::map<std::string, model::Car> cars;
  static std::map<std::string, model::Car> initCarsData();
public:
  static std::shared_ptr<model::ACar> getCar(const std::string& teamName);
  CarsData() = delete;
};


}
