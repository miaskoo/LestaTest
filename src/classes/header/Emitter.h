#pragma once
#include <Particle.h>

namespace test {
	class Emitter {
	public:
		Emitter() = default;
		~Emitter() = default;
		bool isFree() const;
		std::array<Particle, variablesForTest::countParticleInEmitter>& getPoolParticles();
		void initEmitter(float x, float y);
		void setFree(bool aFree);
	private:
		std::array<Particle, variablesForTest::countParticleInEmitter> poolParticles;
		std::atomic_bool free = true;
	};
}
