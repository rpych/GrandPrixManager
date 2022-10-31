#pragma once
#include <string>
#include <memory>
#include <utility>
#include <map>
#include <vector>

namespace gp::utils
{
  enum class TrackConditions;
  enum class TireType;
}
using namespace gp::utils;

namespace gp::model
{
  class ATires;
  using TiresInConditions = std::pair<TrackConditions, TireType>;

  class AConditions 
  {
  protected:
    static std::map<TiresInConditions, double> condTirePaceFactors; 
    static std::map<TiresInConditions, double> initCondTirePaceFactors();

  public:
    AConditions();
    virtual ~AConditions() {}
    virtual double getCurrentCondTirePaceFactor(std::shared_ptr<model::ATires> tires) = 0;
    virtual void setCurrentConditons() = 0;
    virtual utils::TrackConditions getCurrentTrackConditions() = 0; 
  };

  class Conditions: public AConditions
  {
    std::vector<utils::TrackConditions> currentConditions;
    int conditionsNo;
  public:
    Conditions();
    virtual ~Conditions() {}
    Conditions(std::vector<utils::TrackConditions> conditions);
    virtual double getCurrentCondTirePaceFactor(std::shared_ptr<model::ATires> tires) override;
    virtual void setCurrentConditons() override;
    virtual utils::TrackConditions getCurrentTrackConditions();
    void changeConditions(); 
  };
} //gp::model