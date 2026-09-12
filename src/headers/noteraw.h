#ifndef NOTEFILE_H
#define NOTEFILE_H
#include <stdio.h>
#include <stdlib.h>

static inline void ekraniSil(void) {
    printf("\033[2J\033[1;1H\033[3J");

}
#endif