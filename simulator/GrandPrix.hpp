#pragma once
#include <memory>



namespace gp::simulator
{
class GrandPrixSession;

class GrandPrix
{
  void prepareSession();
  void prepareTrack();
  void prepareDrivers();
  void prepareConditions();
  void setCurrentSession();
  std::shared_ptr<GrandPrixSession> session;
public:
  GrandPrix() {}
  virtual ~GrandPrix() {}
  void prepare();
};
} //gp::simulator
