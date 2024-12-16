#pragma once

#include "Graphics.h"
#include "Jaz.h"

class Object
{
public:
	int BorderCheckX(int x_in, int width_in);
	int BorderCheckY(int y_in, int height_in);
	void Draw(Graphics& gfx) const;
	void Update();
	bool Colliding(Jaz& jaz);
public:
	int x = 400;
	int y = 400;
	int vx;
	int vy;
	bool collected = false;
	static constexpr int width = 12;
	static constexpr int height = 12;
};