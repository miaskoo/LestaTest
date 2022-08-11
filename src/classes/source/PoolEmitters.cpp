#include "PoolEmitters.h"
#include "variablesForTest.h"

using namespace test;
static PoolEmitters* instance = nullptr;

std::array<Emitter, variablesForTest::countEmitterInPool>& PoolEmitters::getPoolEmitters() {
	return poolEmitters;
}

Emitter* PoolEmitters::getFreeEmitter() {
	// To speed up the search, I thought it would be better to create a busyEmittersCounter and check it,
	//and also make a poolEmittersCounter to get it faster.
	if (busyEmittersCounter.load(std::memory_order_relaxed) != variablesForTest::countEmitterInPool) {
		auto counter = poolEmittersCounter.load(std::memory_order_relaxed);
		if (counter >= poolEmitters.size()) {
			counter = 0U;
		}
		if (poolEmitters[counter].isFree()) {
			poolEmittersCounter.fetch_add(1, std::memory_order_relaxed);
			return &poolEmitters[counter];
		}
		for (auto n = counter + 1; n < poolEmitters.size(); n++) {
			if (poolEmitters[n].isFree()) {
				return &poolEmitters[n];
			}
		}
		for (auto n = 0; n < counter; n++) {
			if (poolEmitters[n].isFree()) {
				return &poolEmitters[n];
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
	if (!instance) {
		instance = new PoolEmitters();
	}
	return instance;
}

void PoolEmitters::cleanup() {
	delete instance;
	instance = nullptr;
}

std::atomic_size_t& PoolEmitters::getBusyEmitterCounter() {
	return busyEmittersCounter;
}