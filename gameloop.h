#ifndef RK1_GAMELOOP_H
#define RK1_GAMELOOP_H

#include "struct.h"
#include <windows.h>

void gameloop(int amount_of_pages, int time_limit, int max_errors, Page *pages, HANDLE hConsole);

#endif //RK1_GAMELOOP_H
