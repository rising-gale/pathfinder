#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
    size_t len = mx_strlen(s1);
    if(len <= n){
        return mx_strdup(s1);
    }
    char *strcopy = mx_strnew(len);
    mx_strncpy(strcopy, s1, n);
    return strcopy;
}

// int main(){
//     char *s = "01234567890";
//     char *s1 = mx_strndup(s,1);
//     printf("%s",s1);
//     return 0;
// }
