#include <vector>

#pragma once

namespace RoutinesApi {

	/** @brief Please call this in your Arduino code's `setup()`. Anywhere in there. */
	void setup();

	/** @brief Please call this in your Arduino code's `loop()`. Anywhere in there. */
	void loop();

	/** @brief Abstract class representing a routine object. */
	class IRoutine {
	public:

		// No virtual destructor needed! Who's removing routines...?
		virtual ~IRoutine() = default;

		/** @brief Called when this routine is first called. */
		virtual void setup() { };

		/** @brief Called in yor sketch's `loop()` along with other `IRoutine` instances's `loop()` method,
		 *  in the order of your routines list. */
		virtual void loop() { };

		/** @brief Called when the routines list has been changed. */
		virtual void out() { };

		/**
		 * @brief This method enables/disables the routine object.
		 * @param newStatus this decides whether or not the routine is enabled.
		 * @return The previous state of being enabled - the same as `IRoutine::isEnabled()`'s.
		 */
		bool setStatus(bool newStatus);

		/**
		 * @brief This method inverts the enabled/disabled state of the routine object.
		 * @return The previous state of being enabled - the same as `IRoutine::isEnabled()`'s.
		 */
		bool toggle();

		/**
		 * @brief This method enables the routine object.
		 * @return The previous state of being enabled - the same as `IRoutine::isEnabled()`'s.
		 */
		bool enable();

		/**
		 * @brief This method disables the routine object.
		 * @return The previous state of being enabled - the same as `IRoutine::isEnabled()`'s.
		 */
		bool disable();

		/** @return A `bool` indicating if the routine has been disabled. */
		bool isEnabled() const;

	private:
		bool status;
	};

	/**
	 * @brief Simple type-definition to avoid typing too much.
	 * This is to be used as the return type for `supplyRoutines()`.
	 * Make sure to allocate this on the heap!
	 */
	typedef std::vector<RoutinesApi::IRoutine*> FixedSizeRoutinesList;

}

/** @brief Write an implementation for this to supply `RoutinesApi::IRoutine` instances. */
RoutinesApi::FixedSizeRoutinesList supplyRoutines();
