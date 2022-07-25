#pragma once
namespace test
{
	void render();
	void update(int dt);
	void on_click(int x, int y);
	void init();
	void term();

	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;
};

namespace platform
{
	void drawPoint(float x, float y, float r, float g, float b, float a);
};