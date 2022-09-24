#include "Driver.hpp"
#include "../utils/Constants.hpp"
#include "SessionInfo.hpp"

using namespace gp::utils;

namespace gp::model
{

ADriver::ADriver(int number, const std::string& name, double experience, std::shared_ptr<ATeam> team):
         number(number), name(name), experience(experience), team(team), sessionInfo(std::make_shared<SessionInfo>(INVALID)) {}

double ADriver::getTeamExperience()
{
  return team->getExperience();
}

//--------------------------

Driver::Driver(int number, const std::string& name, double experience, std::shared_ptr<ATeam> team):
        ADriver(number, name, experience, team) {}

void Driver::updateLapScore(double score)
{
  sessionInfo->updateScore(score);
}
  
} //gp::model