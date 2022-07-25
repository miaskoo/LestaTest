#include "Emitter.h"
#include <PoolEmitters.h>
#include "variablesForTest.h"

using namespace test;

bool Emitter::isFree() const {
	return free.load();
}

void Emitter::setFree(bool aFree) {
	if (free == aFree) {
		return;
	}
	free.store(aFree);
	PoolEmitters::getInstance()->getBusyEmitterCounter().fetch_add(!aFree ? 1 : -1, std::memory_order_relaxed);
}

std::array<Particle, variablesForTest::countParticleInEmitter>& Emitter::getPoolParticles() {
	return poolParticles;
}

void Emitter::initEmitter(float x, float y) {
	setFree(false);
	for (auto& particle : poolParticles) {
		particle.setPosition(x, y);
		particle.setSpeed(static_cast<float>(functionHelper::getRndBetween(variablesForTest::moduleStartSpeed, variablesForTest::minStartSpeedParticle)));
		particle.setDirection(functionHelper::getRndDirection());
		particle.setVisible(true);
		particle.setLifeTime(static_cast<float>(functionHelper::getRndBetween(variablesForTest::muduleLifeTime, variablesForTest::minLifeTimeParticle)));
		particle.setLockDown(false);
		particle.setFadeOutTime(variablesForTest::timeFadeOutParticle);
#ifdef MULTICOLOR_PARTICLE_MODE
		particle.setColor(functionHelper::getRndColor());
#else
		particle.setAlpha(variablesForTest::maxColor);
#endif
	}
}