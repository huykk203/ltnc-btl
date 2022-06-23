#pragma once
#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H

#include "Texture.h"
#include "constant.h"
#include "Buttons.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern bool Running;
extern bool ShowMenu;
extern bool Choosing;
extern bool MenuChoice;
extern bool customMode;

extern bool Winning;
extern bool lose;

extern LTexture PauseIcon;
extern LTexture TimeImage;
extern LTexture MineImage;
extern LTexture EasyBackground;
extern LTexture MediumBackground;
extern LTexture HardBackground;
extern LTexture CustomBackground;
extern LTexture menuTheme;
extern LTexture LevelChoiceTheme;
extern LTexture customStart;
extern LTexture back;
extern LTexture sound_on;
extern LTexture sound_off;

extern LTexture winFace;
extern LTexture playingFace;
extern LTexture loseFace;

extern LTexture TileImage;
extern SDL_Rect TilesButton[12];

extern LTexture menu;
extern LTexture menu1;
extern LTexture menuColor;
extern LTexture menu1Color;
extern LTexture EasyChoice;
extern LTexture MediumChoice;
extern LTexture HardChoice;
extern LTexture CustomChoice;
extern LTexture EasyChoiceColor;
extern LTexture MediumChoiceColor;
extern LTexture HardChoiceColor;
extern LTexture CustomChoiceColor;
extern LTexture wInput;
extern LTexture hInput;
extern LTexture mInput;
extern TTF_Font* gFont;

extern std::vector <std::vector<int> > HideBoard;
extern std::vector <std::vector<int> > ShowBoard;

extern int MineLeft;
extern int TileLeft;

extern bool mute;
extern bool continu;
extern Mix_Chunk* Click;
extern Mix_Music* LoseMusic;
extern Mix_Music* WinMusic;

extern int DistanceX;
extern int DistanceY;
extern int DigitX;
extern int DigitY;
extern int TimeX;
extern int screen;

extern LTexture Digits;
extern SDL_Rect TimeButton[10];

extern int BoardSizeX;
extern int BoardSizeY;
extern int TotalMine;

// boolean
extern bool playAgain;
extern bool saveScore;
extern bool start;
extern bool easy;
extern bool medium;
extern bool hard;
extern bool cus;

#endif
