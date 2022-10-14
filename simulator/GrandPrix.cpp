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

void GrandPrix::prepareDrivers()
{
  //std::shared_ptr<model::ATeam>mercedes{std::make_shared<model::Team>("Mercedes", 90)}; 
  //std::shared_ptr<model::ACar>mercedesCar{std::make_shared<model::Car>("Mercedes", TeamsData::getTeamByName("Mercedes"), std::make_shared<model::Tires>())};
  
  //std::shared_ptr<model::ATeam>ferrari{std::make_shared<model::Team>("Ferrari", 85)};
  //std::shared_ptr<model::ACar>ferrariCar{std::make_shared<model::Car>("Ferrari", TeamsData::getTeamByName("Ferrari"), std::make_shared<model::Tires>())};

  session->addDriver(DriversData::getDriver("Lewis Hamilton"));
  std::cout<<"Hamilton added"<<std::endl;
  session->addDriver(DriversData::getDriver("George Russell"));
  session->addDriver(DriversData::getDriver("Charles Leclerc"));
  session->addDriver(DriversData::getDriver("Carlos Sainz"));
  std::cout<<"prepareDrivers"<<std::endl;
}

void GrandPrix::prepareConditions()
{
  session->setConditions(std::make_shared<model::Conditions>(data::ConditionsData::getConditions()));
  std::cout<<"prepareConditions"<<std::endl;
}

void GrandPrix::setCurrentSession()
{
  session = std::make_shared<RaceSimulator>();
  std::cout<<"setCurrentSession"<<std::endl;
}

void GrandPrix::prepareSession()
{
  setCurrentSession();
  prepareTrack();
  prepareDrivers();
  prepareConditions();
}

void GrandPrix::prepare()
{
  prepareSession();
  session->conductSession();
}

}