#pragma once
#include <string>
#include <memory>
#include "Team.hpp"
//#include "SessionInfo.hpp"


//class ATeam;

namespace gp::model
{
class ASessionInfo;

class ADriver
{
public:
  ADriver(int number, const std::string& name, double experience, std::shared_ptr<ATeam> team);
  int getNumber() { return number; }
  std::string getName() { return name; }
  double getExperience() { return experience; }
  std::shared_ptr<ATeam> getTeam() { return team;}
  virtual void updateLapScore(double score) = 0;
  double getTeamExperience();
protected:
  int number;
  const std::string name;
  double experience;
  std::shared_ptr<ATeam> team;
  std::shared_ptr<ASessionInfo> sessionInfo;
};

class Driver: public ADriver
{
public:
  Driver(int number, const std::string& name, double experience, std::shared_ptr<ATeam> team);
  virtual void updateLapScore(double score);
};

} //gp::model