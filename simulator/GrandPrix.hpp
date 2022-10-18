#pragma once
#include <memory>
#include <vector>

namespace gp::model
{
  class ADriver;
  class ATrack;
}

namespace gp::simulator
{
class GrandPrixSession;

class GrandPrix
{
  void prepareQualiSession();
  void prepareRaceSession();
  void prepareTrack();
  void prepareDriversToQuali();
  void prepareDriversToRace(std::vector<std::shared_ptr<model::ADriver>> drivers);
  template<typename T> void setCurrentSession(std::unique_ptr<model::ATrack> track);
  std::shared_ptr<GrandPrixSession> session;
public:
  GrandPrix() {}
  virtual ~GrandPrix() {}
  void prepare();
};
} //gp::simulator
