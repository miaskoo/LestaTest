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
		const bool& isFadeOut() const;
		const vector2& getPosition() const;
		const float& getSpeed() const;
		const vector2& getDirection() const;
		const bool& isLockDown() const;
		const float& getAlpha() const;
#ifdef MULTICOLOR_PARTICLE_MODE
		const color& getColor() const;
#endif
	private:
		vector2 position;
		float speed = 0.0f;
		float fadeOutTime = 0.0f;
		vector2 direction;
		bool visible = false;
		float fullLifeTime = 0.0f;
		float lifeTime = 0.0f;
#ifdef MULTICOLOR_PARTICLE_MODE
		color colorParticle = variablesForTest::WHITE;
#else
		float alpha = 0.0f;
#endif
		bool lockDown = false;	
		bool fadeOut = false;
	};
}

