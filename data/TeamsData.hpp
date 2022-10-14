#pragma once
#include <string>
#include <memory>
#include <map>

namespace gp::model
{
  class ATeam;
  class Team;
}

namespace gp::data
{
  
class TeamsData
{
  static std::map<std::string, model::Team> teams;
  static std::map<std::string, model::Team> initTeamsData();
public:
  static std::shared_ptr<model::ATeam> getTeamByName(const std::string& name);
  TeamsData() = delete;
};

}