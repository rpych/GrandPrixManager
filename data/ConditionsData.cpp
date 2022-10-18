#include "ConditionsData.hpp"
#include "../utils/TrackConditions.hpp"
#include "../utils/Randomizer.hpp"

namespace gp::data
{

std::map<int, std::vector<utils::TrackConditions>> ConditionsData::initConditionsTypes()
{
  std::map<int, std::vector<utils::TrackConditions>> conditionsSequenceMap;
  std::vector<utils::TrackConditions> conditionsSequence;
  conditionsSequence.push_back(utils::TrackConditions::DRY);
  conditionsSequence.push_back(utils::TrackConditions::DRY);
  conditionsSequence.push_back(utils::TrackConditions::DRY);

  conditionsSequenceMap.emplace(0, conditionsSequence);

  std::vector<utils::TrackConditions> conditionsSequence2;
  conditionsSequence2.push_back(utils::TrackConditions::DRY);
  conditionsSequence2.push_back(utils::TrackConditions::MEDIUM_WET);
  conditionsSequence2.push_back(utils::TrackConditions::WET);

  conditionsSequenceMap.emplace(1, conditionsSequence2);

  std::vector<utils::TrackConditions> conditionsSequence3;
  conditionsSequence3.push_back(utils::TrackConditions::DRY);
  conditionsSequence3.push_back(utils::TrackConditions::MEDIUM_WET);
  conditionsSequence3.push_back(utils::TrackConditions::MEDIUM_WET);

  conditionsSequenceMap.emplace(2, conditionsSequence3);

  std::vector<utils::TrackConditions> conditionsSequence4;
  conditionsSequence4.push_back(utils::TrackConditions::MEDIUM_WET);
  conditionsSequence4.push_back(utils::TrackConditions::MEDIUM_WET);
  conditionsSequence4.push_back(utils::TrackConditions::MEDIUM_WET);

  conditionsSequenceMap.emplace(3, conditionsSequence4);

  std::vector<utils::TrackConditions> conditionsSequence5;
  conditionsSequence5.push_back(utils::TrackConditions::MEDIUM_WET);
  conditionsSequence5.push_back(utils::TrackConditions::DRY);
  conditionsSequence5.push_back(utils::TrackConditions::DRY);

  conditionsSequenceMap.emplace(4, conditionsSequence5);

  return conditionsSequenceMap;
}

std::map<int, std::vector<utils::TrackConditions>> ConditionsData::conditionsTypes{initConditionsTypes()};

std::vector<utils::TrackConditions>& ConditionsData::getConditions()
{
  return conditionsTypes[utils::Randomizer::random(0, CONDITIONS_NUM)];
}

}