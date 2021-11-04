#include "libmx.h"

char *mx_del_extra_spaces(const char *str){
    if(str == NULL)
        return NULL;
    char *strtrimmed = mx_strtrim(str);
    int i=0, j = 0;
    char *words = mx_strnew(mx_strlen(strtrimmed));
    while(strtrimmed[i]!='\0'){
        if(!mx_isspace(strtrimmed[i])){
            words[j] = strtrimmed[i];
            j++;
        } else if (mx_isspace(strtrimmed[i]) && !mx_isspace(strtrimmed[i+1])){
            words[j]=' ';
            j++;
        }
        i++;
    }
    mx_strdel(&strtrimmed);
    return words;
}
