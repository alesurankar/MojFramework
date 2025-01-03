#include "Jaz.h"

Jaz::Jaz(const Vec2& pos_in)
{
	pos = pos_in;
}

void Jaz::BorderCheck()
{
	if (pos.x <= float(GeneralGame::offset))
	{
		pos.x = float(GeneralGame::offset);
	}
	if (pos.y <= float(GeneralGame::yOffset))
	{
		pos.y = float(GeneralGame::yOffset);
	}
	if (pos.x >= float(Graphics::ScreenWidth - GeneralGame::offset) - width)
	{
		pos.x = float(Graphics::ScreenWidth - GeneralGame::offset) - width;
	}
	if (pos.y >= float(Graphics::ScreenHeight - GeneralGame::offset) - height)
	{
		pos.y = float(Graphics::ScreenHeight - GeneralGame::offset) - height;
	}
}

void Jaz::Draw(Graphics& gfx) const
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(width), int(height), Colors::Green);
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
		pos.y -= speed;;
	}
	if (kbd.KeyIsPressed('S'))
	{
		pos.y += speed;
	}
	if (kbd.KeyIsPressed('A'))
	{
		pos.x -= speed;
	}
	if (kbd.KeyIsPressed('D'))
	{
		pos.x += speed;
	}
}

Vec2 Jaz::GetPos()
{
	return pos;
}

float Jaz::GetWidth()
{
	return width;
}

float Jaz::GetHeight()
{
	return height;
}
