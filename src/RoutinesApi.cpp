#include <Arduino.h>

#include <map>
#include <list>
#include <vector>

#include "MacroUtils.hpp"
#include "RoutinesApi.hpp"
#include "BrahvimArduinoUtils.hpp"
#include "RoutinesApiDebugLogging.hpp"

namespace RoutinesApi {

	static std::initializer_list<RoutinesApi::IRoutine*> s_currentRoutinesList = fixRoutinesList();

	void setup() {
	}

	void loop() {
	}

}
