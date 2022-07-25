#pragma once
#include "structHelper.h"
#include "variablesForTest.h"

namespace test {
	class Particle {
	public:
		Particle() = default;
		~Particle() = default;

		void update(float dt);

		void setPosition(float x, float y);
		void setSpeed(float aSpeed);
		void setDirection(const vector2& aDirection);
		void setVisible(bool aVisible);
		void setLifeTime(float aLifeTime);
		void setLockDown(bool aLockDown);
		void setAlpha(uint8_t a);
		void setColor(const color& aColorParticle);
		void setFadeOut(bool aFadeOut);
		void setFadeOutTime(float aFadeOutTime);

		const bool& isVisible() const;
		bool isDead() const;
		bool isFadeOut() const;
		const vector2& getPosition() const;
		float getSpeed() const;
		const vector2& getDirection() const;
		bool isLockDown() const;
		float getAlpha() const;
		const color& getColor() const;
	private:
		vector2 position;
		float speed = 0.0f;
		float fadeOutTime = 0.0f;
		vector2 direction;
		bool visible = false;
		float fullLifeTime = 0.0f;
		float lifeTime = 0.0f;
		color colorParticle = variablesForTest::WHITE;
		bool lockDown = false;	
		bool fadeOut = false;
	};
}

