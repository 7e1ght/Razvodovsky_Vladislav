#pragma once
#include <cfloat>
#include <vector>
#include <ncurses.h>
#include <string>
#include <map>

#include <sys/mman.h>

typedef float sec;

namespace scene
{
    const float NO_DELTA = 0.f;
    const int ENTER_KEY = 10;
}

namespace gamefield
{

const unsigned short GAMEFIELD_ROW = 25;
const unsigned short GAMEFIELD_COLUMN = 25;

}
namespace drawer
{

const unsigned short CANVAS_ROW = 30;
const unsigned short CANVAS_COLUMN = 30;

}
namespace id_space
{

enum BLOCK_ID
{
    SPACE,
    WALL,
    FOOD,
    ENERGYZE,
    DOOR
};

enum class COLOR_ID : int
{
    SPACE,
    WALL,
    FOOD,
    ENERGYZE,
    DOOR,
    PLAYER = 10,
    INKY,
    PINKY,
    CLYDE,
    BLINKY,
    DEFAULT_TEXT = 20
};

enum class SCENE_ID : int
{
    BEFORE_BIG_BANG,
    GAME,
    LOSE,
    SCENE_ERROR,
    MAIN_MENU,
    END_GAME
};

}
namespace appearance_space
{

struct ConsoleSymbolData
{
    char symbol;
    int colorId;
};

const ConsoleSymbolData DEFAULT_TEXT_APPREARANCE { ' ', static_cast<int>(id_space::COLOR_ID::DEFAULT_TEXT)};

const ConsoleSymbolData WALL_APPEARANCE { ' ', static_cast<int>(id_space::COLOR_ID::WALL)};
const ConsoleSymbolData FOOD_APPEARANCE { '.', static_cast<int>(id_space::COLOR_ID::FOOD)};
const ConsoleSymbolData ENERGYZE_APPEARANCE { 'o', static_cast<int>(id_space::COLOR_ID::ENERGYZE)};
const ConsoleSymbolData DOOR_APPEARANCE { ' ', static_cast<int>(id_space::COLOR_ID::DOOR)};
const ConsoleSymbolData SPACE_APPEARANCE{ ' ', static_cast<int>(id_space::COLOR_ID::SPACE)};

const ConsoleSymbolData PLAYER_APPREARANCE { 'C', static_cast<int>(id_space::COLOR_ID::PLAYER)};
const ConsoleSymbolData BLINKY_APPREARANCE { 'B', static_cast<int>(id_space::COLOR_ID::BLINKY)};
const ConsoleSymbolData INKY_APPREARANCE { 'I', static_cast<int>(id_space::COLOR_ID::INKY)};
const ConsoleSymbolData CLYDE_APPREARANCE {'D', static_cast<int>(id_space::COLOR_ID::CLYDE)};
const ConsoleSymbolData PINKY_APPREARANCE {'P', static_cast<int>(id_space::COLOR_ID::PINKY)};

}
namespace position_space
{

struct Position
{
    short x;
    short y;

    Position operator-(const Position& pos)
    {
        return Position(x - pos.x, y - pos.y);
    }

    Position operator*(const int& num)
    {
        return Position(x * num, y * num);
    }

    Position(short xx, short yy) : x(xx), y(yy)
    {

    }

    Position()
    {
    }
};

const Position PLAYER_START_POSITION{ 12, 19 };

const Position BLINKY_START_POSITION{ 11, 9 };
const Position CLYDE_START_POSITION{ 12, 9 };
const Position PINKY_START_POSITION{ 13, 9 };
const Position INKY_START_POSITION{ 14, 9 };


const Position INKY_SCATTER_POSITION{ 30, 30 };
const Position BLINKY_SCATTER_POSITION{ 30, 0 };
const Position CLYDE_SCATTER_POSITION{ 0, 30 };
const Position PINKY_SCATTER_POSITION{ 0, 0 };

const Position DIE_SCREEN_POSITION {0, 10};

const Position DOOR_START{11, 10};

}
namespace map_space
{

const char BLOCK_MAP[gamefield::GAMEFIELD_ROW][gamefield::GAMEFIELD_COLUMN] =
{
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 4, 4, 4, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

const char FOOD_MAP[gamefield::GAMEFIELD_ROW][gamefield::GAMEFIELD_COLUMN] =
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
    { 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0 },
    { 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0 },
    { 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 3, 0 },
    { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
    { 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0 },
    { 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
    { 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0 },
    { 0, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 0 },
    { 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0 },
    { 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0 },
    { 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

const std::vector<std::vector<char>> DIE_MAP
{
    { 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0 }
};

}
namespace characters
{

enum DIRECTION { UP, DOWN, LEFT, RIGHT, STOP };

}
namespace main_menu
{
    const unsigned LOGO_WIDTH = 29;
    const unsigned LOGO_HEIGHT = 5;
}
namespace mode
{
    const float MAX_DURATION = FLT_MAX;
}
namespace game_scene
{

enum STATE
{
    LOSE,
    WIN,
    PLAY,
    PAUSE,
    GHOST_EAT_ME,
    RESET_GAME
};

const unsigned DOOR_SIZE = 3;

}
namespace utilities_space
{

bool kbhit();

class NCursesSupport
{
private:
    std::map<std::string, appearance_space::ConsoleSymbolData> userAppearance;
public:
    void initColors();

    void drawChar(const position_space::Position& p, const appearance_space::ConsoleSymbolData& appearance);
    void drawText(const std::string& text, const position_space::Position& p, const appearance_space::ConsoleSymbolData& appearance = appearance_space::DEFAULT_TEXT_APPREARANCE);

    void drawRect(const position_space::Position& p, const std::vector<std::vector<char>>& rectData, const appearance_space::ConsoleSymbolData& appearance);

    void addSymbol(const std::string& appearanceName, const char symbol, const short foreground, const short background);
    appearance_space::ConsoleSymbolData getAppearance(const std::string& appearanceName);
} static NCSupport;

class SHMHellper
{
private:
    static std::map<std::string, int> _nameFd;

    SHMHellper() = delete;
    SHMHellper(const SHMHellper&) = delete;
    SHMHellper operator=(const SHMHellper&) = delete;
public:
    static void createSHM(const std::string& shmName, const size_t size);
    static void connectSHM(const std::string& shmName);
    template<typename T>
    static void setDataSHM(const T& data, const std::string& shmName);
    template<typename T>
    static T getDataSHM(const std::string& shmName);

    ~SHMHellper();
};



template<typename T>
void SHMHellper::setDataSHM(const T& data, const std::string& shmName)
{
    const T* dataPtr = &data;

    const size_t dataSize = sizeof(data);

    const char* dataByte = reinterpret_cast<const char*>(dataPtr);

    char* mapRegion = static_cast<char*>(mmap(nullptr, dataSize, PROT_WRITE, MAP_SHARED, _nameFd[shmName], 0));

    for(int i = 0; i < dataSize; ++i)
    {
        mapRegion[i] = dataByte[i];
    }

    munmap(mapRegion, dataSize);
}

template<typename T>
T SHMHellper::getDataSHM(const std::string& shmName)
{
    T tempFile;

    char* tempFileByte = reinterpret_cast<char*>(&tempFile);

    const size_t dataSize = sizeof(T);

    char* mapRegion = static_cast<char*>(mmap(nullptr, dataSize, PROT_READ, MAP_SHARED, _nameFd[shmName], 0));

    for(int i = 0; i < dataSize; ++i)
    {
        tempFileByte[i] = mapRegion[i];
    }

    munmap(mapRegion, dataSize);

    return tempFile;
}

}
