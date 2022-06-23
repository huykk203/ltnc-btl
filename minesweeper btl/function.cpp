#include "Texture.h"
#include "Variables.h"
#include "constant.h"
#include "Buttons.h"
#include "function.h"
#include "Timer.h"
#include <bits/stdc++.h>

using namespace std;
vector <vector<LButton> > Buttons(3, vector<LButton>(2));
LButton Face;
LButton GoBack;
LButton Sound;
LButton Pause;
LTimer timer;

void LButton::handleEventPause(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPosition.x||x > mPosition.x + 50||y > mPosition.y + 50||y < mPosition.y)
		{
			inside = false;
		}

		if (inside)
		{
			if (e->button.button == SDL_BUTTON_LEFT)
			{   if (continu == false)
				{
                 timer.unpause();
				 continu=true;
				}
			   else
               {
                 timer.pause();
                 continu=false;
               }

		    }
        }
     }
}
bool init()
{

	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
	    cout << "SDL could not Initialize! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{

		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{

			cout << "Warning: Linear texture filtering not enabled!";
		}


		window = SDL_CreateWindow( "Minesweeper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{

			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( renderer == NULL )
			{
			    cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
				    cout << "SDL_image could not Initialize! SDL_image Error: " << IMG_GetError() << endl;
					success = false;
				}


				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
				    cout << "SDL_mixer could not Initialize! SDL_mixer Error: " << Mix_GetError() << endl;
					success = false;
				}

				if( TTF_Init() == -1 )
				{
				    cout << "SDL_ttf could not Initialize! SDL_ttf Error: " << TTF_GetError() << endl;
					success = false;
				}
			}
		}
	}

	return success;
}

bool LoadMedia()
{
	bool success = true;


	if (!EasyBackground.loadFromFile("texture/images/easybackground.jpg"))
    {
       cout<<"Fail"<<endl;
		success = false;
    }
    if (!MediumBackground.loadFromFile("texture/images/mediumbackground.jpg"))
    {
       cout<<"Fail"<<endl;
		success = false;
    }
    if (!HardBackground.loadFromFile("texture/images/hardbackground.jpg"))
    {
       cout<<"Fail"<<endl;
		success = false;
    }
    if (!CustomBackground.loadFromFile("texture/images/custombackground.jpg"))
    {
        cout<<"Fail"<<endl;
		success = false;
    }
	if (!TimeImage.loadFromFile("texture/images/hourglass.png"))
    {
        cout<<"Fail"<<endl;
		success = false;
    }
    if (!MineImage.loadFromFile("texture/images/bomb.png"))
    {
       cout<<"Fail"<<endl;
		success = false;
    }
    if (!PauseIcon.loadFromFile("texture/images/pause.png"))
    {
       cout<<"Fail"<<endl;
		success = false;
    }
	if (!winFace.loadFromFile("texture/images/winface.png"))
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	if (!loseFace.loadFromFile("texture/images/loseface.png"))
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	if (!playingFace.loadFromFile("texture/images/playingface.png"))
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	if (!back.loadFromFile("texture/images/back.png"))
	{
	    cout<<"Fail"<<endl;
		success = false;
	}
	if (!sound_on.loadFromFile("texture/images/unmute.jpg"))
	{
	    cout<<"Fail"<<endl;
		success = false;
	}
	if (!sound_off.loadFromFile("texture/images/mute.png"))
	{
	    cout<<"Fail"<<endl;
		success = false;
	}
	//Open the font
	gFont = TTF_OpenFont("texture/font.ttf", 22);
	if (gFont == NULL)
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	//load text
	SDL_Color textcolor1 = { 255,255,255 };
	if (!menu.loadFromRenderedText("START", textcolor1))
	{
		cout<<"Fail"<<endl;
	}
	if (!menu1.loadFromRenderedText("EXIT", textcolor1))
	{
		cout<<"Fail"<<endl;
	}
	SDL_Color color = { 255,0,0 };
	if (!menuColor.loadFromRenderedText("START", color))
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	if (!menu1Color.loadFromRenderedText("EXIT", color))
	{
		cout<<"Fail"<<endl;
		success = false;
	}

	LoseMusic = Mix_LoadMUS("texture/audio/bomb.wav");
	if (LoseMusic == NULL)
	{
		cout<<"Fail"<<endl;
		success = false;
	}


	WinMusic = Mix_LoadMUS("texture/audio/beat.wav");
	if (WinMusic == NULL)
	{
		cout<<"Fail"<<endl;
		success = false;
	}

	Click = Mix_LoadWAV("texture/audio/Click.wav");
	if (Click == NULL)
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	if (!TileImage.loadFromFile("texture/images/tile.png"))
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	else
	{
		for (int i = 0;i < 12;++i)
		{
			TilesButton[i].x = i * TileSize;
			TilesButton[i].y = 0;
			TilesButton[i].w = TileSize;
			TilesButton[i].h = TileSize;
		}
	}

	if (!Digits.loadFromFile("texture/images/Time.png"))
	{
		cout<<"Fail"<<endl;
		success = false;
	}
	else
	{

		for (int i = 0;i < 10;i++)
		{
			TimeButton[i].x = i * 41;
			TimeButton[i].y = 0;
			TimeButton[i].w = 41;
			TimeButton[i].h = 41;
		}
	}
	return success;
}

