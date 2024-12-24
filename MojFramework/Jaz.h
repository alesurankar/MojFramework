#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "GeneralGame.h"

class Jaz
{
public:
	Jaz(float x_in, float y_in);
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
private:
	float x;
	float y;
	float speed;
	static constexpr float width = 12.0f;
	static constexpr float height = 12.0f;
};