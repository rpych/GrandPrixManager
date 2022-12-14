#include "QualiSimulator.hpp"
#include "../../model/Track.hpp"
#include "../../model/Driver.hpp"
#include "../../model/Tires.hpp"
#include "../../model/Conditions.hpp"
#include "../../data/ConditionsData.hpp"
#include "../../utils/Constants.hpp"

#include <algorithm>
#include <memory>
#include <iostream>

namespace gp::simulator
{

void QualiSimulator::conductSession()
{
  simulate();
}

void QualiSimulator::simulate()
{
  prepareDriversForSession();

  for(int i=0; i < utils::NUM_OF_QUALI_LAPS; ++i)
  {
    updateDriversResults();
  }
}

void QualiSimulator::updateDriversResults()
{
  std::for_each(drivers.begin(), drivers.end(),
   [this](std::shared_ptr<model::ADriver>& driver)
   {
     std::shared_ptr<model::ATires> carsTires = driver->getCar()->getTires();
     double score = driver->getExperience() + driver->getTeamExperience() +
                    conditions->getCurrentCondTirePaceFactor(carsTires) + getMistakesFactor();
     //std::cout<<driver->getName()<<" quali score="<<driver->getSessionScore()<<", with current score="<<score<<std::endl;
     driver->updateLapScore(score);
   });
}

}