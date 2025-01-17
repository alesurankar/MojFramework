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
			//Jaz
			jaz.Respawn();

			//Bullet

			//Object
			for (int i = 0; i < n; i++)
			{
				objRed[i].Respawn();
				objRed[i].InitRed(Vec2(xRand(rng),yRand(rng)),Vec2(vRand(rng),vRand(rng)));
			}
			objBlue.InitBlue(Vec2(xRand(rng), yRand(rng)));

			//GeneralGame
			gg.StartGame();
		}
	}
	else
	{
		//Jaz
		jaz.Update(wnd.mouse, wnd.kbd);
		if (jaz.FiringStatus())
		{
			if (!bul.FlyingStatus())
			{
				bul.Init(jaz.GetCenter(), jaz.GetDirection(wnd.mouse));
				bul.Flying();
			}
		}
		if (jaz.DestroyedStatus())
		{
			gg.GameOver();
		}

		//Bullet
		if (bul.FlyingStatus())
		{
			bul.Update();
		}

		//Object
		for (int i = 0; i < n; i++)
		{
			objRed[i].Update(); 
			if (objRed[i].Colliding(jaz))
			{
				jaz.Damaged();
			}
			if (objRed[i].Colliding(bul))
			{
				objRed[i].Damaged();
				bul.Smashed();
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
		if (bul.FlyingStatus())
		{
			bul.Draw(gfx);
		}

		//Object
		for (int i = 0; i < n; i++)
		{
			if (!objRed[i].DestroyedStatus())
			{
				objRed[i].DrawRed(gfx);
			}
		}
		objBlue.DrawBlue(gfx);
		
		//GeneralGame
		gg.DrawScore(gfx);
		gg.DrawGameBorder(gfx);
	}
}