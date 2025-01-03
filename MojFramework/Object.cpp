#include "Object.h"

void Object::InitRed(float x_in, float y_in, float vx_in, float vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}

void Object::InitBlue(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

void Object::BorderCheck()
{
	if (x <= float(GeneralGame::offset))
	{
		x = float(GeneralGame::offset);
		vx = -vx;
	}
	if (y <= float(GeneralGame::yOffset))
	{
		y = float(GeneralGame::yOffset);
		vy = -vy;
	}
	if (x >= float(Graphics::ScreenWidth - GeneralGame::offset) - width)
	{
		x = float(Graphics::ScreenWidth - GeneralGame::offset) - width;
		vx = -vx;
	}
	if (y >= float(Graphics::ScreenHeight - GeneralGame::offset) - height)
	{
		y = float(Graphics::ScreenHeight - GeneralGame::offset) - height;
		vy = -vy;
	}
}


void Object::DrawRed(Graphics& gfx) const
{
	gfx.DrawRect(int(x), int(y), int(width), int(height), Colors::Red);
}

void Object::DrawBlue(Graphics& gfx) const
{
	gfx.DrawRect(int(x), int(y), int(width), int(height), Colors::Blue);
}

void Object::Update()
{
	x += vx;
	y += vy;

	BorderCheck();
}

bool Object::Colliding(Jaz& jaz)
{
	const float right0 = jaz.GetX() + jaz.GetWidth();
	const float bottom0 = jaz.GetY() + jaz.GetHeight();
	const float right1 = x + width;
	const float bottom1 = y + height;

	return
		right0 >= x &&
		bottom0 >= y &&
		right1 >= jaz.GetX() &&
		bottom1 >= jaz.GetY();
}