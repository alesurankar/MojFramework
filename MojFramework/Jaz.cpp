#include "Jaz.h"

void Jaz::BorderCheck()
{
	if (x <= 0)
	{
		x = 0;
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (x >= Graphics::ScreenWidth - width)
	{
		x = Graphics::ScreenWidth - width;
	}
	if (y >= Graphics::ScreenHeight - height)
	{
		y = Graphics::ScreenHeight - height;
	}
}

void Jaz::Draw(Graphics& gfx) const
{
	for (int i = x; i < x + width; i++)
	{
		for (int j = y; j < y + height; j++)
		{
			gfx.PutPixel(i, j, Colors::Green);
		}
	}
}

void Jaz::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		speed = 6;
	}
	else
	{
		speed = 2;
	}
	if (kbd.KeyIsPressed('W'))
	{
		y -= speed;;
	}
	if (kbd.KeyIsPressed('S'))
	{
		y += speed;
	}
	if (kbd.KeyIsPressed('A'))
	{
		x -= speed;
	}
	if (kbd.KeyIsPressed('D'))
	{
		x += speed;
	}
}
