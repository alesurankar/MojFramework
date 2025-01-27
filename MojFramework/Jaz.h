#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "GeneralGame.h"
#include "Vec2.h"
#include "Surface.h"

class Jaz
{
public:
	Jaz(const Vec2& pos_in);
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(const Mouse& mouse, const Keyboard& kbd, float dt);
	Vec2 GetPos();
	float GetWidth();
	float GetHeight();
	bool FiringStatus();
	Vec2 GetCenter();
	Vec2 GetDirection(const Mouse& mouse);
	void Destroyed();
	void Respawn();
	bool DestroyedStatus();
	void Damaged();
private:
	Surface surf = Surface("SpriteMe21x36.bmp");
	float inOff = 1.0f;
	bool destroyed = false;
	int lives;
	bool firing;
	Vec2 pos;
	float speed;
	static constexpr float width = 21.0f;
	static constexpr float height = 36.0f;
	static constexpr int maxLives = GeneralGame::myLives;
};