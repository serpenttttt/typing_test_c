#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <stdio.h>
#include "functions.h"

char *select_file(char *level) {
    strcat(level, ".txt");
    return level;
}

Page *init_pages() {
    Page *pages; // указатель на динамический массив страниц
    pages = (Page *) malloc(sizeof(Page) * 1);
    return pages;
}

Page *create_page(int page_number, Page *pages) {
    pages = (Page *) realloc(pages, sizeof(Page)*(page_number + 2));
    return pages;
}

void print_page(int current_page, Page *pages, HANDLE hConsole) {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH && pages[current_page].text[i][j].value != '\0'; ++j) {
            // Дефолтный цвет
            if (pages[current_page].text[i][j].color == 0) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                printf("%c", pages[current_page].text[i][j].value);
            }
            // Зеленый цвет
            if (pages[current_page].text[i][j].color == 1) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                printf("%c", pages[current_page].text[i][j].value);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
            }
            // Красный цвет
            if (pages[current_page].text[i][j].color == 2){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("%c", pages[current_page].text[i][j].value);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
            }
        }
        printf("\n");
        if (i + 1 == HEIGHT && pages[current_page].text[i][j].value != '\0') return ;
    }
}

void show_res(int correct_characters, int incorrect_characters, int words, double time) {
    system("cls");
    printf("\n- You've entered %d correct symbols\n", correct_characters);
    printf("\n- You've entered %d incorrect symbols\n", incorrect_characters);
    printf("\n- You've entered %d symbols\n", correct_characters + incorrect_characters);

    //Добавить отсчет времени
    printf("\n- Your average speed is %d symbols per minute\n", (correct_characters + incorrect_characters)/time*60);
    printf("\n- Your average speed is %d words per minute\n", words/time*60);
}