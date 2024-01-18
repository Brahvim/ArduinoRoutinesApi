#include <Arduino.h>

#include "MacroUtils.hpp"
#include "RoutinesApi.hpp"
#include "RoutinesApiDebugLogging.hpp"

namespace RoutinesApi {

	static RoutinesApi::FixedSizeRoutinesList s_routinesList = { 0 };

	void setup() {
		DEBUG_PRINT_LN("In `RoutinesApi::setup()`...");
		s_routinesList = fixRoutinesList();

		for (auto i : s_routinesList)
			i->setup();
	}

	void loop() {
		for (auto i : s_routinesList)
			i->loop();
	}

}
