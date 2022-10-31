#include "TeamsData.hpp"
#include "../model/Team.hpp"
#include <algorithm>
#include <iostream>

namespace gp::data
{

std::map<std::string, model::Team> TeamsData::initTeamsData()
{
  std::map<std::string, model::Team> teamsTmp;
  teamsTmp.emplace("Ferrari", model::Team("Ferrari", 0.87));
  teamsTmp.emplace("Mercedes", model::Team("Mercedes", 0.84));
  teamsTmp.emplace("Red Bull", model::Team("Red Bull", 0.90));
  teamsTmp.emplace("Alpine", model::Team("Alpine", 0.77));
  return teamsTmp;
}

std::map<std::string, model::Team> TeamsData::teams{initTeamsData()};

std::shared_ptr<model::ATeam> TeamsData::getTeamByName(const std::string& name)
{
  const auto& res = std::find_if(teams.begin(), teams.end(), [&name](const auto& team)
   {
     if(team.first == name) return true;
     else return false;
   });
  if(res != teams.end())
  {
    return std::make_shared<model::Team>(model::Team((*res).second));
  }
}

}