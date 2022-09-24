#include "RaceSimulator.hpp"
#include "../../model/Driver.hpp"
#include "../../model/Conditions.hpp"
#include <iostream>

namespace gp::simulator
{

void RaceSimulator::conductSession()
{
  simulate();
}

void RaceSimulator::simulate()
{
  for(int i=0; i < track->getLaps(); ++i)
  {
    std::cout<<"Lap="<<i;
    updateDriversResults();
    //updateCurrentConditions(i);
  }
}

void RaceSimulator::updateDriversResults()
{
  for_each(drivers.begin(), drivers.end(),
   [this](std::shared_ptr<model::ADriver> driver)
   {
     double score = driver->getExperience() + driver->getTeamExperience() - conditions->getCurrentConditionsScore();
     std::cout<<"score="<<score<<std::endl;
     driver->updateLapScore(score);
   });
}

void RaceSimulator::updateCurrentConditions(int lap)
{
  if (lap == (track->getLaps()*GrandPrixSession::trackChangeCoef))
  {
    conditions->setCurrentConditons();
  }
}

} //gp::simulator
