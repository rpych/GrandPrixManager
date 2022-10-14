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
  virtual ~APitStop() {}
protected:
  int lap;
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