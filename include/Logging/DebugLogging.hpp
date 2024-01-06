// Debugging macros!:

#ifdef ENABLE_DEBUG_LOGS
#include <Arduino.h>

/** @brief Logs without "[DEBUG] " prefixed. */
#define DEBUG_WRITE(...) Serial.print(__VA_ARGS__)

/** @brief Logs without "[DEBUG] " prefixed, and a new-line at the end. */
#define DEBUG_WRITELN(...) Serial.println(__VA_ARGS__)

/** @brief Logs with "[DEBUG] " prefixed. */
#define DEBUG_PRINT(...)         \
	Serial.print(F("[DEBUG] ")); \
	Serial.print(__VA_ARGS__)

/** @brief Logs with "[DEBUG] " prefixed, and a new-line at the end. */
#define DEBUG_PRINTLN(...)		\
  Serial.print(F("[DEBUG] "));	\
  Serial.println(__VA_ARGS__)

#else // Else, we define these as empty:

#define DEBUG_WRITE(...)
#define DEBUG_PRINT(...)
#define DEBUG_WRITELN(...)
#define DEBUG_PRINTLN(...)

#endif
