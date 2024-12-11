#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

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
	void BorderCheck();
	int BorderCheckObjX(int x_in, int width_in);
	int BorderCheckObjY(int y_in, int height_in);
	void DrawMe(int x_in, int y_in, Color c);
	void DrawObj(int x_in, int y_in, Color c);
	bool Colliding(int x0_in, int y0_in, int width0_in, int height0_in, int x1_in, int y1_in, int width1_in, int height1_in);
	void GameOverBanner();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  Moji Parametri              */
	int x = 100;
	int y = 100;
	int x1 = 200;
	int y1 = 200;
	int vx1;
	int vy1;
	bool collected1 = false;
	int x2 = 300;
	int y2 = 300;
	int vx2;
	int vy2;
	bool collected2 = false;
	int x3 = 400;
	int y3 = 400;
	int vx3;
	int vy3;
	bool collected3 = false;
	int width = 12;
	int height = 12;
	int speed;
	bool gameOver = true;
	/********************************/
};