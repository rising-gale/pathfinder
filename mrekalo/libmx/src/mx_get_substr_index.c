#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub){
    const char *p=str;
    int len2=mx_strlen(sub);
    int len1 =mx_strlen(str);
    if (str==NULL || sub == NULL)
        return -2;
    for(int count = 0; count < len1 ;p++, count++)
        if(mx_strncmp(p,sub,len2)==0)
            return count;
    return -1;
}

// int main(){
//     char s[] = "abcdfeghn";
//     char s1[] = "f";
//     printf("%d",mx_get_substr_index(s,s1));
//     return 0;
// }
