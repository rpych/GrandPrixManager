#pragma once
#include <string>
#include <memory>
#include <map>

namespace gp::utils
{
  enum class TrackConditions;
}
using namespace gp::utils;

namespace gp::model
{
  class AConditions 
  {
  protected:
    static std::map<TrackConditions, int> difficultyScore; 
    static std::map<TrackConditions, int> initDifficultyMap();

  public:
    AConditions();
    virtual int getCurrentConditionsScore() = 0;
    virtual void setCurrentConditons() = 0;
  };

  class Conditions: public AConditions
  {
    TrackConditions currentConditions;
  public:  
    Conditions();
    virtual int getCurrentConditionsScore();
    virtual void setCurrentConditons();
    void changeConditions(); 
  };
} //gp::model