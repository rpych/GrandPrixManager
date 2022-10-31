#pragma once
#include <memory>
#include <vector>
#include <queue>

namespace gp::model
{
  class ADriver;
  class ATrack;
  class AConditions;
  class APitStop;
}

namespace gp::simulator
{
class GrandPrixSession;

class AGrandPrix
{
public:
  AGrandPrix() {}
  virtual ~AGrandPrix() {}
  void prepareQualiSession(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions);
  void prepareRaceSession(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions);
  void setStrategyForDriver(const std::string& driverName, std::queue<std::shared_ptr<model::APitStop>> pitStops);
  std::vector<std::shared_ptr<model::ADriver>>& getSessionResults();
  void conductSession();
protected:
  std::shared_ptr<GrandPrixSession> session;
  void prepareDriversToQuali();
  void prepareDriversToRace(std::vector<std::shared_ptr<model::ADriver>> drivers);
  template<typename T> 
  void setCurrentSession(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions);
};

class GrandPrix: public AGrandPrix
{
public:
  GrandPrix(): AGrandPrix() {}
  virtual ~GrandPrix() {}
};
} //gp::simulator
