#include "libmx.h"

int mx_count_substr(const char *str, const char *sub){
    const char *p=str;

    if (str == NULL || sub == NULL)
        return -1;
    // if (sub[0])
    //     return 0;

    int len2=mx_strlen(sub);
    if(len2 == 0)
        return 0;
    int len1 =mx_strlen(str);
    int count = 0;
    for(int i = 0; i < len1 ;p++, i++)
        if(mx_strncmp(p,sub,len2)==0){
            count++;
            // printf("%d",count);
        }
            
    return count;
}

// int main(){
//     char str[] = "yo, yo, yo Neo";
//     char sub[] = "yo, yo, yo Neo ";
//     printf("%d", mx_count_substr(str,sub));
//     printf("%c", '\n');
//     printf("%d", mx_count_substr(str,NULL));
//     printf("%c", '\n');
//     printf("%d", mx_count_substr(NULL,sub));
//     printf("%c", '\n');
//     // sub = "";
//     // printf("%d", mx_count_substr(str,sub));
//     return 0;
// }
