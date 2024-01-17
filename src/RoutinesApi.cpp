#include <Arduino.h>

#include <map>
#include <list>
#include <vector>

#include "MacroUtils.hpp"
#include "RoutinesApi.hpp"
#include "BrahvimArduinoUtils.hpp"
#include "RoutinesApiDebugLogging.hpp"

#pragma region // Arduino `setup()`/`loop()` internalization code.
#ifndef ROUTINES_API_NO_CUSTOM_SETUP
namespace RoutinesApi { void setup(); }

void setup() {
	start();
	Serial.println("`start()` ended!");
	RoutinesApi::setup();
}
#endif

#ifndef ROUTINES_API_NO_CUSTOM_LOOP
namespace RoutinesApi { void loop(); }
void loop() {
	RoutinesApi::loop();
}
#endif
#pragma endregion

namespace RoutinesApi {

	static std::map<routine_t, IRoutine*> s_routinesLoopFxnMap;

#ifdef ROUTINES_API_DYNAMIC_LISTS
	static std::map<routines_list_t, std::vector<routine_t>> s_routineListsToRoutineVectorsMap;
	static routines_list_t s_currentRoutinesList;
#else
	static std::initializer_list<IRoutine*> s_currentRoutinesList;
#endif

#ifndef ROUTINES_API_NO_CUSTOM_SETUP
	void setup() { }
#endif
#ifndef ROUTINES_API_NO_CUSTOM_LOOP
	void loop() {
		for (auto i = s_currentRoutinesList.begin(); i != s_currentRoutinesList.end(); ++i) {
			// TODO!
		}
	}
#endif

#pragma region // Implementation without dynamic lists.
	const PROGMEM char* describeError(const RoutinesApi::ApiCallResult p_error) {
		switch (p_error) {
			case RoutinesApi::ApiCallResult::OK: {
				return (const PROGMEM char*) F(
					"Everything went fine!");
			} break;

			case RoutinesApi::ApiCallResult::MALLOC_FAILURE: {
				return (const PROGMEM char*) F(
					"A call to `malloc()` within `RoutinesApi`'s implementation failed.");
			} break;

			case RoutinesApi::ApiCallResult::ROUTINE_ABSENT: {
				return (const PROGMEM char*) F(
					"The routine with the ID passed does not exist!");
			} break;

			default:
			return (const PROGMEM char*) F(
				"Unknown error.");
		}
	}

	RoutinesApi::ApiCallResult setRoutinesList(const std::initializer_list<IRoutine*> p_currentRoutineList) { }

	bool doesRoutineExist(const routine_t p_id) { }

	RoutinesApi::ApiCallResult createRoutine(IRoutine &p_routine) { }

	RoutinesApi::ApiCallResult deleteRoutine(routine_t &p_id) { }
#pragma endregion

#if 0 // `IRoutine` things!
	IRoutine::IRoutine() {
		const RoutinesApi::ApiCallResult result = RoutinesApi::createRoutine(this->id);
		if (result == RoutinesApi::ApiCallResult::OK)
			return;

		DEBUG_PRINT_LN("Failed to instantiate an `IRoutine` instance! Reason:");
		/** @todo */
		switch (result) {
			case RoutinesApi::ApiCallResult::MALLOC_FAILURE: {
				DEBUG_PRINT("`malloc()` failed!");
			} break;

			default: { }
		}
	}

	IRoutine::~IRoutine() {
		switch (RoutinesApi::deleteRoutine(this->id)) {
			case RoutinesApi::ApiCallResult::ROUTINE_ABSENT: {
			} break;

			default: { }
		}
	}
#endif

#ifdef ROUTINES_API_DYNAMIC_LISTS // Data-oriented API functions for lists of routines!
	RoutinesApi::ApiCallResult setCurrentRoutinesList(const routines_list_t p_currentRoutineList) {
		s_currentRoutineList = p_currentRoutineList;
		return RoutinesApi::ApiCallResult::OK;
	}

	bool isRoutineList(const routine_t p_routineListId) {
		for (auto i : s_routineListsToRoutineVectorsMap)
			if (i.first == p_routineListId)
				return true;

		return false;
	}
#endif

	}
