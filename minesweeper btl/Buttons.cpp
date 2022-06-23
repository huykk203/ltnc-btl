#include "Variables.h"
#include "constant.h"
#include "Buttons.h"
#include "function.h"
#include "Timer.h"

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
}

void LButton::SetPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{

	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{

		int x, y;
		SDL_GetMouseState(&x, &y);

		int i =  ( x - DistanceX)  / TileSize;
		int j = (y - DistanceY) / TileSize;

		bool inside = true;

		if (x < mPosition.x||x > mPosition.x + TileSize||y < mPosition.y||y > mPosition.y + TileSize)
		{
			inside = false;
		}
		if (inside)
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				switch (e->button.button)
				{
				case SDL_BUTTON_LEFT:
				{
					OpenBoard(i, j);
					if (TileLeft == TotalMine)
					{
						Mix_PlayMusic(WinMusic, 1);
					}

					if (HideBoard[i][j] == 9)
					{
						lose = true;
						Mix_PlayMusic(LoseMusic, 1);
					}
					else
					{
						Mix_PlayChannel(-1, Click, 0);
					}
					break;
				}
				case SDL_BUTTON_RIGHT:
				{
					Mix_PlayChannel(-1, Click, 0);
					if (HideBoard[i][j] >= 10)
					{
						if (HideBoard[i][j] == 11)
						{
							HideBoard[i][j] = 10;
							MineLeft++;
						}
						else
						{
							HideBoard[i][j] = 11;
							MineLeft--;
						}
					}
					else break;
					break;
				}
				}
			}
		}
	}
}

void LButton::handleEventAgain(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPosition.x||x > mPosition.x + 41||y > mPosition.y + 41||y < mPosition.y)
		{
			inside = false;
		}

		if (inside)
		{
			if (e->button.button == SDL_BUTTON_LEFT)
			{
				PlayAgain();
			}
		}
	}
}


void LButton::handleEventBack(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPosition.x||x > mPosition.x + 50||y < mPosition.y||y > mPosition.y + 50)
		{
			inside = false;
		}
		if (inside)
		{
			if (e->button.button == SDL_BUTTON_LEFT)
			{
				SDL_SetWindowSize(window, SCREEN_WIDTH, SCREEN_HEIGHT);
				Running = false;
				customMode = false;
				Choosing = true;
				Winning = false;
				lose = false;
				easy = false;
				medium = false;
				hard = false;
				cus = false;
			}
		}
	}
}

void LButton::handleEventMute(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;

		if (x < mPosition.x||x > mPosition.x + 50||y < mPosition.y||y > mPosition.y + 50)
		{
			inside = false;
		}

		if (inside)
		{
			if (e->button.button == SDL_BUTTON_LEFT)
			{
				if (mute == true) mute = false;
				else mute = true;
			}
		}
	}
}



void LButton::render(int i, int j)
{
	TileImage.render(mPosition.x, mPosition.y, &TilesButton[HideBoard[i][j]]);
}
void LButton::loseRender(int i, int j)
{
	TileImage.render(mPosition.x, mPosition.y, &TilesButton[ShowBoard[i][j]]);
}
