#pragma once

#include "Graphics.h"

class GeneralGame
{
public:
	void GameOverBanner(Graphics& gfx) const;
	bool GameOverStatus();
	void StartGame();
	void GameOver();
private:
	bool gameOver = true;
};