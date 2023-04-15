// .\cmake-build-debug\rk1.exe easy 6 10
#include "validate_params.h"
#include "functions.h"
#include "struct.h"
#include "gameloop.h"
#include <windows.h>

int main(int argc, char *argv[]) {
    system("cls"); // Очистка терминала

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получение дескриптора стандартного вывода
    SetConsoleCursorInfo(hConsole, &(CONSOLE_CURSOR_INFO) {100, 0}); // Прозрачность

    int time_limit, max_errors; // Переменные для лимита времени и лимита ошибок
    char character; // Переменная, куда записывается символ, используется при чтении файлов, записи текста в структуру страницы

    // Проверка параметров, которые были переданы в программу. В случае непрохождения - ошибка и вывод help из файла help.txt
    if (!validate_params(argv)) {
        FILE *help;
        help = fopen("help.txt", "r");
        while ((character = getc(help)) != EOF) {
            printf ("%c", character);
        }
        fclose(help);
        return -1;
    }

    // Запись переданных значений после их проверки
    time_limit = atoi(argv[2]);
    max_errors = atoi(argv[3]);

    // Создаём указатель на файл и открываем его
    FILE *file_with_text;
    file_with_text = fopen(select_file(argv[1]), "r");

    // Создаем указатель на динамический массив из типа данных Page, пока что там будет 1 страница. (До того момента, пока она не заполнится)
    Page *pages = init_pages();

    // Перезаписываем в структуру
    character = ' '; //
    int i, j, amount_of_pages = 1;
    for (int page_number = 0; character != EOF; ++page_number) {
        // Перебираем строки
        for (i = 0; i < HEIGHT && character != EOF; ++i) {
            // Перебираем символы
            for (j = 0; j < WIDTH && (character = getc(file_with_text)) != EOF; ++j) {
                pages[page_number].text[i][j].value = character;
                pages[page_number].text[i][j].color = 0;   // 0 -- дефолтный цвет
            }
            // Если встречаем конец файла, то записываем '\0'
            if (character == EOF) {
                if (j < WIDTH) pages[page_number].text[i][j].value = '\0';
                else if ((i + 1) < HEIGHT) pages[page_number].text[i + 1][0].value = '\0';
            }
        }

        // Создаем новую страничку
        if ((i + 1) >= HEIGHT && character != '\0') {
            pages = create_page(page_number, pages);
            amount_of_pages = amount_of_pages + 1;
        }
    }

    // Закрытие файла
    fclose(file_with_text);

    // Цикл игры
    gameloop(amount_of_pages, time_limit, max_errors, pages, hConsole);

    return 0;
}
