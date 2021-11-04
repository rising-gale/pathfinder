#include "libmx.h"


char *mx_strcat(char *restrict s1, const char *restrict s2){
    int str1len = mx_strlen(s1);
    int i=0;
    while (s2[i]!='\0'){
        s1[str1len+i]=s2[i];
        i++;
    }
    s1[str1len+i]='\0';
    return s1;
}

// int main(){
//     char s[] = "afafafghty";
//     char s1[] = "abcfd";   
//     mx_strcat(s1,s);
//     printf("%s",s1);
//     return 0;
// }
