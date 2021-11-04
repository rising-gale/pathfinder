#include "libmx.h"

int mx_count_words(const char *str, char c);
int mx_count_words(const char *str, char c){
    if(str == NULL)
        return -1;
    int count_words=0;
    int count_letters=0, i=0;
    while (str[i]!='\0'){
        if(str[i]==c){
            if(count_letters>0){
                count_words++;    
            }
            count_letters=0;
        } else count_letters++;
        i++;
    }
    if(count_letters>0 && str[i]=='\0'){
        count_words++;
    }
    return count_words;
}

// int main(){
//     char str[] = "  follow  *   the  white rabbit ";
//     printf("%d", mx_count_words(str,' '));
//     return 0;
// }
