#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Jaz
{
public:
	Jaz(int x_in, int y_in);
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
private:
	int x = 100;
	int y = 100;
	int speed;
	static constexpr int width = 12;
	static constexpr int height = 12;
};