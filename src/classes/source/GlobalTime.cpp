#include "GlobalTime.h"

using namespace test;

static GlobalTime instance;

int GlobalTime::getTime() {
	return time.load();
}

void GlobalTime::updateTime(int dt) {
	time.fetch_add(dt);
}

GlobalTime* GlobalTime::getInstance() {
	return &instance;
}
