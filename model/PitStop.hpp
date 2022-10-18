#pragma once
#include <memory>

namespace gp::model
{
class ATires;

class APitStop
{
public:
  int getLap() { return lap; } 
  std::shared_ptr<ATires> getTires() { return tires; }
  double getPitPenalty() { return pitPenalty; }
  virtual ~APitStop() {}
protected:
  int lap;
  double pitPenalty;
  std::shared_ptr<ATires> tires;
  APitStop(int lap, std::shared_ptr<ATires> tires);
};

class PitStop: public APitStop
{
public:
  PitStop(int lap, std::shared_ptr<ATires> tires);
  virtual ~PitStop() {}
};

}