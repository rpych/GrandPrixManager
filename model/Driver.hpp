#pragma once
#include <string>
#include <memory>
#include <queue>
#include "Car.hpp"


//class ATeam;

namespace gp::model
{
class ASessionInfo;
class APitStop;

class ADriver
{
public:
  ADriver(int number, const std::string& name, double experience, std::shared_ptr<ACar> car);
  virtual ~ADriver(){}
  int getNumber() { return number; }
  const std::string getName() { return name; }
  double getExperience() { return experience; }
  std::shared_ptr<ACar> getCar() { return car; }
  double getTeamExperience();
  double getSessionScore();
  void setStartingPositionWithScore(int position);
  virtual void updateLapScore(double score) = 0;
  virtual bool shouldRequestPitStop(double condAndTiresPaceFactor) = 0;
  virtual void planPitStop(std::shared_ptr<APitStop> pitStop) = 0;
  virtual void checkPitThisLap(int currentLap) = 0;
protected:
  int number;
  const std::string name;
  double experience;
  std::shared_ptr<ACar> car;
  std::queue<std::shared_ptr<APitStop>> pitStops;
  std::shared_ptr<ASessionInfo> sessionInfo;
};

class Driver: public ADriver
{
public:
  Driver(int number, const std::string& name, double experience, std::shared_ptr<ACar> car);
  Driver(const Driver& driver);
  virtual ~Driver(){}
  virtual void updateLapScore(double score) override;
  virtual void planPitStop(std::shared_ptr<APitStop> pitStop) override;
  virtual bool shouldRequestPitStop(double condAndTiresPaceFactor) override;
  virtual void checkPitThisLap(int currentLap) override;
private:
  void pit();
};

} //gp::modelvirtual void checkPitThisLap(int currentLap)