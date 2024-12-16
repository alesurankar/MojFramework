#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Jaz
{
public:
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
public:
	int x = 100;
	int y = 100;
	int speed;
	static constexpr int width = 12;
	static constexpr int height = 12;
};