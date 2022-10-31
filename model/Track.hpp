#pragma once
#include <string>

namespace gp::model
{
class ATrack
{
protected:
  const std::string name;
  int laps;
public:
  ATrack() = default;
  ATrack(const std::string& name, int laps) : name(name), laps(laps) {}
  virtual ~ATrack() {}
  int getLaps() { return laps; }
  const std::string getName() { return name; }
};

class Track: public ATrack
{
public:
  Track(): ATrack() {}
  Track(const std::string& name, int laps): ATrack(name, laps) {}
  Track(const Track& track);
  virtual ~Track() {}
};
} //gp::model
