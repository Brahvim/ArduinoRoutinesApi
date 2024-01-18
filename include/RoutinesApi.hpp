#include <vector>

namespace RoutinesApi {

	void setup();

	void loop();

	/** @brief Abstract class representing a routine object. Love for the C++ guys, brothers and sisters! */
	class IRoutine {
	public:

		/** Called when the routine is first called. */
		virtual void setup() { };

		/** Called in `loop()` along with other `IRoutine` instances in the order of your routines list. */
		virtual void loop() { };

		/** Called when the routines list has been changed. */
		virtual void out() { };

	};

	typedef std::vector<RoutinesApi::IRoutine*> FixedSizeRoutinesList;

}

/** @brief Write an implementation for this to supply `RoutinesApi::IRoutine` instances. */
RoutinesApi::FixedSizeRoutinesList fixRoutinesList();
