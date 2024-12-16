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
	if (gg.gameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> xRandom(0, gfx.ScreenWidth - 20);
			std::uniform_int_distribution<int> yRandom(0, gfx.ScreenHeight - 20);
			std::uniform_int_distribution<int> vRandom(-1,1);
			gg.gameOver = false;
			jaz.x = xRandom(rng);
			jaz.y = yRandom(rng);
			for (int i = 0; i < n; i++)
			{

				obj[i].collected = false;
				obj[i].x = xRandom(rng);
				obj[i].y = yRandom(rng);
				obj[i].vx = vRandom(rng);
				obj[i].vy = vRandom(rng);
			}
		}
	}
	else
	{
		jaz.Update(wnd.kbd);

		jaz.BorderCheck();

		
		for (int i = 0; i < n; i++)
		{
			obj[i].Update(); 
			if (obj[i].Colliding(jaz))
			{
				obj[i].collected = true;
			}
		}

		bool allCollected = true;
		for (int i = 0; i < n; i++)
		{
			allCollected = allCollected && obj[i].collected;
		}
		if (allCollected)
		{
			gg.gameOver = true;
		}
	}
}

void App::ComposeFrame()
{
	if (gg.gameOver)
	{
		gg.GameOverBanner(gfx);
	}
	else
	{
		jaz.Draw(gfx);
		for (int i = 0; i < n; i++)
		{
			if (!obj[i].collected)
			{
				obj[i].Draw(gfx);
			}
		}
	}
}