#pragma once
#include "../ISimulator.hpp"
#include "Track.hpp"


class RaceSimulator: public ISimulator
{
  ITrack* track;
public:
  RaceSimulator() {}
  void simulate();
};