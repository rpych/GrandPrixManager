#include "GrandPrixSession.hpp"
#include "../model/Track.hpp"
#include "../model/Driver.hpp"
#include "../model/Conditions.hpp"
#include "../model/PitWall.hpp"
#include "../utils/Randomizer.hpp"
#include "../utils/Constants.hpp"

namespace gp::simulator
{

GrandPrixSession::GrandPrixSession(): drivers(), track(), conditions(), pitWall(std::make_shared<model::PitWall>())
{}

double GrandPrixSession::getMistakesFactor()
{
  return -(Randomizer::random(1, 4) / utils::NUM_OF_DRIVERS);
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

} //gp::simulator