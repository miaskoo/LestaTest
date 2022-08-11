#include "Physics.h"
#include "GlobalTime.h"
#include "PoolEmitters.h"
#include "nvToolsExt.h"
#include "variablesForTest.h"
#include "functionHelper.h"
#include "Render.h"

using namespace test;

Physics* instance = nullptr;

Physics::Physics() :
	thread(&Physics::threadUpdate, this)
{}

void Physics::start() {
	isStop.store(false);
	thread.detach();
}

void Physics::threadUpdate() {
	while (!isStop.load(std::memory_order_relaxed)) {
		nvtxRangePush(__FUNCTION__);
		auto time = GlobalTime::getInstance()->getTime();
		auto dt = time - lastUpdateTime;
		if (dt < variablesForTest::minUpdatePeriodPhysicx) {
			std::this_thread::sleep_for(std::chrono::milliseconds(variablesForTest::minUpdatePeriodPhysicx - dt));
			dt = variablesForTest::minUpdatePeriodPhysicx;
		}
		lastUpdateTime = time;
		update(dt);
		nvtxRangePop();
	}
}

void Physics::stop() {
	isStop.store(true, std::memory_order_relaxed);
}

void Physics::update(int dt) {
	float dtInSeconds = static_cast<float>(dt) / 1000.f;
	float gravityInSec = variablesForTest::gravity * dtInSeconds;
	
	const int maxParticleCount = variablesForTest::countParticleInEmitter;
	auto counterParticleisFree = 0;

	bool needCash = !Render::getInstance()->isDirty();
	if (needCash) {
		Render::getInstance()->getFrameForCash().clear();
	}

	for (auto& emitter : PoolEmitters::getInstance()->getPoolEmitters()) {
		if (emitter.isFree()) {
			continue;
		}
		for (auto& particle : emitter.getPoolParticles()) {
			if (particle.isVisible()) {
				if (particle.isDead() && !particle.isFadeOut()) {
					if (functionHelper::isÑhance(variablesForTest::percentSpawnNewEmitter)) {
						if (auto freeEmitter = PoolEmitters::getInstance()->getFreeEmitter()) {
							auto position = particle.getPosition();
							PoolEmitters::getInstance()->spawnFreeEmitterOnPos(freeEmitter, position.x, position.y);
							counterParticleisFree++;
							particle.setVisible(false);
						}
						else {
							particle.setFadeOut(true);
						}
					}
					else {
						particle.setFadeOut(true);
					}
				}
			}
			if (particle.isVisible()) {
				moveParticle(particle, dtInSeconds, gravityInSec);
				particle.update(dtInSeconds);	
				if (Render::isInRenderSpace(particle.getPosition()) && particle.getAlpha() != variablesForTest::minColor) {
					if (needCash) {
#ifdef MULTICOLOR_PARTICLE_MODE
						Render::getInstance()->getFrameForCash().emplace_back(particle.getPosition(), particle.getColor());
#else
						Render::getInstance()->getFrameForCash().emplace_back(particle.getPosition(), particle.getAlpha());
#endif
					}
				}
				else {
					particle.setVisible(false);
					counterParticleisFree++;
				}
			}
			else {
				counterParticleisFree++;
			}
		}
		if (counterParticleisFree == maxParticleCount) {
			if (!emitter.isFree()) {
				emitter.setFree(true);
			}
		}
		counterParticleisFree = 0;
	}
	if (needCash) {
		Render::getInstance()->markDirty();
	}
}

void Physics::moveParticle(Particle& particle, float dtInSeconds, float gravityInSeconds) {
	if (dtInSeconds < 0.f) {
		return;
	}
	auto currentPos = particle.getPosition();
	auto speed = particle.getSpeed() * dtInSeconds;
	auto currentDir = particle.getDirection();
	if (!particle.isLockDown()) {
		if (currentDir.x < 0.f) {
			functionHelper::rotateVector(currentDir, dtInSeconds * variablesForTest::rotateSpeedParticle);
			if (currentDir.x > 0.f) {
				currentDir = variablesForTest::DOWN;
				particle.setLockDown(true);
			}
		}
		else {
			functionHelper::rotateVector(currentDir, -dtInSeconds * variablesForTest::rotateSpeedParticle);
			if (currentDir.x < 0.f) {
				currentDir = variablesForTest::DOWN;
				particle.setLockDown(true);
			}
		}
	}
	currentDir.y -= gravityInSeconds;
	
	particle.setDirection(vector2{ currentDir.x, currentDir.y });
	particle.setPosition(currentPos.x + currentDir.x * speed, currentPos.y + currentDir.y * speed);
}

Physics* Physics::getInstance() {
	if (!instance) {
		instance = new Physics();
	}
	return instance;
}

void Physics::cleanup() {
	delete instance;
	instance = nullptr;
}