#include "MainWindow.h"
#include "App.h"
#include <random>

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void App::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void App::UpdateModel()
{
	if (gameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> xRandom(0, gfx.ScreenWidth - width);
			std::uniform_int_distribution<int> yRandom(0, gfx.ScreenHeight - height);
			std::uniform_int_distribution<int> vRandom(-1,1);
			gameOver = false;
			collected1 = false;
			x = xRandom(rng);
			y = yRandom(rng); 
			x1 = xRandom(rng);
			y1 = yRandom(rng);
			vx1 = vRandom(rng);
			vy1 = vRandom(rng);
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			speed = 6;
		}
		else
		{
			speed = 2;
		}
		if (wnd.kbd.KeyIsPressed('W'))
		{
			y -= speed;;
		}
		if (wnd.kbd.KeyIsPressed('S'))
		{
			y += speed;
		}
		if (wnd.kbd.KeyIsPressed('A'))
		{
			x -= speed;
		}
		if (wnd.kbd.KeyIsPressed('D'))
		{
			x += speed;
		}

		BorderCheck();

		vx1 *= BorderCheckObjX(x1, width);
		vy1 *= BorderCheckObjY(y1, height);

		x1 += vx1;
		y1 += vy1;

		if (Colliding(x, y, width, height, x1, y1, width, height))
		{
			collected1 = true;
		}
		if (collected1)
		{
			gameOver = true;
		}
	}
}

void App::BorderCheck()
{
	if (x <= 0)
	{
		x = 0;
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (x >= gfx.ScreenWidth - width)
	{
		x = gfx.ScreenWidth - width;
	}
	if (y >= gfx.ScreenHeight - height)
	{
		y = gfx.ScreenHeight - height;
	}
}

int App::BorderCheckObjX(int x_in, int width_in)
{
	if ((x_in <= 0) || (x_in >= gfx.ScreenWidth - width_in))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int App::BorderCheckObjY(int y_in, int height_in)
{
	if ((y_in <= 0)||(y_in >= gfx.ScreenHeight - height_in))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void App::DrawMe(int x_in, int y_in, Color c)
{
	for (int i = x_in; i < x_in + width; i++)
	{
		for (int j = y_in; j < y_in + height; j++)
		{
			gfx.PutPixel(i, j, c);
		}
	}
}

void App::DrawObj(int x_in, int y_in, Color c)
{
	for (int i = x_in; i < x_in + width; i++)
	{
		for (int j = y_in; j < y_in + height; j++)
		{
			gfx.PutPixel(i, j, c);
		}
	}
}

bool App::Colliding(int x0_in, int y0_in, int width0_in, int height0_in, int x1_in, int y1_in, int width1_in, int height1_in)
{
	const int right0 = x0_in + width0_in;
	const int bottom0 = y0_in + height0_in;
	const int right1 = x1_in + width1_in;
	const int bottom1 = y1_in + height1_in;

	return
		right0 >= x1_in &&
		bottom0 >= y1_in &&
		right1 >= x0_in &&
		bottom1 >= y0_in;
}

void App::GameOverBanner()
{
	for (int i = 0; i < gfx.ScreenWidth; i++)
	{
		for (int j = 0; j < gfx.ScreenHeight; j++)
		{
			gfx.PutPixel(i, j, Colors::Green);
		}
	}
}

void App::ComposeFrame()
{
	if (gameOver)
	{
		GameOverBanner();
	}
	else
	{
		DrawMe(x, y, Colors::Green);
		if (!collected1)
		{
			DrawObj(x1, y1, Colors::Red);
		}
	}
}