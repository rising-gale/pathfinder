#include "libmx.h"

int mx_get_char_index(const char *str, char c);
int mx_get_char_index(const char *str, char c){
    int i = 0;
    int res = -1;
    if(!str || str[0]=='\0'){
        res = -2;
        return res;
    }
    while(str[i]!='\0'){
        if(str[i] == c){
            res = i;
            return res;
        }   
        i++;
    }
    return res;
}

// int main(){
//     char c = 'l';
//     char *s = "";
//     printf("%d",mx_get_char_index(s,c));
//     return 0;
// }
