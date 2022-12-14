#include "ConditionsData.hpp"
#include "../utils/TrackConditions.hpp"
#include "../utils/Randomizer.hpp"

namespace gp::data
{

std::map<int, std::vector<utils::TrackConditions>> ConditionsData::initConditionsTypes()
{
  std::map<int, std::vector<utils::TrackConditions>> conditionsSequenceMap;
  std::vector<utils::TrackConditions> conditionsSequence0 {utils::TrackConditions::DRY,
                                                          utils::TrackConditions::DRY,
                                                          utils::TrackConditions::DRY};

  conditionsSequenceMap.emplace(0, conditionsSequence0);

  std::vector<utils::TrackConditions> conditionsSequence1 {utils::TrackConditions::DRY,
                                                           utils::TrackConditions::MEDIUM_WET,
                                                           utils::TrackConditions::WET};

  conditionsSequenceMap.emplace(1, conditionsSequence1);

  std::vector<utils::TrackConditions> conditionsSequence2 {utils::TrackConditions::DRY,
                                                           utils::TrackConditions::MEDIUM_WET,
                                                           utils::TrackConditions::MEDIUM_WET};

  conditionsSequenceMap.emplace(2, conditionsSequence2);

  std::vector<utils::TrackConditions> conditionsSequence3 {utils::TrackConditions::MEDIUM_WET,
                                                           utils::TrackConditions::MEDIUM_WET,
                                                           utils::TrackConditions::MEDIUM_WET};

  conditionsSequenceMap.emplace(3, conditionsSequence3);

  std::vector<utils::TrackConditions> conditionsSequence4 {utils::TrackConditions::MEDIUM_WET,
                                                           utils::TrackConditions::DRY,
                                                           utils::TrackConditions::DRY};
  conditionsSequenceMap.emplace(4, conditionsSequence4);

  return conditionsSequenceMap;
}

std::map<int, std::vector<utils::TrackConditions>> ConditionsData::conditionsTypes{initConditionsTypes()};

std::vector<utils::TrackConditions>& ConditionsData::getConditions()
{
  return conditionsTypes[utils::Randomizer::random(0, CONDITIONS_NUM)];
}

}