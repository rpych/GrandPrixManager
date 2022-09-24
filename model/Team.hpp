#pragma once
#include <string>
#include <memory>
#include "Car.hpp"

namespace gp::model
{
class ATeam
{
public:
  ATeam(const std::string& name, double experience, std::shared_ptr<ACar> car);
  const std::string getName() { return name; }
  double getExperience() { return experience; }
  std::shared_ptr<ACar> getCar() { return car; }
protected:
  const std::string name;
  double experience;
  std::shared_ptr<ACar> car;
};

class Team: public ATeam
{
public:
  Team(const std::string& name, double experience, std::shared_ptr<ACar> car);
};
} //gp::model