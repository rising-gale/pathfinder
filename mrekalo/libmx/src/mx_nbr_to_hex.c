#include "libmx.h"

//#include <stdio.h>
char *mx_nbr_to_hex(unsigned long nbr){
    int n = nbr;
    // int size = 0;
    char *s = mx_strnew(100);
    int i=0;
    while(n>0){
        if(n%16 >= 10){
            s[i] = 87 + n%16;
        } else {
            s[i] = 48 + n%16;
        }
        i++;
        n = n/16;
    }
    s[i]='\0';
    int j = i-1;
    char *str = mx_strnew(j);
    i=0;
    while(s[i]!='\0'){
        str[i]=s[j];
        i++;
        j--;
    }
    free(s);
    return str;
}
// int main(){
//     int a = 1258;
//     printf("%s",mx_nbr_to_hex(a));
//     return 0;
// }

