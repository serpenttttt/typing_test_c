#include "gameloop.h"
#include <time.h>
#include <conio.h>
#include "functions.h"

void gameloop(int amount_of_pages, int time_limit, int max_errors) {
    int count_errors = 0;
    int current_page = 0;

    clock_t start, now;

    // Считываем текущее время
    start = clock();
    now = start;

    print_page(current_page);
    while ((time_limit > (now - start) / CLK_TCK) && count_errors <= max_errors && current_page < amount_of_pages) {
        if (kbhit()) {


            print_page();
        }
        else now = clock();
    }
}