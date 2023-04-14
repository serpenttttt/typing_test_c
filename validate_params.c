#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool validate_params(int argc, char **argv) {
    if (strcmp(argv[1], "easy") == 0 || strcmp(argv[1], "medium") == 0 || strcmp(argv[1], "hard") == 0) {
        if (4 < atoi(argv[2]) && atoi(argv[2]) < 181) {
            if (!(0 < atoi(argv[3]) && atoi(argv[3]) < 31)){
                puts("\nInvalid parameter <max_errors>! It must not to be less than 3 and higher than 30 errors!\n");
                return false;
            }
        } else {
            puts("\nInvalid parameter <max_time>! It must not to be less than 5 and higher than 180 seconds!\n");
            return false;
        }
    } else {
        puts("\nInvalid parameter <level>! It must be <easy> or <medium> or <hard>!\n");
        return false;
    }
    return true;
}

