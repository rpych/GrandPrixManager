#pragma once
#include <string>

namespace gp::utils
{
 extern const int    NUM_OF_DRIVERS;
 extern const int    NUM_OF_TEAMS;
 extern const int    NUM_OF_QUALI_LAPS;
 extern const int    PIT_STOP_ON_MAX_LAP_AHEAD;
 extern const double MAX_DRIVER_EXP;
 extern const double COND_DURATION_COEF; //conditions unchanged by 0.3 time of session duration

 extern const int INVALID;
 extern const std::string CLASSIFICATION_FILE_PATH;
} //gp::utils