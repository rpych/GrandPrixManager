#include "PitStop.hpp"
#include "../utils/TireType.hpp"
#include "../utils/Randomizer.hpp"

namespace gp::model
{

APitStop::APitStop(int lap, std::shared_ptr<ATires> tires): lap(lap), tires(tires)
{
  pitPenalty = -(utils::Randomizer::random(10, 13));
}

//-----------
PitStop::PitStop(int lap, std::shared_ptr<ATires> tires): APitStop(lap, tires) 
{}



}