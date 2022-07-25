#include "GlobalTime.h"

using namespace test;

static GlobalTime instance;

int GlobalTime::getTime() {
	return time.load(std::memory_order_relaxed);
}

void GlobalTime::updateTime(int dt) {
	time.fetch_add(dt, std::memory_order_relaxed);
}

GlobalTime* GlobalTime::getInstance() {
	return &instance;
}
