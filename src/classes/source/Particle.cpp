#include "Particle.h"
#include "functionHelper.h"

using namespace test;

void Particle::update(float dt) {
	if (isFadeOut()) {
		fadeOutTime -= dt;
		if (fadeOutTime > 0.0f) {
			setAlpha(static_cast<uint8_t>(static_cast<float>(variablesForTest::maxColorF) * functionHelper::getPercentFromNumbers(fadeOutTime, variablesForTest::timeFadeOutParticle)));
			return;
		}
		colorParticle.a = variablesForTest::minColor;
	}
	if (isDead()) {
		return;
	}
	lifeTime -= dt;
}

void Particle::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

void Particle::setDirection(const vector2& aDirection) {
	direction.x = aDirection.x;
	direction.y = aDirection.y;
}

void Particle::setSpeed(float aSpeed) {
	speed = aSpeed;
}

void Particle::setVisible(bool aVisible) {
	visible = aVisible;
}

void Particle::setLifeTime(float aLifeTime) {
	fullLifeTime = aLifeTime;
	lifeTime = aLifeTime;
}

void Particle::setLockDown(bool aLockDown) {
	lockDown = true;
}

void Particle::setAlpha(uint8_t a) {
	colorParticle.a = a;
}

void Particle::setColor(const color& aColorParticle) {
	colorParticle = aColorParticle;
}

void Particle::setFadeOut(bool aFadeOut) {
	fadeOut = aFadeOut;
}

void Particle::setFadeOutTime(float aFadeOutTime) {
	fadeOutTime = aFadeOutTime;
}

const vector2& Particle::getPosition() const {
	return position;
}

const vector2& Particle::getDirection() const {
	return direction;
}


const float& Particle::getSpeed() const {
	return speed;
}

const bool& Particle::isVisible() const {
	return visible;
}


bool Particle::isDead() const {
	return lifeTime < 0.0f;
}

const bool& Particle::isFadeOut() const {
	return fadeOut;
}

const bool& Particle::isLockDown() const {
	return lockDown;
}

const float& Particle::getAlpha() const {
	return colorParticle.a;
}

const color& Particle::getColor() const {
	return colorParticle;
}
