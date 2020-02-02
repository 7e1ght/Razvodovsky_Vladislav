#include "MainMenu.h"

#include <ncurses.h>
#include <string>

inline void MainMenu::enterPressed()
{
	switch (_currentChoose)
	{
	case CHOOSE::START_GAME:
        _returnScene = id_space::SCENE_ID::GAME;
		break;
	case CHOOSE::QUIT:
        _returnScene = id_space::SCENE_ID::END_GAME;
		break;
	}
}

id_space::SCENE_ID MainMenu::update(sec delta)
{
//	bool isEnterPressed = false;

//	while (isEnterPressed == false)
//	{
		std::string startStr = "   Start game";
		std::string quitStr = "   Quit";

        if (utilities_space::kbhit())
		{
            switch (getch())
			{
            case 'W':
            case 'w':
            case KEY_UP:
				_currentChoose = CHOOSE::START_GAME;
				break;
            case 'S':
            case 's':
            case KEY_DOWN:
				_currentChoose = CHOOSE::QUIT;
				break;
            case KEY_ENTER:
            case scene::ENTER_KEY:
				enterPressed();
//				isEnterPressed = true;
				break;
			}
		}

		switch (_currentChoose)
		{
		case CHOOSE::START_GAME:
			startStr[0] = '-';
			startStr[1] = '>';
			break;
		case CHOOSE::QUIT:
			quitStr[0] = '-';
			quitStr[1] = '>';
			break;

		default:
			break;
		}

        utilities_space::NCSupport.drawText(startStr.c_str(), position_space::Position(10, 10));
        utilities_space::NCSupport.drawText(quitStr.c_str(), position_space::Position(10, 12));

        refresh();
//	}

	return _returnScene;
}

MainMenu::MainMenu() : _returnScene(id_space::SCENE_ID::MAIN_MENU), _currentChoose(CHOOSE::START_GAME)
{

}
