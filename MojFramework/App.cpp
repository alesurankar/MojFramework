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
	jaz(Vec2(xRand(rng),yRand(rng)))
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
				objRed[i].InitRed(Vec2(xRand(rng),yRand(rng)),Vec2(vRand(rng),vRand(rng)));
			}
			objBlue.InitBlue(Vec2(xRand(rng), yRand(rng)));
			bul.Init(Vec2(30.0f, 30.0f), Vec2(1.0f, 1.0f));
		}
	}
	else
	{
		//Jaz
		jaz.Update(wnd.kbd);
		jaz.Update(wnd.mouse);
		jaz.BorderCheck();
		
		//Bullet
		bul.Update();

		//Object
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
			objBlue.InitBlue(Vec2(xRand(rng), yRand(rng)));
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
		//Jaz
		jaz.Draw(gfx);

		//Bullet
		bul.Draw(gfx);

		//Object
		for (int i = 0; i < n; i++)
		{
			objRed[i].DrawRed(gfx);
		}
		objBlue.DrawBlue(gfx);
		
		//GeneralGame
		gg.DrawScore(gfx);
		gg.DrawGameBorder(gfx);
	}
}