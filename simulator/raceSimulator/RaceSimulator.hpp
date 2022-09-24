#pragma once
#include <algorithm>
#include "../ISimulator.hpp"
#include "../../model/Track.hpp"
#include "../GrandPrixSession.hpp"

namespace gp::simulator
{
  class RaceSimulator: public GrandPrixSession, public ISimulator
  {
  public:
    RaceSimulator() {}
    virtual void simulate();
    void updateDriversResults();
    void updateCurrentConditions(int lap);
    virtual void conductSession() override;
  };
} //gp::simulator
