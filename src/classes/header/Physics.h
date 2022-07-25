#pragma once
#include "Emitter.h"
#include "variablesForTest.h"
#include <thread>

namespace test {
	class Physics {
	public:
		Physics();
		~Physics() = default;
		void start();
		void stop();
		static Physics* getInstance();
	private:
		void threadUpdate();
		void update(int dt);
		void moveParticle(Particle& particle, float dtInSeconds, float gravity);

		//in ms
		int lastUpdateTime = 0;
		std::atomic_bool isStop = false;
		std::thread thread;
	};
}

