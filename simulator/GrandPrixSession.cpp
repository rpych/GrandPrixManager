#include "GrandPrixSession.hpp"
#include "../model/Track.hpp"
#include "../model/Driver.hpp"
#include "../model/Conditions.hpp"
#include "../model/PitWall.hpp"
#include "../model/Tires.hpp"
#include "../utils/Randomizer.hpp"
#include "../utils/Constants.hpp"

#include <algorithm>

namespace gp::simulator
{

GrandPrixSession::GrandPrixSession(std::shared_ptr<model::ATrack> track, std::shared_ptr<model::AConditions> conditions):
                  drivers(), track(track), conditions(conditions), pitWall(std::make_shared<model::PitWall>())
{}

double GrandPrixSession::getMistakesFactor()
{
  return -(static_cast<double>(Randomizer::random(1, 4)) / utils::NUM_OF_DRIVERS);
}

void GrandPrixSession::setTrack(std::unique_ptr<model::ATrack> _track)
{
  track = std::move(_track);
}

void GrandPrixSession::addDriver(std::shared_ptr<model::ADriver> driver)
{
  drivers.push_back(driver);
}

void GrandPrixSession::setConditions(std::shared_ptr<model::AConditions> _conditions)
{
  conditions = _conditions;
}

std::shared_ptr<model::AConditions> GrandPrixSession::getConditions()
{
  return conditions;
}

void GrandPrixSession::prepareDriversForSession()
{
  std::for_each(drivers.begin(), drivers.end(), [this](auto& driver)
  {
    pitWall->chooseInitialTires(driver, conditions);
  });
}

void GrandPrixSession::addStrategyForCareerDriver(const std::string& driverName, std::queue<std::shared_ptr<model::APitStop>> pitStops)
{
  auto careerDriverIt = std::find_if(drivers.begin(), drivers.end(), [driverName=driverName](auto& driver)
  {
    return driver->getName() == driverName;
  });

  if (careerDriverIt != drivers.end())
  {
    //first pitStop is done immediately before race
    if (not pitStops.empty())
    {
      std::shared_ptr<model::ATires> tires = pitStops.front()->getTires();
      pitStops.pop();
      (*careerDriverIt)->getCar()->setTires(tires);
    }

    while (not pitStops.empty())
    {
      (*careerDriverIt)->planPitStop(pitStops.front());
      pitStops.pop();
    }
  }
}

std::vector<std::shared_ptr<model::ADriver>>& GrandPrixSession::getSessionResults()
{
  std::sort(drivers.begin(), drivers.end(), [](std::shared_ptr<model::ADriver> dr1, std::shared_ptr<model::ADriver> dr2)
  {
    return dr1->getSessionScore() > dr2->getSessionScore();
  });

  return drivers;
}

} //gp::simulator