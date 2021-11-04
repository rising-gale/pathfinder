#include "libmx.h"
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strncpy(char *dst, const char *src, int len){
    
    if(len >0){
        int i=0;
        while(i<len){
            dst[i]=src[i];
            i++;
        }
    }
    return dst;
}
