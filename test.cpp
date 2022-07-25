#include "test.h"
#include "PoolEmitters.h"
#include "Physics.h"
#include "Render.h"
#include "GlobalTime.h"
#include "variablesForTest.h"

using namespace test;

void test::init() {
	srand(static_cast<unsigned int>(time(0)));
	functionHelper::initColorsFloat();
	Physics::getInstance()->start();
}

void test::on_click(int x, int y) {
	PoolEmitters::getInstance()->spawnFreeEmitterOnPos(PoolEmitters::getInstance()->getFreeEmitter(), x, test::SCREEN_HEIGHT - y); //Because the top of the screen doesn't start at 0
}
	
void test::term() {
	Physics::getInstance()->stop();
}

void test::render() {
	Render::getInstance()->draw();
}

void test::update(int dt) {
	GlobalTime::getInstance()->updateTime(dt);
}