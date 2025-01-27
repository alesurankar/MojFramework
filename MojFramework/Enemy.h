#pragma once

#include "Graphics.h"
#include "Jaz.h"
#include "GeneralGame.h"
#include "Vec2.h"
#include "Bullet.h"
#include "Surface.h"

class Enemy
{
public:
	Enemy(const Vec2& pos_in, const Vec2& vel_in);
	void BorderCheck();
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool Colliding(Jaz& jaz);
	bool Colliding(Bullet& bul);
	void Destroyed();
	void Respawn();
	bool DestroyedStatus();
	void Damaged();
private:
	Surface surf = Surface("SpriteEnemy24x24.bmp");
	float inOff = 1.0f;
	int lives;
	bool destroyed = false;
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 24.0f;
	static constexpr float height = 24.0f;
	static constexpr int maxLives = GeneralGame::enemyLives;
};