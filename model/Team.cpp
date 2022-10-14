#include "Team.hpp"
#include "Tires.hpp"

namespace gp::model
{

ATeam::ATeam(const std::string& name, double experience):
     name(name), experience(experience) {}

//-----------
Team::Team(const std::string& name, double experience):
      ATeam(name, experience) {}

Team::Team(const Team& team) : ATeam(std::string{team.name}, team.experience)
{}

} //gp::model