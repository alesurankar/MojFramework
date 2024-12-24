#pragma once

#include "Graphics.h"
#include "Jaz.h"
#include "GeneralGame.h"

class Object
{
public:
	void InitRed(float x_in, float y_in, float vx_in, float vy_in);
	void InitBlue(float x_in, float y_in);
	float BorderCheckX(float x_in, float width_in);
	float BorderCheckY(float y_in, float height_in);
	void DrawRed(Graphics& gfx) const;
	void DrawBlue(Graphics& gfx) const;
	void Update();
	bool Colliding(Jaz& jaz);
private:
	float x;
	float y;
	float vx;
	float vy;
	static constexpr float width = 12.0f;
	static constexpr float height = 12.0f;
};