#pragma once
#include <atomic>
namespace test {
	class GlobalTime {
	public:
		GlobalTime() = default;
		~GlobalTime() = default;
		void updateTime(int dt);
		int getTime();
		static GlobalTime* getInstance();
	private:
		std::atomic_uint time = 0;
	};
}

