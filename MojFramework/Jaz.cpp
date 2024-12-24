#include "Jaz.h"

Jaz::Jaz(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

void Jaz::BorderCheck()
{
	if (x <= GeneralGame::offset)
	{
		x = GeneralGame::offset;
	}
	if (y <= GeneralGame::yOffset)
	{
		y = GeneralGame::yOffset;
	}
	if (x >= float(Graphics::ScreenWidth - GeneralGame::offset) - width)
	{
		x = float(Graphics::ScreenWidth - GeneralGame::offset) - width;
	}
	if (y >= float(Graphics::ScreenHeight - GeneralGame::offset) - height)
	{
		y = float(Graphics::ScreenHeight - GeneralGame::offset) - height;
	}
}

void Jaz::Draw(Graphics& gfx) const
{
	gfx.DrawRect(int(x), int(y), int(width), int(height), Colors::Green);
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

float Jaz::GetX()
{
	return x;
}

float Jaz::GetY()
{
	return y;
}

float Jaz::GetWidth()
{
	return width;
}

float Jaz::GetHeight()
{
	return height;
}
