#include <random>
#include "Conditions.hpp"
#include "../utils/TrackConditions.hpp"

namespace gp::model
{

AConditions::AConditions()
{}

std::map<TrackConditions, int> AConditions::initDifficultyMap()
{
  std::map<TrackConditions, int> mapping;
  mapping[TrackConditions::DRY]        = 0.0;
  mapping[TrackConditions::MEDIUM_WET] = 0.2;
  mapping[TrackConditions::WET]        = 0.4;
  return mapping;
}

std::map<TrackConditions, int> AConditions::difficultyScore{initDifficultyMap()};


//-----------------------

Conditions::Conditions(): AConditions(), currentConditions(TrackConditions::DRY)
{}

int Conditions::getCurrentConditionsScore()
{
  return difficultyScore[currentConditions];
}

void Conditions::setCurrentConditons()
{
  changeConditions();
}

void Conditions::changeConditions()
{
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);
  switch(currentConditions)
  {
    case TrackConditions::DRY:
      currentConditions = (dist(rng) == 0) ? TrackConditions::MEDIUM_WET : TrackConditions::DRY;
      break;
    case TrackConditions::WET:
      currentConditions = (dist(rng) == 0) ? TrackConditions::MEDIUM_WET : TrackConditions::WET;
    case TrackConditions::MEDIUM_WET:
      int option = dist(rng);
      currentConditions = (option == 0) ? TrackConditions::MEDIUM_WET : (option == 1 ? TrackConditions::WET : TrackConditions::DRY);
      break;
  }
}

} //gp::model
