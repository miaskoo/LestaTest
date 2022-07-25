#pragma once
#include <structHelper.h>
#include <atomic>
#include <vector>

namespace test {
	class Particle;
	class Render {
	public:
		Render();
		~Render() = default;
		static bool isInRenderSpace(const vector2& pos);
		static Render* getInstance();
		void draw();
		void changeFrame();
		void markDirty();
		bool isDirty();
		std::vector<ParticleCash>& getFrameForCash();
	private:
		std::vector<ParticleCash>& getCashedFrame();
		std::vector<ParticleCash> frame1;
		std::vector<ParticleCash> frame2;
		std::atomic_bool useNextFrame = false;
		std::atomic_bool dirty = false;
	};
}