#include "GrandPrix.hpp"
#include "GrandPrixSession.hpp"
#include "../model/Track.hpp"
#include "../model/Driver.hpp"
#include "../model/Team.hpp"
#include "../model/Tires.hpp"
#include "../model/Conditions.hpp"

#include "RaceSimulator.hpp"
#include <iostream>

namespace gp::simulator
{

void GrandPrix::prepareTrack()
{
  session->setTrack(std::make_unique<model::Track>("MonzaIt", 70, 0.6));
  std::cout<<"prepareTrack"<<std::endl;
}

void GrandPrix::prepareDrivers()
{
  std::shared_ptr<model::ATeam>mercedes{std::make_shared<model::Team>("Mercedes", 90,
                                        std::make_shared<model::Car>("Mercedes", std::make_shared<model::Tires>()))};
  std::shared_ptr<model::ATeam>ferrari{std::make_shared<model::Team>("Ferrari", 85,
                                        std::make_shared<model::Car>("Ferrari", std::make_shared<model::Tires>()))};

  session->addDriver(std::make_shared<model::Driver>(1, "Lewis Hamilton", 95, mercedes));
  session->addDriver(std::make_shared<model::Driver>(2, "George Russell", 87, mercedes));
  session->addDriver(std::make_shared<model::Driver>(3, "Charles Leclerc", 87, ferrari));
  session->addDriver(std::make_shared<model::Driver>(4, "Carlos Sainz", 78, ferrari));
  std::cout<<"prepareDrivers"<<std::endl;
}

void GrandPrix::prepareConditions()
{
  session->setConditions(std::make_shared<model::Conditions>());
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