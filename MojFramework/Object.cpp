#include "Object.h"

void Object::InitRed(const Vec2& pos_in, const Vec2& vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

void Object::InitBlue(const Vec2& pos_in)
{
	pos = pos_in;
}

void Object::BorderCheck()
{
	if (pos.x <= float(GeneralGame::offset))
	{
		pos.x = float(GeneralGame::offset);
		vel.x = -vel.x;
	}
	if (pos.y <= float(GeneralGame::yOffset))
	{
		pos.y = float(GeneralGame::yOffset);
		vel.y = -vel.y;
	}
	if (pos.x >= float(Graphics::ScreenWidth - GeneralGame::offset) - width)
	{
		pos.x = float(Graphics::ScreenWidth - GeneralGame::offset) - width;
		vel.x = -vel.x;
	}
	if (pos.y >= float(Graphics::ScreenHeight - GeneralGame::offset) - height)
	{
		pos.y = float(Graphics::ScreenHeight - GeneralGame::offset) - height;
		vel.y = -vel.y;
	}
}


void Object::DrawRed(Graphics& gfx) const
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(width), int(height), Colors::Red);
}

void Object::DrawBlue(Graphics& gfx) const
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(width), int(height), Colors::Blue);
}

void Object::Update()
{
	pos.x += vel.x;
	pos.y += vel.y;

	BorderCheck();
}

bool Object::Colliding(Jaz& jaz)
{
	const float right0 = jaz.GetPos().x + jaz.GetWidth();
	const float bottom0 = jaz.GetPos().y + jaz.GetHeight();
	const float right1 = pos.x + width;
	const float bottom1 = pos.y + height;

	return
		right0 >= pos.x &&
		bottom0 >= pos.y &&
		right1 >= jaz.GetPos().x &&
		bottom1 >= jaz.GetPos().y;
}