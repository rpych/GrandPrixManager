#include "PitWall.hpp"
#include "PitStop.hpp"
#include "Driver.hpp"
#include "Tires.hpp"
#include "Conditions.hpp"
#include "../utils/TireType.hpp"
#include "../utils/TrackConditions.hpp"
#include "../utils/Randomizer.hpp"
#include "../utils/Constants.hpp"
#include <iostream>

namespace gp::model
{

void PitWall::preparePitStop(std::shared_ptr<ADriver> driver, std::shared_ptr<AConditions> conditions, int currentLap)
{
  std::cout<<"PIT_STOP_ON_MAX_LAP_AHEAD="<<utils::PIT_STOP_ON_MAX_LAP_AHEAD<<std::endl;
  int pitStopLap = utils::Randomizer::random(currentLap + 1, currentLap + 1 + utils::PIT_STOP_ON_MAX_LAP_AHEAD);
  TireType newTiresType = chooseNewTires(conditions);
  std::shared_ptr<Tires> newTires = std::make_shared<Tires>(0, newTiresType);
  driver->planPitStop(std::make_shared<PitStop>(pitStopLap, newTires));
} 

TireType PitWall::chooseNewTires(std::shared_ptr<AConditions> conditions)
{
  TrackConditions currentTrackConditions = conditions->getCurrentTrackConditions();
  TireType newTiresType = TireType::SOFT;
  int index = -1;
  std::vector<TireType> slickTires = {TireType::SOFT, TireType::MEDIUM, TireType::HARD};
  switch(currentTrackConditions)
  {
    case TrackConditions::DRY:
      index = Randomizer::random(0, 3);
      newTiresType = slickTires.at(index);
      break;
    case TrackConditions::MEDIUM_WET:
      newTiresType = TireType::INTERMEDIATE;
      break;
    case TrackConditions::WET:
      newTiresType = TireType::WET;
      break;
    default:
      break;
  }
  return newTiresType;
}

} 