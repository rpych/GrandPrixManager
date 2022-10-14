#include "Driver.hpp"
#include "../utils/Constants.hpp"
#include "SessionInfo.hpp"
#include "PitStop.hpp"

using namespace gp::utils;

namespace gp::model
{

ADriver::ADriver(int number, const std::string& name, double experience, std::shared_ptr<ACar> car):
         number(number), name(name), experience(experience), car(car), sessionInfo(std::make_shared<SessionInfo>(INVALID)) {}

double ADriver::getTeamExperience()
{
  return car->getTeam()->getExperience();
}

//--------------------------

Driver::Driver(int number, const std::string& name, double experience, std::shared_ptr<ACar> car):
        ADriver(number, name, experience, car) {}

Driver::Driver(const Driver& driver):
        ADriver(driver.number, std::string(driver.name), driver.experience, std::make_shared<Car>(driver.car)) {}

void Driver::updateLapScore(double score)
{
  sessionInfo->updateScore(score);
}

void Driver::planPitStop(std::shared_ptr<APitStop> pitStop)
{
  pitStops.push(pitStop);
}

bool Driver::shouldRequestPitStop(double condAndTiresPaceFactor)
{
  return (pitStops.empty()) and (std::abs(condAndTiresPaceFactor) < std::abs(car->getTiresAgeFactor()));
}

void Driver::checkPitThisLap(int currentLap)
{
  if (not pitStops.empty() and (pitStops.front()->getLap() == currentLap))
  {
    pit();
  }
}

void Driver::pit()
{
  std::shared_ptr<APitStop> pitStop = pitStops.front();
  pitStops.pop();
  car->setTires(pitStop->getTires());
}

} //gp::model