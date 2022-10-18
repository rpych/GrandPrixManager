#include "Car.hpp"
#include "Tires.hpp"
#include "../utils/TireType.hpp"

namespace gp::model
{

ACar::ACar(const std::string& engineProducer, std::shared_ptr<ATeam> team, std::shared_ptr<ATires> tires):
      engineProducer(engineProducer), team(team), tires(tires) {}

//------------

Car::Car(const std::string& engineProducer, std::shared_ptr<ATeam> team, std::shared_ptr<ATires> tires):
     ACar(engineProducer, team, tires) {}

Car::Car(const Car& car) : ACar(std::string{car.engineProducer}, car.team, std::make_shared<Tires>(car.tires))
{}

Car::Car(const std::shared_ptr<ACar> car) : ACar(car->getEngineProducer(), std::make_shared<Team>(car->getTeam()), std::make_shared<Tires>(car->getTires())) {}

double Car::getTiresAgeFactor()
{
  return tires->getTiresAgeFactor();
}

void Car::setTires(std::shared_ptr<ATires> newTires)
{
  tires = newTires;
}

void Car::updateTiresAge()
{
  tires->updateTiresAge();
}

}