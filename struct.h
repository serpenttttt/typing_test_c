#ifndef RK1_STRUCT_H
#define RK1_STRUCT_H

#define HEIGHT 5
#define WIDTH 45

typedef struct Element {
    char value;
    int color;
} Element;

typedef struct Page {
    Element text[HEIGHT][WIDTH];
} Page;

#endif //RK1_STRUCT_H
