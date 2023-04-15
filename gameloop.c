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

    // Для начала ввода и текущего времени
    clock_t start, now;

    // Считываем текущее время и время начала
    start = clock();
    now = start;
    int i = 0, j = 0;
    // Выводим страницу
    print_page(current_page, pages, hConsole, i, j);
    // В цикле проходим по структуре страниц
    while ((time_limit > (now - start) / CLK_TCK) && count_errors <= max_errors && current_page < amount_of_pages &&
        pages[current_page].text[i][j].value != '\0') {
        // Если кнопка была нажата
        if (kbhit()) {
            button = getch();
            // Если дошли до конца строки, ты пытаемся перейти на новую
            if (j == WIDTH) {
                // Переходим на следующую страницу, если закончились строки на первой
                if(i + 1 == HEIGHT) {
                    current_page += 1;
                    i = 0;
                } else // Переходим на следующую строку
                    i += 1;
                j = 0; // Переходим на первый элемент в строке
            }
            // Если символ нажатой кнопки совпал с символом в структуре
            if (button == pages[current_page].text[i][j].value) {
                pages[current_page].text[i][j].color = 1; // 1 - зеленый
                if (button == ' ')
                    words += 1;
                correct_characters += 1;
            }
            // Если символ нажатой кнопки не совпал с символом
            else {
                pages[current_page].text[i][j].color = 2; // 2 - красный
                count_errors += 1; // Считаем ошибку
            }
            // Чистим терминал
            system("cls");

            // Переходим на следующий символ в строке
            j += 1;

            // Отрисовываем страницу
            print_page(current_page, pages, hConsole, i, j);
        }
        else now = clock(); // Обновляем значение now
    }

    // Время игры
    double test_time = difftime(now, start);

    // Показыаем результат пользователю
    show_res(correct_characters, count_errors, words, test_time);
}