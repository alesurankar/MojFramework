#include "Object.h"

void Object::Init(int x_in, int y_in, int vx_in, int vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}

int Object::BorderCheckX(int x_in, int width_in)
{
	if ((x_in <= 0) || (x_in >= Graphics::ScreenWidth - width_in))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int Object::BorderCheckY(int y_in, int height_in)
{
	if ((y_in <= 0) || (y_in >= Graphics::ScreenHeight - height_in))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void Object::Draw(Graphics& gfx) const
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::Red);
		}
	}
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
	const int right0 = jaz.GetX() + jaz.GetWidth();
	const int bottom0 = jaz.GetY() + jaz.GetHeight();
	const int right1 = x + width;
	const int bottom1 = y + height;

	return
		right0 >= x &&
		bottom0 >= y &&
		right1 >= jaz.GetX() &&
		bottom1 >= jaz.GetY();
}

void Object::Collected()
{
	collected = true;
}

void Object::Reset()
{
	collected = false;
}

bool Object::CheckCollected()
{
	return collected;
}
