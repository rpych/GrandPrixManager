#include "Team.hpp"

namespace gp::model
{

ATeam::ATeam(const std::string& name, double experience, std::shared_ptr<ACar> car):
     name(name), experience(experience), car(car){}

//-----------
Team::Team(const std::string& name, double experience, std::shared_ptr<ACar> car):
      ATeam(name, experience, car) {}

} //gp::model