// Warn-logging macros!:

#ifdef ENABLE_WARN_LOGS
#include <Arduino.h>

/** @brief Logs without "[WARN] " prefixed. */
#define WARN_WRITE(...) Serial.print(__VA_ARGS__)

/** @brief Logs without "[WARN] " prefixed, and a new-line at the end. */
#define WARN_WRITELN(...) Serial.println(__VA_ARGS__)

/** @brief Logs with "[WARN] " prefixed. */
#define WARN_PRINT(...)         \
	Serial.print(F("[WARN] ")); \
	Serial.print(__VA_ARGS__)

/** @brief Logs with "[WARN] " prefixed, and a new-line at the end. */
#define WARN_PRINTLN(...)		\
  Serial.print(F("[WARN] "));	\
  Serial.println(__VA_ARGS__)

#else // Else, we define these as empty:

#define WARN_WRITE(...)
#define WARN_PRINT(...)
#define WARN_WRITELN(...)
#define WARN_PRINTLN(...)

#endif
