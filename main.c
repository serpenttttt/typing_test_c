// .\cmake-build-debug\rk1.exe easy 6 10
#include <stdio.h>
#include <stdlib.h>
#include "validate_params.h"
#include <time.h>
#include "functions.h"
#include "struct.h"

#define HEIGHT 5
#define WIDTH 45


int main(int argc, char *argv[]) {
    int time_limit, max_errors;
    char character;

    if (!validate_params(argc, argv)) {
        FILE *help;
        help = fopen("help.txt", "r");
        while ((character = getc(help)) != EOF) {
            printf ("%c", character);
        }
        fclose(help);
        return -1;
    }

    time_limit = atoi(argv[2]);
    max_errors = atoi(argv[3]);

    // создаём указатель на файл и открываем его
    FILE *file_with_text;
    file_with_text = fopen(select_file(argv[1]), "r");

    Element *text[HEIGHT][WIDTH];

    // перезапись в структуру
    character = getc(file_with_text);
    for (int k = 0; character != '\0'; ++k) {

        for (int i = 0; i < HEIGHT || character != '\0'; ++i) {
            for (int j = 0; j < WIDTH || character != '\0'; ++j) {
                puts()
            }

        }

    }

    // заполняем массив, проверяем конец строки, но новую, если строки закончились, то добавляем страницу

    // закрытие файла
    fclose(file_with_text);


    int count_errors = 0;

    long int start;
    long int now;

    // Считываем текущее время
    start = (int) time (NULL);
    now = (int) time (NULL);

    while ((time_limit > now - start) && count_errors <= max_errors) {
        now = (int) time (NULL);
    }

    // статистика

    return 0;
}
