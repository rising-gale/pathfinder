#include "libmx.h"
int mx_strcmp(const char *s1, const char *s2);
int mx_bubble_sort(char **arr, int size);
int mx_bubble_sort(char **arr, int size){
    int swaps=0;
    for (int i=0;i<size;i++)
        for (int j=0;j<size-i-1;j++){
            if(mx_strcmp(arr[j],arr[j+1])>0){
                char *tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                
                swaps++;
            }
        }
    return swaps;
}

// int main(){
//     char *arr[] = {"abc", "xyz", "ghi", "def"};
//     printf("%d",mx_bubble_sort(arr,4));
// }
