#include <stdlib.h>
#include <string.h>
#include "struct.h"

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

void print_page(int current_page) {

}