#pragma once
#include <structHelper.h>
#include <atomic>
#include <vector>

namespace test {
	class Particle;
	class Render {
	public:
		static bool isInRenderSpace(const vector2& pos);
		void draw();
		void changeFrame();
		void markDirty();
		bool isDirty();
		std::vector<ParticleCash>& getFrameForCash();
		static Render* getInstance();
		void cleanup();
	private:
		Render();
		~Render() = default;
		std::vector<ParticleCash>& getCashedFrame();
		std::vector<ParticleCash> frame1;
		std::vector<ParticleCash> frame2;
		std::atomic_bool useNextFrame = false;
		std::atomic_bool dirty = false;
	};
}