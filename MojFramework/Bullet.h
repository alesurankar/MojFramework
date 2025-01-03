#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Bullet
{
public:
	void Init(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update();
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float dim = 3.0f;
};