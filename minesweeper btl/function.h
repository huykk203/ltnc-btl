#pragma once
#pragma once
#include "Timer.h"
#include <SDL.h>

bool init();
bool LoadMedia();
bool LoadMenuMedia();
void close();
void CreateMineBoard();
void CustomMode();
void showMenu();
void showModeChoice();
void SetButtonPosition();
void PlayerWinning();
void MineManager();
void PlayAgain();
void GameManager();
void TimeManager();
void Setting(int x, int y, int n, int a, int b, int c, int d, int e, int& BoardSizeX, int& BoardSizeY, int& TotalMine, int& MineLeft, int& TileLeft, int& DistanceX, int& DistanceY, int& DigitX, int& DigitY, int& TimeX);
void handleEvent();
void OpenBoard(int i, int j);
void RenderGame();
