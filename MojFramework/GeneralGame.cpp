#include "GeneralGame.h"

void GeneralGame::GameWonBanner(Graphics& gfx) const
{
	gfx.DrawRect(0, 0, Graphics::ScreenWidth, Graphics::ScreenHeight, Colors::Green);
}

void GeneralGame::GameLostBanner(Graphics& gfx) const
{
	gfx.DrawRect(0, 0, Graphics::ScreenWidth, Graphics::ScreenHeight, Colors::Red);
}

void GeneralGame::DrawScore(Graphics& gfx) const
{
	gfx.DrawRect(offset, offset, scoreX * score, scoreY, Colors::Blue);
}

void GeneralGame::DrawGameBorder(Graphics& gfx) const
{
	gfx.DrawRect(0, 2 * offset + scoreY, offset, Graphics::ScreenHeight, Colors::Blue);
	gfx.DrawRect(0, Graphics::ScreenHeight - offset, Graphics::ScreenWidth, Graphics::ScreenHeight, Colors::Blue);
	gfx.DrawRect(Graphics::ScreenWidth - offset, 2 * offset + scoreY, Graphics::ScreenWidth, Graphics::ScreenHeight, Colors::Blue);
	gfx.DrawRect(0, 2 * offset + scoreY, Graphics::ScreenWidth, yOffset, Colors::Blue);
}

bool GeneralGame::GameOverStatus()
{
	return gameOver;
}

bool GeneralGame::GameWonStatus()
{
	return gameWon;
}

int GeneralGame::ScoreStatus()
{
	return score;
}

void GeneralGame::StartGame()
{
	score = 0;
	gameOver = false;
	gameWon = false;
}

void GeneralGame::GameOver()
{
	gameOver = true;
}

void GeneralGame::GameWon()
{
	gameWon = true;
}

void GeneralGame::AddScore()
{
	score++;
}
