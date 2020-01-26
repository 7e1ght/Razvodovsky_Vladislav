#define WINVER         _WIN32_WINNT_VISTA
#define _WIN32_WINNT   _WIN32_WINNT_VISTA

#include "GameController.h"

using namespace std;

int main()
{
	GameController gc;
	gc.startGame();

	return 0;
}