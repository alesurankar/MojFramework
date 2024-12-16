#include "GeneralGame.h"

void GeneralGame::GameOverBanner(Graphics& gfx) const
{
	for (int i = 0; i < Graphics::ScreenWidth; i++)
	{
		for (int j = 0; j < Graphics::ScreenHeight; j++)
		{
			gfx.PutPixel(i, j, Colors::Green);
		}
	}
}