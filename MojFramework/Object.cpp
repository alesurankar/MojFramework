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

float Object::BorderCheckX(float x_in, float width_in)
{
	if ((x_in <= GeneralGame::difficulty) || (x_in >= float(Graphics::ScreenWidth - GeneralGame::difficulty) - width_in))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

float Object::BorderCheckY(float y_in, float height_in)
{
	if ((y_in <= GeneralGame::yOffset - GeneralGame::difficulty) || (y_in >= float(Graphics::ScreenHeight - GeneralGame::difficulty) - height_in))
	{
		return -1;
	}
	else
	{
		return 1;
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
	vx *= BorderCheckX(x, width);
	vy *= BorderCheckY(y, height);

	x += vx;
	y += vy;
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