#include "GrandPrixSession.hpp"
#include "../model/Track.hpp"
#include "../model/Driver.hpp"
#include "../model/Conditions.hpp"

namespace gp::simulator
{

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

} //gp::simulator