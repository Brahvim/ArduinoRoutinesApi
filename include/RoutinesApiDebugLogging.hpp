#ifdef ENABLE_ROUTINES_API_DEBUG_LOGS
#define ENABLE_DEBUG_LOGS
#endif

#include "PerFileLogging/DebugLogging.hpp"

#define ROUTINES_API_DEBUG_PRINTNP(...) DEBUG_PRINTNP("[RoutinesApi] " __VA_ARGS__)

#define ROUTINES_API_DEBUG_PRINT(...) DEBUG_PRINT("[RoutinesApi] " __VA_ARGS__)

#define ROUTINES_API_DEBUG_PRINTNPLN(...) DEBUG_PRINTNPLN("[RoutinesApi] " __VA_ARGS__)

#define ROUTINES_API_DEBUG_PRINTLN(...) DEBUG_PRINTLN("[RoutinesApi] " __VA_ARGS__)
