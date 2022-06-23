#include "Texture.h"
#include "Buttons.h"
#include "Variables.h"
#include "constant.h"
#include "function.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (!init())
	{
		cout<<"Fail";
	}
	else
	{
    if (LoadMedia())
    {
    if (LoadMenuMedia())
    {
        showMenu();
        while (MenuChoice)
        {
            if (Choosing)
            {
            showModeChoice();
            }
            if(customMode) CustomMode();
            while (Running)
           {
             handleEvent();
             SetButtonPosition();
             RenderGame();
            }
        }
    }
    }
	}
	close();
	return 0;
}