bool LoadMenuMedia()
{
	bool success = true;

	if (!menuTheme.loadFromFile("texture/images/menu.png"))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}

	if (!LevelChoiceTheme.loadFromFile("texture/images/mode.jpg"))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	if (!customStart.loadFromFile("texture/images/custom.png"))
	{
		cout<<"Fail!"<<endl;
		success = true;
	}
	SDL_Color textColor1 = { 0,128,0 };
	if (!EasyChoice.loadFromRenderedText("EASY", textColor1))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	SDL_Color textColor2 = { 0, 0, 255 };
	if (!MediumChoice.loadFromRenderedText("MEDIUM", textColor2))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	SDL_Color textColor3 = { 255,165,0 };
	if (!HardChoice.loadFromRenderedText("HARD", textColor3))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	SDL_Color textColor4 = { 128,0,128 };
	if (!CustomChoice.loadFromRenderedText("CUSTOM ", textColor4))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	SDL_Color textcolor = { 255,0,0 };
	if (!EasyChoiceColor.loadFromRenderedText("EASY ", textcolor))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	if (!MediumChoiceColor.loadFromRenderedText("MEDIUM ", textcolor))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	if (!HardChoiceColor.loadFromRenderedText("HARD ", textcolor))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	if (!CustomChoiceColor.loadFromRenderedText("CUSTOM ", textcolor))
	{
		cout<<"Fail!"<<endl;
		success = false;
	}
	return success;
}


void CreateMineBoard()
{
	srand(time(0));
	int Mine = 0;
	for (int i = 0;i < BoardSizeX;i++)
	{
		for (int j = 0;j < BoardSizeY;j++)
		{
			HideBoard[i][j] = 10;
			ShowBoard[i][j] = 0;
		}
	}
	while (Mine < TotalMine)
	{
		int i = rand() % BoardSizeX;
		int j = rand() % BoardSizeY;
		if (ShowBoard[i][j] == 9) continue;
		else
		ShowBoard[i][j] = 9;
		Mine++;
	}
    for (int i = 0;i < BoardSizeX;i++)
	{
		for (int j = 0;j < BoardSizeY;j++)
		{
			if (ShowBoard[i][j] == 9) continue;
			for (int x = -1;x <= 1; x++)
			{
				for (int y = -1;y <= 1; y++)
				{
					int u = i + x;
					int v = j + y;
					if (u < 0 || u>BoardSizeX - 1 || v<0 || v>BoardSizeY - 1) continue;
					if (ShowBoard[u][v] == 9) ShowBoard[i][j]++;
				}
			}
		}
	}
}

