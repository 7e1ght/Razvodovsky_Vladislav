#include "Lose.h"

#include <ncurses.h>
#include <string>

inline void Lose::enterPressed()
{
	switch (_currentChoose)
	{
	case CHOOSE::MAIN_MENU:
        _returnScene = id_space::SCENE_ID::MAIN_MENU;
		break;
	case CHOOSE::NEW_GAME:
        _returnScene = id_space::SCENE_ID::GAME;
		break;
	}
}

id_space::SCENE_ID Lose::update()
{
	bool outLoop = false;

	while(outLoop == false)
	{
		std::string startStr = "   Main menu";
		std::string quitStr = "   New game";


        if(utilities_space::kbhit())
		{
            switch(getch())
			{
				case 'W': case 'w':
					_currentChoose = CHOOSE::MAIN_MENU;
					break;
				case 'S': case 's':
					_currentChoose = CHOOSE::NEW_GAME;
					break;
                case KEY_ENTER:
					enterPressed();
					outLoop = true;
					break;
			}
		}

		switch(_currentChoose)
		{
			case CHOOSE::MAIN_MENU:
				startStr[0] = '-';
				startStr[1] = '>';
				break;
			case CHOOSE::NEW_GAME:
				quitStr[0] = '-';
				quitStr[1] = '>';
				break;

			default:
				break;
		}

        utilities_space::NCSupport.drawText(startStr, position_space::Position(10, 10));
        utilities_space::NCSupport.drawText(quitStr, position_space::Position(10, 12));

        refresh();
	}

	return _returnScene;
}

Lose::Lose()
    : _returnScene(id_space::SCENE_ID::LOSE), _currentChoose(CHOOSE::MAIN_MENU)
{

}
