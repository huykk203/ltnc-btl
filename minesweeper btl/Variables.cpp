#include "Variables.h"
#include<iostream>

extern bool Running = false;
extern bool ShowMenu = false;
extern bool Choosing = true;
extern bool MenuChoice = true;
extern bool customMode = false;
extern bool Winning = false;
extern bool lose = false;
extern int MineLeft = TotalMine;
extern int TileLeft = BoardSizeX * BoardSizeY;

extern LTexture PauseIcon (NULL, 0 ,0);
extern LTexture TimeImage(NULL, 0 ,0);
extern LTexture MineImage(NULL, 0, 0);
extern LTexture EasyBackground(NULL, 0, 0);
extern LTexture MediumBackground(NULL, 0, 0);
extern LTexture HardBackground(NULL,0 ,0);
extern LTexture CustomBackground(NULL,0 ,0);
extern LTexture menuTheme(NULL, 0, 0);
extern LTexture LevelChoiceTheme(NULL, 0, 0);
extern LTexture customStart(NULL, 0, 0);
extern LTexture back(NULL, 0, 0);
extern LTexture sound_on(NULL, 0, 0);
extern LTexture sound_off(NULL, 0, 0);
extern LTexture winFace(NULL,0,0);
extern LTexture playingFace(NULL,0,0);
extern LTexture loseFace(NULL,0,0);

extern LTexture menu(NULL, 0, 0);
extern LTexture menu1(NULL, 0, 0);
extern LTexture menuColor(NULL, 0, 0);
extern LTexture menu1Color(NULL, 0, 0);
extern LTexture EasyChoice(NULL, 0, 0);
extern LTexture MediumChoice(NULL, 0, 0);
extern LTexture HardChoice(NULL, 0, 0);
extern LTexture CustomChoice(NULL, 0, 0);
extern LTexture EasyChoiceColor(NULL, 0, 0);
extern LTexture MediumChoiceColor(NULL, 0, 0);
extern LTexture HardChoiceColor(NULL, 0, 0);
extern LTexture CustomChoiceColor(NULL, 0, 0);
extern LTexture wInput(NULL, 0, 0);
extern LTexture hInput(NULL, 0, 0);
extern LTexture mInput(NULL, 0, 0);


extern std::vector <std::vector<int> > HideBoard(3, std::vector<int>(2,0));
extern std::vector <std::vector<int> > ShowBoard(3, std::vector<int>(2, 0));

extern LTexture TileImage(NULL, 0, 0);
extern SDL_Rect TilesButton[12] = {};


extern bool mute = false;
extern bool continu = false;
extern Mix_Chunk* Click = NULL;
extern Mix_Music* LoseMusic = NULL;
extern Mix_Music* WinMusic = NULL;


extern int DistanceX = 0;
extern int DistanceY = 0;
extern int DigitX = 0;
extern int DigitY = 0;
extern int TimeX = 0;
extern int screen =0;


extern LTexture Digits(NULL, 0, 0);
extern SDL_Rect TimeButton[10] = {};


extern int BoardSizeX = 0;
extern int BoardSizeY = 0;
extern int TotalMine = 0;


extern bool playAgain = false;
extern bool saveScore = false;
extern bool start = false;
extern bool easy = false;
extern bool medium = false;
extern bool hard = false;
extern bool cus = false;

