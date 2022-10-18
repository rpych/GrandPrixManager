#include "GrandPrix.hpp"
#include "GrandPrixSession.hpp"
#include "../model/Track.hpp"
#include "../model/Driver.hpp"
#include "../model/Team.hpp"
#include "../model/Tires.hpp"
#include "../model/Conditions.hpp"
#include "../model/Car.hpp"
#include "../data/ConditionsData.hpp"
#include "../data/DriversData.hpp"
#include "QualiSimulator.hpp"
#include "RaceSimulator.hpp"
#include <iostream>

using namespace gp::data;

namespace gp::simulator
{

void GrandPrix::prepareTrack()
{
  session->setTrack(std::make_unique<model::Track>("MonzaIt", 70, 0.6));
  std::cout<<"prepareTrack"<<std::endl;
}

void GrandPrix::prepareDriversToQuali()
{
  for(const auto& driverName: DriversData::getDriversNames())
  {
    session->addDriver(DriversData::getDriver(driverName));
  }
  /*session->addDriver(DriversData::getDriver("Lewis Hamilton"));
  std::cout<<"Hamilton added"<<std::endl;
  session->addDriver(DriversData::getDriver("George Russell"));
  session->addDriver(DriversData::getDriver("Charles Leclerc"));
  session->addDriver(DriversData::getDriver("Carlos Sainz"));*/
  std::cout<<"prepareDriversQuali"<<std::endl;
}

void GrandPrix::prepareDriversToRace(std::vector<std::shared_ptr<model::ADriver>> drivers)
{
  int position = 1;
  std::cout<<"prepareDriversToRace begin capacity = "<<drivers.capacity()<<std::endl;
  for(auto driverIt=drivers.begin(); driverIt != drivers.end(); ++driverIt)
  {
    std::cout<<"Driver = "<<(*driverIt)->getName()<<", position = "<<position<<std::endl;
    std::shared_ptr<model::ADriver> raceDriver = DriversData::getDriver((*driverIt)->getName());
    raceDriver->setStartingPositionWithScore(position);
    position++;
    
    session->addDriver(raceDriver);
  }

  std::cout<<"prepareDriversRace end"<<std::endl;
}

template<typename T>
void GrandPrix::setCurrentSession(std::unique_ptr<model::ATrack> track, std::shared_ptr<model::AConditions> conditions)
{
  session = std::make_shared<T>(std::move(track), conditions);
  std::cout<<"setCurrentSession "<<typeid(T).name()<<std::endl;
}

void GrandPrix::prepareQualiSession()
{
  setCurrentSession<simulator::QualiSimulator>(std::make_unique<model::Track>("MonzaIt", 70, 0.6),
  std::make_shared<model::Conditions>(data::ConditionsData::getConditions()));
  prepareTrack();
  prepareDriversToQuali();
}

void GrandPrix::prepareRaceSession()
{
  std::vector<std::shared_ptr<model::ADriver>> drivers = session->getSessionResults();

  setCurrentSession<simulator::RaceSimulator>(std::make_unique<model::Track>("MonzaIt", 70, 0.6),
  std::make_shared<model::Conditions>(data::ConditionsData::getConditions()));
  prepareTrack();
  prepareDriversToRace(drivers);
}

void GrandPrix::prepare()
{
  prepareQualiSession();
  session->conductSession();

  prepareRaceSession();
  session->conductSession();
}

}