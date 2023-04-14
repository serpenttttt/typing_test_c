#ifndef RK1_FUNCTIONS_H
#define RK1_FUNCTIONS_H

#include "struct.h"

char *select_file(char *level);

Page *init_pages();

Page *create_page(int page_number, Page *pages);

void print_page(int current_page);

#endif //RK1_FUNCTIONS_H
