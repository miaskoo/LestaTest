#include "functionHelper.h"
#include "structHelper.h"
#include "variablesForTest.h"
#include <unordered_map>
#include <random>

namespace functionHelper {
	const int maxColorI = 256;
	float colors[maxColorI];
}

bool functionHelper::isÑhance(float percentWin) {
	if (percentWin >= 1.0f) {
		return true;
	}
	return getRndf() < percentWin;
}

float functionHelper::getPercentFromNumbers(float partOfAllNumber, float fullNumber) {
	if (fullNumber <= 0.f) {
		return 0.0f;
	}
	return  partOfAllNumber / fullNumber;
}

float functionHelper::getRndf() {
	return getRndf(rand());
}

float functionHelper::getRndf(int randNumb) {
	return static_cast <float>(randNumb) / static_cast <float> (RAND_MAX);
}

test::vector2 functionHelper::getRndDirection() {
	test::vector2 randDir;
	auto randX = rand();
	auto randY = rand();
	randDir.x = functionHelper::getRndf(randX);
	randDir.y = functionHelper::getRndf(randY);
	if ((randX & 1) == 1) {
		randDir.x *= -1;
	}
	if ((randY & 1) == 1) {
		randDir.y *= -1;
	}
	return randDir;
}

test::color functionHelper::getRndColor() {
	return test::color{ 
		static_cast<uint8_t> (rand() % functionHelper::maxColorI),
		static_cast<uint8_t> (rand() % functionHelper::maxColorI),
		static_cast<uint8_t> (rand() % functionHelper::maxColorI),
		variablesForTest::maxColor };
}

int functionHelper::getRndBetween(int aModule, int aMin) {
	if (aModule == 0) {
		return aMin;
	}
	return rand() % aModule + aMin;
}

const float& functionHelper::getColorFloatFromChar(const uint8_t &aColor) {
	return functionHelper::colors[aColor];
}

void functionHelper::initColorsFloat() {
	uint8_t n = 0;
	do {
		functionHelper::colors[n] = static_cast<float>(n) / 255.f;
	} 
	while (n++ < variablesForTest::maxColor);
}

void functionHelper::rotateVector(test::vector2& vec, float angle) {
	auto x = vec.x;
	auto y = vec.y;
	vec.x = x * cosf(angle) - y * sinf(angle);
	vec.y = y * cosf(angle) + x * sinf(angle);
}