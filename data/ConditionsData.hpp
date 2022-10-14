#pragma once
#include <vector>
#include <map>
#include <memory>


namespace gp::utils
{
enum class TrackConditions;
}

namespace gp::data 
{
class ConditionsData
{
  static constexpr int CONDITIONS_NUM = 5; 
  static std::map<int, std::vector<utils::TrackConditions>> conditionsTypes;
  ConditionsData() = delete;
  static std::map<int, std::vector<utils::TrackConditions>> initConditionsTypes();
public:
  static std::vector<utils::TrackConditions>& getConditions();
};
}