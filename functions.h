#ifndef RK1_FUNCTIONS_H
#define RK1_FUNCTIONS_H

#include "struct.h"
#include <windows.h>

char *select_file(char *level);

Page *init_pages();

Page *create_page(int page_number, Page *pages);

void print_page(int current_page, Page *pages, HANDLE hConsole);

void show_res(int correct_characters, int incorrect_characters, int words, double time);

#endif //RK1_FUNCTIONS_H
