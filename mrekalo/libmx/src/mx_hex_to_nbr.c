#include "libmx.h"

bool mx_isalpha(int c){
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

bool mx_islower(int c){
    return (c >=97 && c<=122);
}

bool mx_isdigit(int c){
    return (c >=48 && c <=57);
}

unsigned long mx_hex_to_nbr(const char *hex){
    int i=0;
    unsigned long decimal = 0;
    while(hex[i]!='\0')
        i++;
    i = i - 1;
    unsigned long base = 1;
    while (i>=0){
        if(mx_isdigit(hex[i])){
            decimal = decimal + (hex[i]-48) * base;
            
        }else if(mx_isalpha(hex[i])){
            if(mx_islower(hex[i])){
                decimal = decimal +(hex[i]-87) * base;
            } else {
                decimal = decimal +(hex[i]-55) * base;
            }
        }
        i--;
        base = base * 16;
    }
    return decimal;
}

// int main()
// {
//     printf("%d", mx_hex_to_nbr("ffffff"));

//     return 0;
// }
