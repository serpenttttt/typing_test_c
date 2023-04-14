#include "gameloop.h"
#include <time.h>
#include <conio.h>
#include "functions.h"
#include <stdlib.h>

#include <stdio.h>

void gameloop(int amount_of_pages, int time_limit, int max_errors, Page *pages) {
    int count_errors = 0;
    int current_page = 0;

    clock_t start, now;

    // Считываем текущее время
    start = clock();
    now = start;
    puts("before");
    print_page(current_page, pages);
    puts("after");
    while ((time_limit > (now - start) / CLK_TCK) && count_errors <= max_errors && current_page < amount_of_pages) {
        if (kbhit()) {

            system("cls");
            print_page(current_page, pages);
        }
        else now = clock();
    }
}