void OpenBoard(int i, int j)
{
	if (HideBoard[i][j] == 10 || HideBoard[i][j] == 11)
	{

		HideBoard[i][j] = ShowBoard[i][j];
		if (HideBoard[i][j] == 9)
            {
						lose = true;
						Mix_PlayMusic(LoseMusic, 1);
            }
		if (HideBoard[i][j] != 9) TileLeft--;
		if (HideBoard[i][j] == 0)
		{
			for (int x = -1;x <= 1;x++)
			{
				for (int y = -1;y <= 1;y++)
				{
					int u = i + x;
					int v = j + y;
					if (u<0 || u>BoardSizeX - 1 || v<0 || v>BoardSizeY - 1) continue;
					OpenBoard(u, v);
				}
			}
		}
	}

		if (HideBoard[i][j]>= 1 && HideBoard[i][j]<= 8)
    {
                   int n=0;
            for (int x = -1;x <= 1;x++)
        {
				for (int y = -1;y <= 1;y++)
                {
                    int u = i + x;
					int v = j + y;
					if (u<0 || u>BoardSizeX - 1 || v<0 || v>BoardSizeY - 1) continue;
					if (HideBoard[u][v] == 11) n++;
                }

        }
        if (n == HideBoard[i][j])
        {
            for (int x = -1;x <= 1;x++)
			{
				for (int y = -1;y <= 1;y++)
				{
					int u = i + x;
					int v = j + y;
					if (u<0 || u>BoardSizeX - 1 || v<0 || v>BoardSizeY - 1) continue;
					if (HideBoard[u][v] == 10 ) OpenBoard(u, v);
				}
			}
        }
	 }

}
void SetButtonPosition()
{
	Face.SetPosition(screen/2 - 20, DigitY);
	GoBack.SetPosition(0, 0);
	Sound.SetPosition(TimeX - 10, 0);
	Pause.SetPosition(screen/2 - 20, 0);
	for (int i = 0;i < BoardSizeX;++i)
	{
		for (int j = 0;j < BoardSizeY;++j)
		{
			Buttons[i][j].SetPosition(i * TileSize + DistanceX, j * TileSize + DistanceY);
		}
	}
}

void showMenu()
{
	bool startInside = false;
	bool exitInside = false;
	bool MenuShowing = true;
	SDL_Event e;
	menuTheme.render(0, 0);
	menu.render(350, 350);
	menu1.render(500, 350);
	SDL_RenderPresent(renderer);
	while (MenuShowing)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				MenuChoice = false;
				MenuShowing = false;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (x > 350 && x < 350 + menu.getWidth() && y > 350 && y < 350 + menu.getHeight()) startInside = true;
				else startInside = false;
				if (x > 500 && x < 500 + menu1.getWidth() && y > 350 && y < 350 + menu1.getHeight()) exitInside = true;
				else exitInside = false;
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (startInside == true)
						{
							start = true;
							MenuShowing = false;
						}
						if (exitInside == true)
						{
							MenuChoice = false;
							MenuShowing = false;

						}
					}
				}
				if (e.type == SDL_MOUSEMOTION)
				{
					if (startInside == true)
					{
						menuColor.render(350, 350);
					}
					else menu.render(350, 350);
					if (exitInside == true)
					{
						menu1Color.render(500, 350);

					}
					else menu1.render(500, 350);
				}

			}
			SDL_RenderPresent(renderer);
		}
	}
}

