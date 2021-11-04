#include "libmx.h"
char *mx_strjoin(char const *s1, char const *s2);

char *mx_strjoin(char const *s1, char const *s2){
    if(s1==NULL && s2 == NULL) 
        return NULL;
    if(s1!=NULL && s2==NULL) 
        return mx_strdup(s1);
    else if(s1==NULL && s2!=NULL) 
        return mx_strdup(s2);
    char *s3 = mx_strnew(mx_strlen(s1)+ mx_strlen(s2));
    s3 = mx_strdup(s1);
    mx_strcat(s3,s2);
    return s3;
}
