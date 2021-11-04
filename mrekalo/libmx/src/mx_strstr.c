#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle);
char *mx_strstr(const char *haystack, const char *needle){
    const char *p=haystack;
    int len2=mx_strlen(needle);
    int len1 =mx_strlen(haystack);
    for(int count = 0; count < len1 ;p++, count++)
        if(mx_strncmp(p,needle,len2)==0)
            return (char *)p;
    return 0;
}

// int main(){
//     char s[] = "abcdfeghnAYKRnB8YfagrqjgknhFM815759AYKRn B8Yt";
//     char s1[] = "AYKRn B8Y";
//     printf("%s",mx_strstr(s,s1));
//     return 0;
// }
