#include <initializer_list>

#ifndef ROUTINES_API_NO_CUSTOM_SETUP
/** @brief Please use this instead of Arduino's `setup()`. `RoutinesApi` handles `loop()`. */
void start();
#endif

namespace RoutinesApi {

	/** @brief Error states for `RoutinesApi`. */
	enum class ApiCallResult {

		/** @brief My API uses `malloc()` because exceptions don't exist. CHECK FOR THIS! */
		MALLOC_FAILURE,

		/** @brief No such `RoutinesManager::Routine` object was registered! */
		ROUTINE_ABSENT,

		/** @brief Everything went fine, have a good day! */
		OK,

	};

	/** @brief Routines' handle/ID! "Holds routines"! */
	typedef size_t routine_t;

	const PROGMEM char* describeError(const RoutinesApi::ApiCallResult error);

	/** @brief Abstract class representing a routine object. Love for the C++ guys, brothers and sisters! */
	struct IRoutine {

		/** Called when the routine is first called. */
		virtual void setup() { };

		/** Called in `loop()` along with other `IRoutine` instances in the order of your routines list. */
		virtual void loop() { };

		/** Called when the routines list has been changed. */
		virtual void out() { };

	};

#pragma region // Routines API!
	bool doesRoutineExist(const routine_t id);
	RoutinesApi::ApiCallResult createRoutine(IRoutine &routine);
	RoutinesApi::ApiCallResult deleteRoutine(routine_t &id);
#pragma endregion

#ifdef ROUTINES_API_DYNAMIC_LISTS // Dynamic lists API.
	/** @brief Routine @e lists' handle/ID! "Holds routine lists"! */
	typedef size_t routines_list_t;

	RoutinesApi::ApiCallResult setCurrentRoutinesList(const routines_list_t p_currentRoutineList);

	bool doesRoutineListExist(const routines_list_t listId, const routine_t routineId);
	bool doesRoutineListInclude(const routines_list_t listId, const routine_t routineId);

	RoutinesApi::ApiCallResult createRoutineLiEst(routines_list_t &id);
	RoutinesApi::ApiCallResult deleteRoutineList(routines_list_t &id);

	RoutinesApi::ApiCallResult addRoutineToList(const routines_list_t listId, const routine_t routineId);
	RoutinesApi::ApiCallResult removeRoutineFromList(const routines_list_t listId, const routine_t routineId);

	RoutinesApi::ApiCallResult toggleRoutineInList(const routines_list_t listId, const routine_t routineId);
	RoutinesApi::ApiCallResult enableRoutineInList(const routines_list_t listId, const routine_t routineId);
	RoutinesApi::ApiCallResult disableRoutineInList(const routines_list_t listId, const routine_t routineId);

	RoutinesApi::ApiCallResult isRoutineEnabledForList(const routines_list_t listId, const routine_t routineId);
	RoutinesApi::ApiCallResult isRoutineEnabledAndInList(const routines_list_t listId, const routine_t routineId);
#else
	RoutinesApi::ApiCallResult setRoutinesList(const std::initializer_list<IRoutine*> currentRoutinesList);
#endif

}
