#include "libmx.h"



int count_space_before(const char *str, int length){
    int count=0;
    for (int i=0; i < length; i++){
        if(mx_isspace(str[i])){
            count++;
        } else{
            break;
        }
    }
    return count;
}
int count_space_after(const char *str, int length){
    int count=0;
    for (int i=length-1; i >= 0; i--){
        if(mx_isspace(str[i])){
            count++;
        } else{
            break;
        }
    }
    return count;
}
char *mx_strtrim (const char *str);
char *mx_strtrim (const char *str){
    if(str==NULL)
        return NULL;
    int len = mx_strlen(str);
    int spaces_before = count_space_before(str,len);
    int spaces_after = count_space_after(str,len);
    int new_len = len - spaces_after - spaces_before;
    if(len <= 0)
        return NULL;
    char *new_str = mx_strnew(new_len);
    int j=0;
    for (int i=spaces_before;i<len-spaces_after;i++){
        new_str[j]=str[i];
        j++;
    }
    return new_str;
}

// int main(){
//     char name[] = "\f  My name... is Neo  \t\n ";
//     printf("%s",mx_strtrim(name));

//     return 0;
// }
