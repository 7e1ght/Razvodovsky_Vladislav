#include "MainMenu.h"

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

scene::SCENE_ID MainMenu::update()
{
	bool isEnterPressed = false;

	while (isEnterPressed == false)
	{
		std::string startStr = "   Start game";
		std::string quitStr = "   Quit";

        if (utilities::kbhit())
        {
            switch (getch())
            {
            case 'W': case 'w': case KEY_UP:
                _currentChoose = CHOOSE::START_GAME;
                break;
            case 'S': case 's': case KEY_DOWN:
                _currentChoose = CHOOSE::QUIT;
                break;
            case KEY_ENTER:
                enterPressed();
                isEnterPressed = true;
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

        _drawer->setText(startStr.c_str(), 10, 10);
        _drawer->setText(quitStr.c_str(), 10, 12);

		_drawer->draw();
	}

	return _returnScene;
}

MainMenu::MainMenu(std::unique_ptr<Drawer>& d) : Scene(d), _returnScene(scene::MAIN_MENU), _currentChoose(CHOOSE::START_GAME)
{

}