void showModeChoice()
{
	bool easyInside = false;
	bool mediumInside = false;
	bool hardInside = false;
	bool customInside = false;
	SDL_Event e;
	LevelChoiceTheme.render(0, 0);
	EasyChoice.render(400, 150);
	MediumChoice.render(400, 200);
	HardChoice.render(400, 250);
	CustomChoice.render(400, 300);
	while (Choosing)
{
    while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				MenuChoice = false;
				Choosing = false;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (x > 400 && x < 400 + EasyChoice.getWidth() && y > 150 && y < 150 + EasyChoice.getHeight()) easyInside = true;
				else easyInside = false;
				if (x > 400 && x < 400 + MediumChoice.getWidth() && y > 200 && y < 200 + MediumChoice.getHeight()) mediumInside = true;
				else mediumInside = false;
				if (x > 400 && x < 400 + HardChoice.getWidth() && y > 250 && y < 250 + HardChoice.getHeight()) hardInside = true;
				else hardInside = false;
				if (x > 400 && x < 400 + CustomChoice.getWidth() && y > 300 && y < 300 + CustomChoice.getHeight()) customInside = true;
				else customInside = false;
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (easyInside == true)
						{   screen=500;
							Running = true;
							Choosing = false;
							customMode = false;
							timer.start();
							easy = true;
							medium = false;
							hard = false;
							cus = false;
							SDL_SetWindowSize(window, screen, screen);
							Setting(9, 9, 10, 106, 120, 0, 50, screen-41, BoardSizeX, BoardSizeY, TotalMine, MineLeft, TileLeft, DistanceX, DistanceY, DigitX, DigitY, TimeX);
							CreateMineBoard();
						}
						if (mediumInside == true)
						{   screen=700;
							Running = true;
							Choosing = false;
							customMode = false;
							timer.start();
							easy = false;
							medium = true;
							hard = false;
							cus = false;
							SDL_SetWindowSize(window, screen, screen);
							Setting(16, 16, 40, 94, 130, 0, 50, screen-41, BoardSizeX, BoardSizeY, TotalMine, MineLeft, TileLeft, DistanceX, DistanceY, DigitX, DigitY, TimeX);
							CreateMineBoard();
						}
						if (hardInside == true)
						{   screen=1000;
							Running = true;
							Choosing = false;
							customMode = false;
							timer.start();
							easy = false;
							medium = false;
							hard = true;
							cus = false;
							SDL_SetWindowSize(window,screen, 700);
							Setting(30, 16, 99, 20, 130, 0, 50, screen-41, BoardSizeX, BoardSizeY, TotalMine, MineLeft, TileLeft, DistanceX, DistanceY, DigitX, DigitY, TimeX);
							CreateMineBoard();
						}
						if (customInside == true)
						{
							Choosing = false;
							customMode = true;
							easy = false;
							medium = false;
							hard = false;
							cus = true;
						}
					}
				}
				if (e.type == SDL_MOUSEMOTION)
				{
					if (easyInside == true)
                         EasyChoiceColor.render(400, 150);
					else EasyChoice.render(400, 150);
					if (mediumInside == true)
					     MediumChoiceColor.render(400, 200);
					else MediumChoice.render(400, 200);
					if (hardInside == true)
					     HardChoiceColor.render(400, 250);
					else HardChoice.render(400, 250);
					if (customInside == true)
					     CustomChoiceColor.render(400, 300);
					else CustomChoice.render(400, 300);
				}
			}
			SDL_RenderPresent(renderer);
		}
	}
}

