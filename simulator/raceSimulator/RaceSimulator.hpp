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
    RaceSimulator(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions):
    GrandPrixSession(track, std::move(conditions)), ISimulator() {}
    virtual ~RaceSimulator() {}
    virtual void conductSession() override;
    virtual void simulate() override;
    void updateDriversResults(int lap);
    void updateCurrentConditions(int lap);
    bool shouldConditionsBeChanged(int lap);
  };
} //gp::simulator
