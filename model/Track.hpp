#pragma once
#include <string>

class ITrack
{};

class Track: public ITrack
{
  std::string name;
  int laps;
  int difficultyCoef;
public:

};