#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Object.h"
#include "Jaz.h"
#include "GeneralGame.h"
#include <random>

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
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xRand;
	std::uniform_int_distribution<int> yRand;
	std::uniform_int_distribution<int> vRand;
	Jaz jaz;
	static constexpr int n = 1000;
	Object obj[n];
	GeneralGame gg;
	/********************************/
};