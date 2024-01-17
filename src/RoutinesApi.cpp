#include <Arduino.h>

#include "RoutinesApi.hpp"
#include "RoutinesApiDebugLogging.hpp"

namespace RoutinesApi {

	static std::initializer_list<RoutinesApi::IRoutine*> s_routinesList = { 0 };

	void setup() {
		DEBUG_PRINT_LN("In `RoutinesApi::setup()`...");
		s_routinesList = fixRoutinesList();

		const RoutinesApi::IRoutine *const *listEnd = s_routinesList.end();
		for (auto i = s_routinesList.begin(); i != listEnd; ++i)
			(*i)->setup();
	}

	void loop() {
		const RoutinesApi::IRoutine *const *listEnd = s_routinesList.end();
		for (auto i = s_routinesList.begin(); i != listEnd; ++i)
			(*i)->loop();
	}

}
