#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "GeneralGame.h"
#include "Vec2.h"

class Jaz
{
public:
	Jaz(const Vec2& pos_in);
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	Vec2 GetPos();
	float GetWidth();
	float GetHeight();
private:
	Vec2 pos;
	float speed;
	static constexpr float width = 12.0f;
	static constexpr float height = 12.0f;
};