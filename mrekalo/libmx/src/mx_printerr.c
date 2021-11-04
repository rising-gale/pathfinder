#include "libmx.h"

void mx_printerr(const char *s) {
    if(s == 0) return;
    int len = mx_strlen(s);
    write(2, s, len);
}

