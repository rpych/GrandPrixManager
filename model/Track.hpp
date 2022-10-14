#pragma once
#include <string>

namespace gp::model
{
class ATrack
{
  const std::string name;
  int laps;
  float difficultyCoef;
public:
  ATrack(const std::string& name, int laps, float difficultyCoef) : name(name), laps(laps), difficultyCoef(difficultyCoef) {}
  virtual ~ATrack() {}
  int getLaps() { return laps; }
};

class Track: public ATrack
{
public:
  Track(const std::string& name, int laps, float difficultyCoef): ATrack(name, laps, difficultyCoef) {}
  virtual ~Track() {}
};
} //gp::model
