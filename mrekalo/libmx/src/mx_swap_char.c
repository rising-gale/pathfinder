#include "libmx.h"
void mx_swap_char(char *s1, char *s2);
void mx_swap_char(char *s1, char *s2){
    if(!s1 || !s2)
        return;
    char temp = *s1;
    *s1=*s2;
    *s2=temp;
}

// int main(){
//     char str[] = "ONE";
//     printf("%s",str);
//     mx_swap_char(&str[0], &str[1]); //'str' now is "NOE"
//     printf("%s",str);
//     mx_swap_char(&str[1], &str[2]); //'str' now is "NEO"
//     printf("%s",str);
//     return 0;
// }
