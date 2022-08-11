#include "Render.h"
#include "PoolEmitters.h"
#include "VariablesForTest.h"
#include "test.h"
#include "Physics.h"

using namespace test;

static Render* instance = nullptr;

Render::Render() {
	frame1.reserve(variablesForTest::totalCountParticle);
	frame2.reserve(variablesForTest::totalCountParticle);
}

void Render::draw() {
	if (isDirty()) {
		changeFrame();
	}
	auto& cashedFrame = getCashedFrame();
	for (auto& partile : cashedFrame) {
#ifdef MULTICOLOR_PARTICLE_MODE
		platform::drawPoint(
			partile.pos.x,
			partile.pos.y,
			functionHelper::getColorFloatFromChar(partile.color.r),
			functionHelper::getColorFloatFromChar(partile.color.g),
			functionHelper::getColorFloatFromChar(partile.color.b),
			functionHelper::getColorFloatFromChar(partile.color.a));
	}
#else
		platform::drawPoint(
			partile.pos.x,
			partile.pos.y,
			1.f,
			1.f,
			1.f,
			functionHelper::getColorFloatFromChar(partile.a));
	}
#endif
}

std::vector<ParticleCash>& Render::getCashedFrame() {
	return useNextFrame.load() ? frame1 : frame2;
}

std::vector<ParticleCash>& Render::getFrameForCash() {
	return useNextFrame.load() ? frame2 : frame1;
}

Render* Render::getInstance() {
	if (!instance) {
		instance = new Render();
	}
	return instance;
}

void Render::cleanup() {
	delete instance;
	instance = nullptr;
}

bool Render::isInRenderSpace(const vector2& pos) {
	return pos.x < test::SCREEN_WIDTH && pos.x >= 0.f && pos.y < test::SCREEN_HEIGHT && pos.y >= 0.f;
}

void Render::changeFrame() {
	useNextFrame.store(!useNextFrame.load());
	dirty.store(false);
}

void Render::markDirty() {
	dirty.store(true);
}

bool Render::isDirty() {
	return dirty.load();
}