#pragma once

#include "Graphics.h"
#include "Jaz.h"
#include "GeneralGame.h"
#include "Vec2.h"
#include "Bullet.h"

class Object
{
public:
	void InitRed(const Vec2& pos_in, const Vec2& vel_in);
	void InitBlue(const Vec2& pos_in);
	void BorderCheck();
	void DrawRed(Graphics& gfx) const;
	void DrawBlue(Graphics& gfx) const;
	void Update();
	bool Colliding(Jaz& jaz);
	bool Colliding(Bullet& bul);
	void Destroyed();
	void Respawn();
	bool DestroyedStatus();
	void Damaged();
private:
	float inOff = 1.0f;
	int lives;
	bool destroyed = false;
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 12.0f;
	static constexpr float height = 12.0f;
	static constexpr int maxLives = GeneralGame::enemyLives;
};