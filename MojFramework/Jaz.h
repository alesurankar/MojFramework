#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "GeneralGame.h"
#include "Vec2.h"

class Jaz
{
public:
	Jaz(const Vec2& pos_in);
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(const Mouse& mouse, const Keyboard& kbd);
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
	float inOff = 1.0f;
	bool destroyed = false;
	int lives;
	bool firing;
	Vec2 pos;
	float speed;
	static constexpr float width = 12.0f;
	static constexpr float height = 12.0f;
	static constexpr int maxLives = GeneralGame::myLives;
};