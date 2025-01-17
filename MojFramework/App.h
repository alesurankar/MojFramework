#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Object.h"
#include "Jaz.h"
#include "GeneralGame.h"
#include "Bullet.h"
#include <random>
#include "FrameTimer.h"

class App
{
public:
	App(class MainWindow& wnd);
	App(const App&) = delete;
	App& operator=(const App&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  Moije Funkcije              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  Moji Parametri              */
	FrameTimer ft;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xRand;
	std::uniform_real_distribution<float> yRand;
	std::uniform_real_distribution<float> vRand;
	Jaz jaz;
	static constexpr int n = GeneralGame::enemyNum;
	Object objRed[n];
	Object objBlue;
	GeneralGame gg;
	Bullet bul;
	/********************************/
};