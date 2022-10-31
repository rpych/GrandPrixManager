#pragma once
#include <vector>
#include <memory>
#include <queue>
#include "../model/PitStop.hpp"

namespace gp::model
{
class ADriver;
class ATrack;
class AConditions;
class APitWall;
}

namespace gp::simulator
{
class GrandPrixSession
{
protected:
  std::vector<std::shared_ptr<model::ADriver>> drivers;
  std::shared_ptr<model::ATrack> track;
  std::shared_ptr<model::AConditions> conditions;
  std::shared_ptr<model::APitWall> pitWall;
public:
  GrandPrixSession(std::shared_ptr<model::ATrack> track, std::shared_ptr<model::AConditions> conditions);
  virtual ~GrandPrixSession() {}
  static double getMistakesFactor();
  void setTrack(std::unique_ptr<model::ATrack> track);
  void addDriver(std::shared_ptr<model::ADriver> driver);
  void setConditions(std::shared_ptr<model::AConditions> conditions);
  std::shared_ptr<model::AConditions> getConditions();
  std::vector<std::shared_ptr<model::ADriver>>& getSessionResults();
  void prepareDriversForSession();
  void addStrategyForCareerDriver(const std::string& driverName, std::queue<std::shared_ptr<model::APitStop>> pitStops);
  virtual void conductSession() = 0;
};
} //gp::simulator
  


