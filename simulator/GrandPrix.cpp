#include "GrandPrix.hpp"
#include "GrandPrixSession.hpp"
#include "../model/Track.hpp"
#include "../model/Driver.hpp"
#include "../model/Team.hpp"
#include "../model/Tires.hpp"
#include "../model/Conditions.hpp"
#include "../model/Car.hpp"
#include "../model/PitStop.hpp"
#include "../data/ConditionsData.hpp"
#include "../data/DriversData.hpp"
#include "QualiSimulator.hpp"
#include "RaceSimulator.hpp"
#include <iostream>

using namespace gp::data;

namespace gp::simulator
{

void AGrandPrix::prepareDriversToQuali()
{
  for(const auto& driverName: DriversData::getDriversNames())
  {
    session->addDriver(DriversData::getDriver(driverName));
  }
}

void AGrandPrix::prepareDriversToRace(std::vector<std::shared_ptr<model::ADriver>> drivers)
{
  int position = 1;
  for(auto driverIt=drivers.begin(); driverIt != drivers.end(); ++driverIt)
  {
    std::shared_ptr<model::ADriver> raceDriver = DriversData::getDriver((*driverIt)->getName());
    raceDriver->setStartingPositionWithScore(position);
    position++;
    
    session->addDriver(raceDriver);
  }
}

template<typename T>
void AGrandPrix::setCurrentSession(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions)
{
  session = std::make_shared<T>(track, std::move(conditions));
}

void AGrandPrix::prepareQualiSession(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions)
{
  setCurrentSession<simulator::QualiSimulator>(track, std::move(conditions));
  prepareDriversToQuali();
}

void AGrandPrix::conductSession()
{
  session->conductSession();
}

std::vector<std::shared_ptr<model::ADriver>>& AGrandPrix::getSessionResults()
{
  return session->getSessionResults();
}

void AGrandPrix::prepareRaceSession(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions)
{
  //get quali results before new session starts
  std::vector<std::shared_ptr<model::ADriver>> drivers = getSessionResults();
  setCurrentSession<simulator::RaceSimulator>(track, std::move(conditions));
  prepareDriversToRace(drivers);
}

void AGrandPrix::setStrategyForDriver(const std::string& driverName, std::queue<std::shared_ptr<model::APitStop>> pitStops)
{
  session->addStrategyForCareerDriver(driverName, pitStops);
}

}