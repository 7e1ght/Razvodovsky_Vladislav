#include "Lose.h"

#include <conio.h>
#include <string>

inline void Lose::enterPressed()
{
	switch (_currentChoose)
	{
	case CHOOSE::MAIN_MENU:
		_returnScene = scene::MAIN_MENU;
		break;
	case CHOOSE::NEW_GAME:
		_returnScene = scene::GAME;
		break;
	}
}

scene::SCENE_ID Lose::update()
{
	bool outLoop = false;

	while(outLoop == false)
	{
		std::string startStr = "   Main menu";
		std::string quitStr = "   New game";


		if(_kbhit())
		{
			switch(_getch())
			{
				case 'W': case 'w':
					_currentChoose = CHOOSE::MAIN_MENU;
					break;
				case 'S': case 's':
					_currentChoose = CHOOSE::NEW_GAME;
					break;
				case main_menu::ENTER_KEY_CODE:
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

		_drawer->setText(startStr.c_str(), 10, 10, drawer::LIGHT_GRAY, drawer::BLACK);
		_drawer->setText(quitStr.c_str(), 10, 12, drawer::LIGHT_GRAY, drawer::BLACK);

		_drawer->draw();
	}

	return _returnScene;
}

Lose::Lose(std::unique_ptr<Drawer>& d) : Scene(d), _returnScene(scene::LOSE), _currentChoose(CHOOSE::MAIN_MENU)
{

}
