#include "libmx.h"
int mx_strncmp(const char *s1, const char *s2, int n);
int mx_strncmp(const char *s1, const char *s2, int n){
    if(n==0)
        return 0;
    int i=0;
    while(i<n){
        if(s1[i]>s2[i]){
            return s1[i] - s2[i];
        } else if(s1[i]<s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}
