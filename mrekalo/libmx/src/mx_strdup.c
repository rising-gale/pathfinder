#include "libmx.h"

char *mx_strdup(const char *str){
    int len = mx_strlen(str);
    char *strcopy = mx_strnew(len);
    mx_strcpy(strcopy, str);
    return strcopy;
}
