#include "RaceSimulator.hpp"
#include "../../model/Driver.hpp"
#include "../../model/Conditions.hpp"
#include "../../model/Tires.hpp"
#include "../../model/PitWall.hpp"
#include "../../utils/Constants.hpp"
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
    updateDriversResults(i);
    //updateCurrentConditions(i);
  }
}

void RaceSimulator::updateDriversResults(int lap)
{
  std::for_each(drivers.begin(), drivers.end(),
   [this, lap](std::shared_ptr<model::ADriver>& driver)
   {
     std::shared_ptr<model::ATires> carsTires = driver->getCar()->getTires();
     double score = driver->getExperience() + driver->getTeamExperience() +
                    conditions->getCurrentCondTirePaceFactor(carsTires) + carsTires->getTiresAgeFactor() + getMistakesFactor();
     std::cout<<"score="<<score<<", tiresAge = "<<carsTires->getTiresAge()<<std::endl;
     driver->updateLapScore(score);

     if (driver->shouldRequestPitStop(conditions->getCurrentCondTirePaceFactor(carsTires)) 
         && (lap + utils::PIT_STOP_ON_MAX_LAP_AHEAD) < track->getLaps())
     {
       //std::cout<<"In shouldRequestPitStop"<<std::endl;
       pitWall->preparePitStop(driver, conditions, lap); 
     }
     driver->checkPitThisLap(lap);

     driver->getCar()->updateTiresAge();
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
