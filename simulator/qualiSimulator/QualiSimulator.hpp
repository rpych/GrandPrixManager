#pragma once
#include <memory>
#include "../ISimulator.hpp"
#include "../GrandPrixSession.hpp"

namespace gp::simulator
{

class QualiSimulator: public GrandPrixSession, public ISimulator
{
  void updateDriversResults();
public:
  QualiSimulator(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions):
  GrandPrixSession(track, std::move(conditions)), ISimulator() {}
  virtual ~QualiSimulator() {}
  virtual void conductSession() override;
  virtual void simulate() override;
};

}