#include <stdio.h>
#include "util.h"

void clear(void) {
    printf("\x1b[H\x1b[2J");
}
