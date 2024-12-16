#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd), 
	rng(rd()),
	xRand(20, gfx.ScreenWidth - 30),
	yRand(20, gfx.ScreenHeight - 30),
	vRand(-1, 1),
	jaz(xRand(rng),yRand(rng))
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
	if (gg.GameOverStatus())
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gg.StartGame();
			for (int i = 0; i < n; i++)
			{

				obj[i].Reset();
				obj[i].Init(xRand(rng),yRand(rng),vRand(rng),vRand(rng));
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
				obj[i].Collected();
			}
		}

		bool allCollected = true;
		for (int i = 0; i < n; i++)
		{
			allCollected = allCollected && obj[i].CheckCollected();
		}
		if (allCollected)
		{
			gg.GameOver();
		}
	}
}

void App::ComposeFrame()
{
	if (gg.GameOverStatus())
	{
		gg.GameOverBanner(gfx);
	}
	else
	{
		jaz.Draw(gfx);
		for (int i = 0; i < n; i++)
		{
			if (!obj[i].CheckCollected())
			{
				obj[i].Draw(gfx);
			}
		}
	}
}