void CustomMode()
{
	SDL_Event e;
	SDL_Color black = { 0,0,0,0 };
	SDL_SetWindowSize(window, 400, 600);
	customStart.render(0, 0);
	string width, height, mine;
	int w = 0, h = 0, m = 0;
	char inputChar;
	bool widthInside = false;
	bool heightInside = false;
	bool mineInside = false;
	bool play = false;
	while (customMode)
	{
		SDL_StartTextInput();
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				customMode = false;
				MenuChoice = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (x > 200 && x < 267 && y>374 && y < 394) widthInside = true;
				else widthInside = false;
				if (x > 200 && x < 267 && y>400 && y < 400) heightInside = true;
				else heightInside = false;
				if (x > 200 && x < 267 && y>427 && y < 447) mineInside = true;
				else mineInside = false;
				if (x > 150 && x < 250 && y>488 && y < 526) play = true;
				else play = false;
				break;
			case SDL_TEXTINPUT:
				inputChar = e.text.text[0];
				if (inputChar >= '0' && inputChar <= '9')
				{
					if (widthInside && width.length() < 6)
					{
						width += e.text.text;
						w *= 10;
						w += (int)(inputChar - 48);
						wInput.loadFromRenderedText(width.c_str(), black);
					}
					else if (heightInside && height.length() < 6)
					{
						height += e.text.text;
						h *= 10;
						h += (int)(inputChar - 48);
						hInput.loadFromRenderedText(height.c_str(), black);
					}
					else if (mineInside && mine.length() < 6)
					{
						mine += e.text.text;
						m *= 10;
						m += (int)(inputChar - 48);
						mInput.loadFromRenderedText(mine.c_str(), black);
					}
				}
				break;
			case SDL_KEYDOWN:
				if (widthInside && e.key.keysym.sym == SDLK_BACKSPACE && width.length() > 0)
				{
					width.pop_back();
					w /= 10;
					wInput.loadFromRenderedText(width.c_str(), black);
				}
				else if (heightInside && e.key.keysym.sym == SDLK_BACKSPACE && height.length() > 0)
				{
					height.pop_back();
					h /= 10;
					hInput.loadFromRenderedText(height.c_str(), black);
				}
				else if (mineInside && e.key.keysym.sym == SDLK_BACKSPACE && mine.length() > 0)
				{
					mine.pop_back();
					m /= 10;
					mInput.loadFromRenderedText(mine.c_str(), black);
				}
				else if (e.key.keysym.sym == SDLK_DOWN)
				{
					if (widthInside)
					{
						widthInside = false;
						heightInside = true;
						mineInside = false;
					}
					else if (heightInside)
					{
						widthInside = false;
						heightInside = false;
						mineInside = true;
					}
					else if (mineInside)
					{
						widthInside = true;
						heightInside = false;
						mineInside = false;
					}
				}
				else if (e.key.keysym.sym == SDLK_UP)
				{
					if (widthInside)
					{
						widthInside = false;
						heightInside = false;
						mineInside = true;
					}
					else if (heightInside)
					{
						widthInside = true;
						heightInside = false;
						mineInside = false;
					}
					else if (mineInside)
					{
						widthInside = false;
						heightInside = true;
						mineInside = false;
					}
				}
				break;
			default:
				break;
			}
		}

		wInput.render(201, 370);
		hInput.render(201, 397);
		mInput.render(201, 423);
        if (play == true)
		{   screen=1200;
			Running = true;
			customMode = false;
			play = false;
			timer.start();
			SDL_SetWindowSize(window, 1200, 700);
			Setting(w, h, m, (screen-w*TileSize)/2, 100, 0, 50, screen-41 , BoardSizeX, BoardSizeY, TotalMine, MineLeft, TileLeft, DistanceX, DistanceY, DigitX, DigitY, TimeX);
			CreateMineBoard();
		}
		SDL_StopTextInput();
		SDL_RenderPresent(renderer);
	}

	width = "";
	height = "";
	mine = "";
	widthInside = false;
	heightInside = false;
	mineInside = false;
	wInput.free();
	hInput.free();
	mInput.free();
}


void Setting(int x, int y, int n, int a, int b, int c, int d, int e, int& BoardSizeX, int& BoardSizeY, int& TotalMine, int& MineLeft, int& TileLeft, int& DistanceX, int& DistanceY, int& DigitX, int& DigitY, int& TimeX)
{
	BoardSizeX = x;
	BoardSizeY = y;
	TotalMine = n;
	MineLeft = n;
	TileLeft = x * y;
	DistanceX = a;
	DistanceY = b;
	DigitX = c;
	DigitY = d;
	TimeX = e;
    Buttons.resize(BoardSizeX);
	for (int i = 0;i < BoardSizeX;i++)
	{
		Buttons[i].resize(BoardSizeY);
	}
	HideBoard.resize(BoardSizeX);
	for (int i = 0;i < BoardSizeX;i++)
	{
		HideBoard[i].resize(BoardSizeY);
	}
	ShowBoard.resize(BoardSizeX);
	for (int i = 0;i < BoardSizeX;i++)
	{
		ShowBoard[i].resize(BoardSizeY);
	}
}

