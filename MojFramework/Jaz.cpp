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
	Vec2 dir(0.0f, 0.0f);
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
		dir.y -= 1.0f;
	}
	if (kbd.KeyIsPressed('S'))
	{
		dir.y += 1.0f;
	}
	if (kbd.KeyIsPressed('A'))
	{
		dir.x -= 1.0f;
	}
	if (kbd.KeyIsPressed('D'))
	{
		dir.x += 1.0f;
	}
	pos += dir.GetNormalized() * speed;
}

void Jaz::Update(const Mouse& mouse)
{
	if (mouse.LeftIsPressed())
	{
		firing = true;
		//
		//pos += 
	}
	else
	{
		firing = false;
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

bool Jaz::FiringStatus()
{
	return firing;
}

Vec2 Jaz::GetCenter()
{
	return pos + Vec2(width / 2.0f, height / 2.0f);
}

Vec2 Jaz::GetDirection(const Mouse& mouse)
{
	Vec2 dir = Vec2(float(mouse.GetPosX()), float(mouse.GetPosY())) - GetCenter();
	return dir.GetNormalized();
}
