#pragma once
#include "Emitter.h"
#include "variablesForTest.h"
#include <atomic>

namespace test {
	class PoolEmitters {
	public:
		std::array<Emitter, variablesForTest::countEmitterInPool>& getPoolEmitters();
		void spawnFreeEmitterOnPos(Emitter* freeEmitter, int startX, int startY);
		void spawnFreeEmitterOnPos(Emitter* freeEmitter, float startX, float startY);
		Emitter* getFreeEmitter();
		std::atomic_size_t& getBusyEmitterCounter();
		static PoolEmitters* getInstance();
		static void cleanup();
	private:
		PoolEmitters() = default;
		~PoolEmitters() = default;
		std::array<Emitter, variablesForTest::countEmitterInPool> poolEmitters;
		std::atomic_size_t poolEmittersCounter = 0U;
		std::atomic_size_t busyEmittersCounter = 0U;
	};
}

