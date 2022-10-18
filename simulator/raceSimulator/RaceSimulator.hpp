#pragma once
#include <algorithm>
#include <memory>
#include "../ISimulator.hpp"
#include "../../model/Track.hpp"
#include "../GrandPrixSession.hpp"

namespace gp::simulator
{
  class RaceSimulator: public GrandPrixSession, public ISimulator
  {
  public:
    RaceSimulator(std::unique_ptr<model::ATrack> track): GrandPrixSession(std::move(track)), ISimulator() {}
    virtual ~RaceSimulator() {}
    virtual void conductSession() override;
    virtual void simulate() override;
    void updateDriversResults(int lap);
    void updateCurrentConditions(int lap);
    bool shouldConditionsBeChanged(int lap);
  };
} //gp::simulator
