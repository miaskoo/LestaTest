#pragma once
#include "structHelper.h"
#include <array>

namespace variablesForTest {
	const int minUpdatePeriodPhysicx = 5;
	const float gravity = 1;
	const int minStartSpeedParticle = 120;
	const int maxStartSpeedParticle = 240;
	const int moduleStartSpeed = maxStartSpeedParticle - minStartSpeedParticle;
	const float percentSpawnNewEmitter = 0.1f; // betwen 0.f and 1.f
	const int minLifeTimeParticle = 1;
	const int maxLifeTimeParticle = 5;
	const int muduleLifeTime = maxLifeTimeParticle - minLifeTimeParticle;
	const float rotateSpeedParticle = 0.2f;
	const float timeFadeOutParticle = 1.0f;
	const size_t countParticleInEmitter = 64U;
	const size_t countEmitterInPool = 2048U;
	const size_t totalCountParticle = variablesForTest::countParticleInEmitter * variablesForTest::countEmitterInPool;


	const unsigned char maxColor = 255;
	const unsigned char minColor = 0;
	const float maxColorF = 255.f;
	const test::color WHITE(maxColor, maxColor, maxColor, maxColor);

	const test::vector2 DOWN = test::vector2{ 0.0f, -1.0f };
}

