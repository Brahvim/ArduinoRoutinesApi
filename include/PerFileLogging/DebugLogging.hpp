// Debugging macros!:

#pragma once

#ifdef ENABLE_DEBUG_LOGS
#include <Arduino.h>

#pragma region // Logging without a prefix.
/** @brief Logs whatever is passed. */
#define DEBUG_PRINTNP(...) Serial.print(__VA_ARGS__)

/** @brief Logs whatever is passed, with a new-line at the end. */
#define DEBUG_PRINTNPLN(...) Serial.println(__VA_ARGS__)
#pragma endregion

#pragma region // Logging with a prefix.
/** @brief Logs with "[DEBUG] " prefixed. */
#define DEBUG_PRINT(...)         \
	Serial.print(F("[DEBUG] ")); \
	Serial.print(__VA_ARGS__)

/** @brief Logs with "[DEBUG] " prefixed, and a new-line at the end. */
#define DEBUG_PRINTLN(...)		\
  Serial.print(F("[DEBUG] "));	\
  Serial.println(__VA_ARGS__)
#pragma endregion

#else // Else, we define these as empty:

// With a prefix:
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)

// Without a prefix:
#define DEBUG_PRINTNP(...)
#define DEBUG_PRINTNPLN(...)

#endif
