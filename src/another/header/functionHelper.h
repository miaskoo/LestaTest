#pragma once
#include <stdint.h>

namespace test {
	struct color;
	struct vector2;
}

namespace functionHelper {
	bool is—hance(float percentWin);
	float getPercentFromNumbers(float partOfAllNumber, float fullNumber);
	float getRndf(int randNumb);
	float getRndf();
	int getRndBetween(int aModule, int aMin);
	test::vector2 getRndDirection();
	void initColorsFloat();
	const float& getColorFloatFromChar(const uint8_t& aColor);
	test::color getRndColor();
	void rotateVector(test::vector2& vec, float angle);
}