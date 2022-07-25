#include "PoolEmitters.h"
#include "variablesForTest.h"

using namespace test;

static PoolEmitters instance;

std::array<Emitter, variablesForTest::countEmitterInPool>& PoolEmitters::getPoolEmitters() {
	return poolEmitters;
}

Emitter* PoolEmitters::getFreeEmitter() {
	//To speed up the search time, i thought it would be better to check countBusy and also make a counter.
	if (busyEmittersCounter.load() != variablesForTest::countEmitterInPool) {
		auto counter = poolEmittersCounter.load();
		if (counter >= poolEmitters.size()) {
			counter = 0U;
		}
		if (poolEmitters[counter].isFree()) {
			poolEmittersCounter.store(counter + 1);
			return &poolEmitters[counter];
		}
		for (auto& emitter : poolEmitters) {
			if (emitter.isFree()) {
				return &emitter;
			}
		}
	}
	return nullptr;
}

void PoolEmitters::spawnFreeEmitterOnPos(Emitter* freeEmitter, int startX, int startY) {
	spawnFreeEmitterOnPos(freeEmitter, static_cast<float>(startX), static_cast<float>(startY));
}

void PoolEmitters::spawnFreeEmitterOnPos(Emitter* freeEmitter, float startX, float startY) {
	if (!freeEmitter) {
		return;
	}
	freeEmitter->initEmitter(static_cast<float>(startX), static_cast<float>(startY));
}

PoolEmitters* PoolEmitters::getInstance() {
	return &instance;
}

std::atomic_size_t& PoolEmitters::getBusyEmitterCounter() {
	return busyEmittersCounter;
}