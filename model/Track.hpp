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
  int getLaps()
  {
    return laps;
  }  
};

class Track: public ATrack
{
public:
  Track(const std::string& name, int laps, float difficultyCoef): ATrack(name, laps, difficultyCoef) {}
};
} //gp::model
