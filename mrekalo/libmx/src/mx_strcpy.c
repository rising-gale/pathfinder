#include "libmx.h"
char *mx_strcpy(char *dst, const char *src);
char *mx_strcpy(char *dst, const char *src){
    int i=0;
    while (src[i]!='\0'){
        dst[i] = src[i];
        i++;
    }
    dst[i]='\0';
    return dst;
}

// int main(){
//     char str[] = "agag";
//     const char *s = str;
//     char *new_str; 
//     printf("%s",mx_strcpy(new_str, s));
//     return 0;
// }
