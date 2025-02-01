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
	jaz(Vec2(xRand(rng), yRand(rng))),
	fireSound(L"Sounds\\1_fireSound.wav"),
	objCollected(L"Sounds\\2_objcollected.wav"),
	objDamaged(L"Sounds\\3_objDamaged.wav"),
	jazDamaged(L"Sounds\\4_jazDamaged.wav"),
	startGame(L"Sounds\\5_startGame.wav"),
	gameMusic(L"Sounds\\6_gameMusic.wav")
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
	float dt = ft.CheckPoint();
	if (gg.GameOverStatus())
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			//Jaz
			jaz.Respawn();

			//Bullet
			bul.clear();

			//Enemy
			enemy.clear();

			//Collectable
			coll.clear();

			//GeneralGame
			gg.StartGame();
			frameCount = 1.3f;
			startGame.Play();
			count = 0.0f;
		}
	}
	else
	{
		//Jaz
		jaz.Update(wnd.mouse, wnd.kbd, dt);
		if (jaz.FiringStatus())
		{
			if (!jaz.ReloadingStatus())
			{
				bul.emplace_back(jaz.GetCenter(), jaz.GetDirection(wnd.mouse));
				fireSound.Play();
			}
		}
		if (jaz.DestroyedStatus())
		{
			gg.GameOver();
		}

		//Bullet
		for (int j = 0; j < bul.size();)
		{
			if (bul[j].FlyingStatus())
			{
				bul[j].Update(dt);
				j++;
			}
			else
			{
				bul.erase(bul.begin() + j);
			}
		}

		//Enemy
		count += dt;
		if (count > GeneralGame::enemyRespawnTime && enemy.size() < n)
		{
			enemy.emplace_back(Vec2(xRand(rng), yRand(rng)), Vec2(vRand(rng), vRand(rng)));
			count = 0.0f;
		}
		for (int i = 0; i < enemy.size();)
		{
			enemy[i].Update(dt);
			if (enemy[i].Colliding(jaz))
			{
				jaz.Damaged();
				jazDamaged.Play();
			}
			for (int j = 0; j < bul.size(); j++)
			{
				if (enemy[i].Colliding(bul[j]))
				{
					enemy[i].Damaged();
					bul[j].Smashed();
					objDamaged.Play();
				}

			}
			if (enemy[i].DestroyedStatus())
			{
				coll.emplace_back(enemy[i].GetPos());
				enemy.erase(enemy.begin() + i);
			}
			else
			{
				i++;
			}
		}

		//Collectable
		for (int c = 0; c < coll.size();)
		{
			if (coll[c].Colliding(jaz))
			{
				gg.AddScore();
				coll.erase(coll.begin() + c);
				if (gg.ScoreStatus() >= GeneralGame::maxScore)
				{
					gg.GameOver();
					gg.GameWon();
				}
				objCollected.Play();
			}
			else
			{
				c++;
			}
		}

		//GeneralGame
		if (gg.GameOverStatus())
		{
			gameMusic.StopAll();
		}
		frameCount += dt;
		if (frameCount > 3.4f)
		{
			gameMusic.Play();
			frameCount = 0.0f;
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
		for (int j = 0; j < bul.size(); j++)
		{
			if (bul[j].FlyingStatus())
			{
				bul[j].Draw(gfx);
			}
		}

		//Enemy
		for (int i = 0; i < enemy.size(); i++)
		{
			if (!enemy[i].DestroyedStatus())
			{
				enemy[i].Draw(gfx);
			}
		}

		//Collectable
		for (int c = 0; c < coll.size(); c++)
		{
			coll[c].Draw(gfx);
		}

		//GeneralGame
		gg.DrawScore(gfx);
		gg.DrawGameBorder(gfx);
	}
}