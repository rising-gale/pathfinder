#include "libmx.h"

char *mx_file_to_str(const char *file){
    char ch;
    int file_to_read = open(file, O_RDONLY);
    if(file_to_read < 0){
        return NULL;
    }
    int counter = 0;
    while (read(file_to_read, &ch, 1)){
        counter++;   
    }
    close(file_to_read);
    file_to_read = open(file, O_RDONLY);
    if(file_to_read < 0){
        return NULL;
    }
    if(counter == 0)
        return NULL;
    char *s = mx_strnew(counter);
    int i = 0;
    while (read(file_to_read, &ch, 1)){
        s[i] = ch;
        i++;
    }
    s[i]='\0';
    close(file_to_read);
    return s;
    
}

// int main(){
//     char *s = "test.txt";
//     printf("%s",mx_file_to_str(s));
//     return 0;
// }
