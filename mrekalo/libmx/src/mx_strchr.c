#include "libmx.h"
char *mx_strchr(const char *s, int c);
char *mx_strchr(const char *s, int c){
    do{
        if(*s==(char)c){
            return (char*)s;
        }       
    }while(*s++);
    return 0;
}
