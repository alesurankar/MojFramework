#include "Bullet.h"

void Bullet::Init(const Vec2& pos_in, const Vec2& vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

void Bullet::Draw(Graphics& gfx) const
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(dim), int(dim), Colors::White);
}

void Bullet::Update()
{
	pos += vel;
}
