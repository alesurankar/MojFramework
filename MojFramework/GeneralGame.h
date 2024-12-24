#pragma once

#include "Graphics.h"

class GeneralGame
{
public:
	void GameWonBanner(Graphics& gfx) const;
	void GameLostBanner(Graphics& gfx) const;
	void DrawScore(Graphics& gfx) const;
	void DrawGameBorder(Graphics& gfx) const;
	bool GameOverStatus();
	bool GameWonStatus();
	int ScoreStatus();
	void StartGame();
	void GameOver();
	void GameWon();
	void AddScore();
private:
	bool gameOver = true; 
	bool gameWon = true;
	int score = 0;
	int scoreX = Graphics::ScreenWidth / maxScore;
public:
	static constexpr int offset = 2;
	static constexpr int scoreY = 12;
	static constexpr int maxScore = 8;
	static constexpr float difficulty = 2.0f;
	static constexpr int yOffset = 3 * offset + scoreY;
};