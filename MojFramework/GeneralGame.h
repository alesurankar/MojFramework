#pragma once

#include "Graphics.h"

class GeneralGame
{
public:
	void GameOverBanner(Graphics& gfx) const;
public:
	bool gameOver = true;
};