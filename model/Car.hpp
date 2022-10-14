#pragma once
#include <string>
#include <memory>
#include "Team.hpp"
#include <iostream>

namespace gp::model
{
class ATires;

class ACar
{
protected:
  const std::string engineProducer;
  std::shared_ptr<ATeam> team;
  std::shared_ptr<ATires> tires;
public:
  ACar(const std::string& engineProducer, std::shared_ptr<ATeam> team, std::shared_ptr<ATires> tires);
  virtual ~ACar() {/*std::cout<<"ACar destructor"<<std::endl;*/};
  const std::string& getEngineProducer() const { return engineProducer; }
  std::shared_ptr<ATeam> getTeam() const { return team; }
  std::shared_ptr<ATires> getTires() const { return tires; }
  virtual void setTires(std::shared_ptr<ATires> newTires) = 0;
  virtual double getTiresAgeFactor() = 0;
  virtual void updateTiresAge() = 0;
};

class Car: public ACar
{
public:
  Car(const std::string& engineProducer, std::shared_ptr<ATeam> team, std::shared_ptr<ATires> tires);
  Car(const std::shared_ptr<ACar> car);
  Car(const Car& car);
  virtual ~Car() { /*std::cout<<"Car destructor"<<std::endl;*/};
  virtual double getTiresAgeFactor() override;
  virtual void setTires(std::shared_ptr<ATires> newTires) override;
  virtual void updateTiresAge() override;
};
} //gp::model