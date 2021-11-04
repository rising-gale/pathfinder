#include "libmx.h"


void mx_print_strarr(char **arr, const char *delim){
    int i = 0;
    if(arr == NULL || delim == NULL)
        return;
    while(arr[i]!=NULL){
        int len = mx_strlen(arr[i]);
        write(1, arr[i], len);
        if(arr[i+1]!=NULL)
            write(1, &delim, 1);
        i++;        
    }
    mx_printchar('\n');
}
