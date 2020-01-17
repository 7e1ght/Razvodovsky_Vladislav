#include "MainMenu.h"

#include <conio.h>
#include <string>

inline void MainMenu::enterPressed()
{
	switch (_currentChoose)
	{
	case CHOOSE::START_GAME:
		_returnScene = scene::GAME;
		break;
	case CHOOSE::QUIT:
		exit(0);
		break;
	}
}

scene::SCENE_ID MainMenu::update(sec delta)
{
	if (_drawer == nullptr) return scene::SCENE_ERROR;

	std::string startStr = "   Start game";
	std::string quitStr = "   Quit";

	if (_kbhit())
	{
		switch (_getch())
		{
		case 'W': case 'w':
			_currentChoose = CHOOSE::START_GAME;
			break;
		case 'S': case 's':
			_currentChoose = CHOOSE::QUIT;
			break;
		case main_menu::ENTER_KEY_CODE:
			enterPressed();
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

	_drawer->clearCanvas();
	_drawer->setText(startStr.c_str(), 10, 10, drawer::LIGHT_GRAY, drawer::BLACK);
	_drawer->setText(quitStr.c_str(), 10, 12, drawer::LIGHT_GRAY, drawer::BLACK);

	return _returnScene;
}

MainMenu::MainMenu(std::shared_ptr<Drawer> d) : Scene(d), _returnScene(scene::MAIN_MENU), _currentChoose(CHOOSE::START_GAME)
{

}
