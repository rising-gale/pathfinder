#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    int len1 = mx_strlen(str);
    int len2 = mx_strlen(sub);
    int len3 = mx_strlen(replace);
    if(str == NULL || sub == NULL)
        return NULL;
    if(replace == NULL){
        return NULL;
    }
    char *new_str = mx_strdup(str);
    char *new_str2 = new_str;
    int index_substr = mx_get_substr_index(new_str,sub);
    // int k = 0;
    while(index_substr > 0){
        // printf("%s",new_str);
        // printf("%d",index_substr);
        index_substr = mx_get_substr_index(new_str2,sub);
        char *str_copy =  mx_strdup(new_str2);
        len1 = mx_strlen(str_copy);
        // printf("%d",len1);
        if(index_substr == -1){
            free(str_copy);
            new_str = new_str2;
            break;
        }
            
        free(new_str2);
        new_str2 = mx_strnew((index_substr + 1) + (len1 - (index_substr + len2)) + len3);
        // printf("%d",mx_strlen(new_str));
        int j = 0;
        for (int i = 0; i < index_substr; i++)
        {
            new_str2[j] = str_copy[i];
            // printf("%c",new_str);
            j++;
        }
        for (int i = 0; i < len3; i++)
        {
            new_str2[j] = replace[i];
            // printf("%c",new_str);
            j++;
        }
        for (int i = index_substr + len2; i < len1; i++)
        {
            new_str2[j] = str_copy[i];
            // printf("%c",new_str);
            j++;
        }
        free(str_copy);        
    }
    
    return new_str;
    
}

// int main(){
//     for (int i = 0; i < 999999; i++)
//     {
//         char *s = mx_replace_substr("McaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonaldsMcaldsDonalds", "alds", "uts");
//         printf("%s", s);
//         free(s);
//     }
    
    
//     return 0;
// }
