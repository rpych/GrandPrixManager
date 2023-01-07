#include <Constants.hpp>

namespace gp::utils
{
 const int    NUM_OF_DRIVERS = 20;
 const int    NUM_OF_TEAMS = 10;
 const int    NUM_OF_QUALI_LAPS = 15;
 const int    PIT_STOP_ON_MAX_LAP_AHEAD = 6;
 const double MAX_DRIVER_EXP = 1.0;
 const double COND_DURATION_COEF = 0.3; //conditions unchanged by 0.3 time of session duration

 const int INVALID = 0xFFFFFFFF;
 const std::string CLASSIFICATION_FILE_PATH ("../storage/driversClassification.txt");
} //gp::utils