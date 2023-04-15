#include "gameloop.h"
#include <time.h>
#include <conio.h>
#include "functions.h"
#include <stdlib.h>

void gameloop(int amount_of_pages, int time_limit, int max_errors, Page *pages, HANDLE hConsole) {
    // Для статистики
    int count_errors = 0, correct_characters = 0, words = 0;

    int current_page = 0;
    int button;

    clock_t start, now;

    // Считываем текущее время
    start = clock();
    now = start;
    int i = 0, j = 0;
    print_page(current_page, pages, hConsole, i, j);
    while ((time_limit > (now - start) / CLK_TCK) && count_errors <= max_errors && current_page < amount_of_pages &&
        pages[current_page].text[i][j].value != '\0') {
        if (kbhit()) {
            button = getch();
            if (j == WIDTH) {
                if(i + 1 == HEIGHT) {
                    current_page += 1;
                    i = 0;
                } else
                    i += 1;
                j = 0;
            }
            if (button == pages[current_page].text[i][j].value) {
                pages[current_page].text[i][j].color = 1; // 1 - зеленый
                if (button == ' ')
                    words += 1;
                correct_characters += 1;
            } else {
                pages[current_page].text[i][j].color = 2; // 2 - красный
                count_errors += 1;
            }
            system("cls");

            j += 1;

            print_page(current_page, pages, hConsole, i, j);
        }
        else now = clock();
    }

    double test_time = difftime(now, start);

    show_res(correct_characters, count_errors, words, test_time);
}