#pragma once
#include <memory>
#include <map>

namespace gp::utils
{
enum class TrackConditions;
enum class TireType;
}

using namespace gp::utils;

namespace gp::model
{
class ADriver;
class AConditions;

class APitWall
{
public:
  APitWall() {};
  virtual ~APitWall() {}
  virtual void preparePitStop(std::shared_ptr<ADriver> driver, std::shared_ptr<AConditions> conditions, int currentLap) = 0;
  virtual void chooseInitialTires(std::shared_ptr<ADriver> driver, std::shared_ptr<AConditions> conditions) = 0;
};

class PitWall: public APitWall
{
public:
  PitWall() : APitWall() {}
  virtual ~PitWall() {}
  void preparePitStop(std::shared_ptr<ADriver> driver, std::shared_ptr<AConditions> conditions, int currentLap) override;
  virtual void chooseInitialTires(std::shared_ptr<ADriver> driver, std::shared_ptr<AConditions> conditions) override;
private:
  TireType chooseNewTires(std::shared_ptr<AConditions> conditions);
};

}