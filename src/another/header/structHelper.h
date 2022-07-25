#pragma once
#include <atomic>
#include <array>
#include "functionHelper.h"

namespace test {
	struct vector2 {
		float x = 0.0f;
		float y = 0.0f;
	};

	struct color {
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 0;
		color(uint8_t aR, uint8_t aG, uint8_t aB, uint8_t aA) : r(aR), g(aG), b(aB), a(aA) {}
	};
	
	struct ParticleCash {
		vector2 pos;
		color color;
		ParticleCash(const test::vector2& aPos, const test::color& aColor) : pos(aPos), color(aColor) {}
	};
}