// Error-logging macros!:

#ifdef ENABLE_ERROR_LOGS
#include <Arduino.h>

/** @brief Logs without "[ERROR] " prefixed. */
#define ERROR_WRITE(...) Serial.print(__VA_ARGS__)

/** @brief Logs without "[ERROR] " prefixed, and a new-line at the end. */
#define ERROR_WRITELN(...) Serial.println(__VA_ARGS__)

/** @brief Logs with "[ERROR] " prefixed. */
#define ERROR_PRINT(...)         \
	Serial.print(F("[ERROR] ")); \
	Serial.print(__VA_ARGS__)

/** @brief Logs with "[ERROR] " prefixed, and a new-line at the end. */
#define ERROR_PRINTLN(...)		\
  Serial.print(F("[ERROR] "));	\
  Serial.println(__VA_ARGS__)

#else // Else, we define these as empty:

#define ERROR_WRITE(...)
#define ERROR_PRINT(...)
#define ERROR_WRITELN(...)
#define ERROR_PRINTLN(...)

#endif
