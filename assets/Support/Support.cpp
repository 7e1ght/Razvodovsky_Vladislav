#include "Support.h"


#include <algorithm>

#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

using namespace utilities_space;

bool utilities_space::kbhit()
{
    struct timeval        timeout;
    fd_set                readfds;
    int                how;

    /* look only at stdin (fd = 0) */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    /* poll: return immediately */
    timeout.tv_sec = 0L;
    timeout.tv_usec = 0L;

    how = select(1, &readfds, (fd_set *)NULL, (fd_set *)NULL, &timeout);
    /* Change "&timeout" above to "(struct timeval *)0"       ^^^^^^^^
     * if you want to wait until a key is hit
     */

    if ((how > 0) && FD_ISSET(0, &readfds))
            return 1;
    else
            return 0;
}

void NCursesSupport::initColors()
{
    using color = id_space::COLOR_ID;

    init_pair(static_cast<int>(color::SPACE), COLOR_BLACK, COLOR_BLACK);
    init_pair(static_cast<int>(color::WALL), COLOR_BLACK, COLOR_BLUE);
    init_pair(static_cast<int>(color::FOOD), COLOR_YELLOW, COLOR_BLACK);
    init_pair(static_cast<int>(color::ENERGYZE), COLOR_YELLOW, COLOR_BLACK);
    init_pair(static_cast<int>(color::DOOR), COLOR_BLACK, COLOR_MAGENTA);

    init_pair(static_cast<int>(color::PLAYER), COLOR_YELLOW, COLOR_BLACK);
    init_pair(static_cast<int>(color::BLINKY), COLOR_RED, COLOR_BLACK);
    init_pair(static_cast<int>(color::INKY), COLOR_CYAN, COLOR_BLACK);
    init_pair(static_cast<int>(color::CLYDE), COLOR_CYAN, COLOR_BLACK);
    init_pair(static_cast<int>(color::PINKY), COLOR_GREEN, COLOR_BLACK);

    init_pair(static_cast<int>(color::DEFAULT_TEXT), COLOR_WHITE, COLOR_BLACK);
}

void NCursesSupport::drawChar(const position_space::Position& p, const appearance_space::ConsoleSymbolData& appearance)
{
    attron(COLOR_PAIR(appearance.colorId));
    mvaddch(p.y, p.x, appearance.symbol);
    attroff(COLOR_PAIR(appearance.colorId));
}
void NCursesSupport::drawText(const std::string& text, const position_space::Position& p, const appearance_space::ConsoleSymbolData& appearance)
{
    for(int i = 0; i < text.size(); ++i)
    {
        appearance_space::ConsoleSymbolData temp{text[i], appearance.colorId};
        drawChar(position_space::Position(p.x+i, p.y), temp);
    }
}
void NCursesSupport::drawRect(const position_space::Position& p, const std::vector<std::vector<char>>& rectData, const appearance_space::ConsoleSymbolData& appearance)
{
    for(int row = 0; row < rectData.size(); ++row)
    {
        for(int column = 0; column < rectData[row].size(); ++column)
        {
            if(int(rectData[row][column]) == 1)
            {
                drawChar(position_space::Position(p.x+column, p.y+row), appearance);
            }
        }
    }
}

void NCursesSupport::addSymbol(const std::string& appearanceName, const char symbol, const short foreground, const short background)
{
    static short colorId = 100;
    init_pair(colorId, foreground, background);

    appearance_space::ConsoleSymbolData temp {symbol, colorId};

    userAppearance.emplace(appearanceName, temp);
    ++colorId;
}

appearance_space::ConsoleSymbolData NCursesSupport::getAppearance(const std::string& appearanceName)
{
    return userAppearance[appearanceName];
}


/////////////////
// SHMHellper //
///////////////

std::map<std::string, int> SHMHellper::_nameFd;

void SHMHellper::createSHM(const std::string &shmName, const size_t size)
{
    size_t fd = shm_open(shmName.c_str(), O_CREAT | O_RDWR, 0777);
    if(fd == -1)
    {
        perror((shmName + " " + "fd").c_str());
        return;
    }

    _nameFd.emplace(shmName, fd);

    if(ftruncate(fd, size) == -1)
    {
        perror("sizing");
        return;
    }
}

void SHMHellper::connectSHM(const std::string &shmName)
{
    size_t fd = shm_open(shmName.c_str(), O_RDWR, 0777);
    if(fd ==  -1)
    {
        perror((shmName + " " + "fd").c_str());
        return;
    }

    _nameFd.emplace(shmName, fd);
}

SHMHellper::~SHMHellper()
{
    for(auto& pair: _nameFd)
    {
        shm_unlink(pair.first.c_str());
    }
}

position_space::Position CharacterShmWrapper::getPosition()
{
    return SHMHellper::getDataSHM<position_space::Position>(_shmName + shm_space::positionTag);
}

characters::DIRECTION CharacterShmWrapper::getDir()
{
    return SHMHellper::getDataSHM<characters::DIRECTION>(_shmName + shm_space::dirTag);
}

appearance_space::ConsoleSymbolData CharacterShmWrapper::getAppearance()
{
    return SHMHellper::getDataSHM<appearance_space::ConsoleSymbolData>(_shmName + shm_space::appearanceTag);
}

CharacterShmWrapper::CharacterShmWrapper(const std::string &shmName)
    : _shmName(shmName)
{
}
