#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "GeneralGame.h"

class Bullet
{
public:
	Bullet(const Vec2& center_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	void BorderCheck();
	void Smashed();
	bool FlyingStatus();
	Vec2 GetPos();
	float GetDim();
private:
	bool flying;
	Vec2 center;
	Vec2 pos;
	Vec2 vel;
	static constexpr float dim = GeneralGame::bulDim;
	static constexpr float speed = GeneralGame::bulSpeed;
};