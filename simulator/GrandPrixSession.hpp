#pragma once
#include <vector>
#include <memory>

namespace gp::model
{
class ADriver;
class ATrack;
class AConditions;
}

namespace gp::simulator
{
class GrandPrixSession
{
protected:
  static constexpr float trackChangeCoef = 0.5f;
  std::vector<std::shared_ptr<model::ADriver>> drivers;
  std::shared_ptr<model::ATrack> track;
  std::shared_ptr<model::AConditions> conditions;
public:
  void setTrack(std::unique_ptr<model::ATrack> track);
  void addDriver(std::shared_ptr<model::ADriver> driver);
  void setConditions(std::shared_ptr<model::AConditions> conditions);
  virtual void conductSession() = 0;
};
} //gp::simulator
  


