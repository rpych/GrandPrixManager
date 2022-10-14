#pragma once
#include <string>
#include <memory>
//#include "Car.hpp"

namespace gp::model
{
class ATires;

class ATeam
{
public:
  ATeam(const std::string& name, double experience);
  virtual ~ATeam() {}
  const std::string getName() { return name; }
  double getExperience() { return experience; }
protected:
  const std::string name;
  double experience;
};

class Team: public ATeam
{
public:
  Team(const std::string& name, double experience);
  Team(const Team& team);
  virtual ~Team() {}
};
} //gp::model