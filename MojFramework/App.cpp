#include "MainWindow.h"
#include "App.h"

App::App(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd), 
	rng(rd()),
	xRand(20.0f, 770.0f),
	yRand(20.0f, 570.0f),
	vRand(-GeneralGame::difficulty, GeneralGame::difficulty),
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
				objRed[i].InitRed(xRand(rng),yRand(rng),vRand(rng),vRand(rng));
			}
			objBlue.InitBlue(xRand(rng), yRand(rng));
		}
	}
	else
	{
		jaz.Update(wnd.kbd);

		jaz.BorderCheck();
		
		for (int i = 0; i < n; i++)
		{
			objRed[i].Update(); 
			if (objRed[i].Colliding(jaz))
			{
				gg.GameOver();
			}
		}
		if (objBlue.Colliding(jaz))
		{
			gg.AddScore();
			objBlue.InitBlue(xRand(rng), yRand(rng));
			if (gg.ScoreStatus() >= GeneralGame::maxScore)
			{
				gg.GameOver();
				gg.GameWon();
			}
		}
	}
}

void App::ComposeFrame()
{
	if (gg.GameOverStatus())
	{
		if (gg.GameWonStatus())
		{
			gg.GameWonBanner(gfx);
		}
		else
		{
			gg.GameLostBanner(gfx);
		}
	}
	else
	{
		jaz.Draw(gfx);
		for (int i = 0; i < n; i++)
		{
			objRed[i].DrawRed(gfx);
		}
		objBlue.DrawBlue(gfx);
		gg.DrawScore(gfx);
		gg.DrawGameBorder(gfx);
	}
}