#include "Lose.h"

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


        if(utilities::kbhit())
        {
            switch(getch())
            {
                case 'W': case 'w': case KEY_UP:
                    _currentChoose = CHOOSE::MAIN_MENU;
                    break;
                case 'S': case 's': case KEY_DOWN:
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

        _drawer->setText(startStr.c_str(), 10, 10);
        _drawer->setText(quitStr.c_str(), 10, 12);

		_drawer->draw();
	}

	return _returnScene;
}

Lose::Lose(std::unique_ptr<Drawer>& d) : Scene(d), _returnScene(scene::LOSE), _currentChoose(CHOOSE::MAIN_MENU)
{

}
