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
  QualiSimulator(std::unique_ptr<model::ATrack> track) : GrandPrixSession(std::move(track)), ISimulator() {}
  virtual ~QualiSimulator() {}
  virtual void conductSession() override;
  virtual void simulate() override;
};

}