void handleEvent()
{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				Running = false;
				MenuChoice = false;
			}
			Face.handleEventAgain(&e);
			GoBack.handleEventBack(&e);
			Sound.handleEventMute(&e);
			Pause.handleEventPause(&e);
			for (int i = 0; i < BoardSizeX; i++)
			{
				for (int j = 0; j < BoardSizeY; j++)
				{
					Buttons[i][j].handleEvent(&e);
				}
			}

		}
}



void PlayerWinning()
{
	if (TileLeft == TotalMine) Winning = true;
}

void GameManager()
{
	if (playAgain == true) PlayAgain();
	if (lose == true)
	{
		timer.pause();
		loseFace.render(screen/2 - 22, DigitY);
		for (int i = 0;i < BoardSizeX;i++)
		{
			for (int j = 0;j < BoardSizeY;j++)
			{
				Buttons[i][j].loseRender(i, j);
			}
		}
	}
	if (Winning == true)
	{
		timer.pause();
		winFace.render(screen/2 - 22, DigitY);

	}
}


void MineManager()
{
	int n = MineLeft;
	if (MineLeft < 10)
	{
		Digits.render(DigitX, DigitY, &TimeButton[0]);
		for (int i = 0;i <= 9;i++)
		{
			if (i == MineLeft) Digits.render(DigitX + 41, DigitY, &TimeButton[i]);
		}
	}

	else
	{
		int i = 0;
		while (n > 0)
		{
			int x = n % 10;
			n /= 10;
			Digits.render(DigitX + (1 - i) * 41, DigitY, &TimeButton[x]);
			i++;
		}
	}
}

void TimeManager()
{
	int n = timer.getTicks() / 1000;
	if (n < 10)
	{
		for (int i = 0;i <= 9;i++)
		{
			if (i == n) Digits.render(TimeX, DigitY, &TimeButton[n]);
		}
	}
	else
	{
		int i = 0;
		while (n > 0)
		{
			int x = n % 10;
			n /= 10;
			Digits.render(TimeX - i * 41, DigitY, &TimeButton[x]);
			i++;
		}
	}

}


void RenderButton()
{
	for (int i = 0;i < BoardSizeX;i++)
	{
		for (int j = 0;j < BoardSizeY;j++)
		{
			Buttons[i][j].render(i, j);
		}
	}
}

void PlayAgain()
{
    timer.start();
	CreateMineBoard();
	Mix_HaltMusic();
	MineLeft = TotalMine;
	TileLeft = BoardSizeX * BoardSizeY;
	Winning = false;
	lose = false;
	playAgain = false;
}

void RenderGame()
{
	if (mute == false)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
		SDL_RenderClear(renderer);
		sound_on.render(TimeX - 10, 0);
		LoseMusic = Mix_LoadMUS("texture/audio/bomb.wav");
		WinMusic = Mix_LoadMUS("texture/audio/win.mp3");
		Click = Mix_LoadWAV("texture/audio/Click.wav");
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		sound_off.render(TimeX - 10, 0);
		Click = NULL;
		WinMusic = NULL;
		LoseMusic = NULL;
	}
	if (easy == true || medium == true || hard == true || cus == true)
	{
		if (easy == true)
		{
			EasyBackground.render(0, 50);
		}
		if (medium == true)
		{
			MediumBackground.render(0, 50);
		}
		if (hard == true)
		{
			HardBackground.render(0, 50);
		}
		if (cus == true)
		{
			CustomBackground.render(0,50);
		}
	}
	playingFace.render(screen/2 - 20, DigitY);
	PauseIcon.render(screen/2 - 20, 0);
	TimeImage.render(TimeX, 91);
	MineImage.render(0, 91);
	RenderButton();
	back.render(0, 0);
	MineManager();
	PlayerWinning();
	TimeManager();
	GameManager();
	SDL_RenderPresent(renderer);
}

void close()
{
	TileImage.free();
	TTF_CloseFont(gFont);
	gFont = NULL;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}
