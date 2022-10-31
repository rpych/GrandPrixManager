#include "CarsData.hpp"
#include "TeamsData.hpp"
#include "../model/Car.hpp"
#include "../model/Tires.hpp"
#include <algorithm>
#include <iostream>

namespace gp::data
{

std::map<std::string, model::Car> CarsData::initCarsData()
{
  std::map<std::string, model::Car> carsTmp;
  carsTmp.emplace("Mercedes", model::Car("Mercedes", TeamsData::getTeamByName("Mercedes"), std::make_shared<model::Tires>()));
  carsTmp.emplace("Ferrari", model::Car("Ferrari", TeamsData::getTeamByName("Ferrari"), std::make_shared<model::Tires>()));
  carsTmp.emplace("Red Bull", model::Car("Honda", TeamsData::getTeamByName("Red Bull"), std::make_shared<model::Tires>()));
  carsTmp.emplace("Alpine", model::Car("Renault", TeamsData::getTeamByName("Alpine"), std::make_shared<model::Tires>()));
  return carsTmp;
}

std::map<std::string, model::Car> CarsData::cars{initCarsData()};

std::shared_ptr<model::ACar> CarsData::getCar(const std::string& teamName)
{
  const auto& res = std::find_if(cars.begin(), cars.end(), [&teamName](const auto& car)
   {
     if(car.first == teamName) return true;
     else return false;
   });
  if(res != cars.end())
  {
    return std::make_shared<model::Car>(model::Car((*res).second));
  }
}

}