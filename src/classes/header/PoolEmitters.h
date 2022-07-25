#pragma once
#include "Emitter.h"
#include "variablesForTest.h"

namespace test {
	class PoolEmitters {
	public:
		PoolEmitters() = default;
		~PoolEmitters() = default;
		std::array<Emitter, variablesForTest::countEmitterInPool>& getPoolEmitters();
		static PoolEmitters* getInstance();
		void spawnFreeEmitterOnPos(Emitter* freeEmitter, int startX, int startY);
		void spawnFreeEmitterOnPos(Emitter* freeEmitter, float startX, float startY);
		Emitter* getFreeEmitter();
		std::atomic_size_t& getBusyEmitterCounter();
	private:
		std::array<Emitter, variablesForTest::countEmitterInPool> poolEmitters;
		std::atomic_size_t poolEmittersCounter = 0U;
		std::atomic_size_t busyEmittersCounter = 0U;
	};
}

