#include <Arduino.h>

#include "RoutinesApi.hpp"
#include "RoutinesApiDebugLogging.hpp"

namespace RoutinesApi {

	static RoutinesApi::FixedSizeRoutinesList s_routinesList = { nullptr };

	void setup() {
		DEBUG_PRINT_LN("In `RoutinesApi::setup()`...");
		s_routinesList = supplyRoutines();

		for (auto i : s_routinesList)
			i->setup();
	}

	void loop() {
		for (auto i : s_routinesList)
			if (i->isEnabled())
				i->loop();
	}

#pragma region // `RoutinesApi::IRoutine` methods.
	bool IRoutine::setStatus(bool p_status) {
		const bool toRet = this->status;
		this->status = p_status;
		return toRet;
	}

	bool IRoutine::toggle() {
		const bool toRet = this->status;
		this->status = !this->status;
		return toRet;
	}

	bool IRoutine::enable() {
		const bool toRet = this->status;
		this->status = true;
		return toRet;
	}

	bool IRoutine::disable() {
		const bool toRet = this->status;
		this->status = false;
		return toRet;
	}

	bool IRoutine::isEnabled() const {
		return this->status;
	}
#pragma endregion

}
