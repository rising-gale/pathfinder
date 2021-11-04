#include "libmx.h"

char *mx_itoa(int number){
    int sign = 0;
    int n = number;
    if(n < 0){
        sign = 1;
        if(n == -2147483648)
            n++;  
        n = n * -1;
    }
    int count = 0;
    while(n > 0){
        n = n /10;
        count++;
    }
    // printf("%d",count);
    char *s = NULL;
    if(sign == 0)
        s = mx_strnew(count);
    else 
    {
        s = mx_strnew(count+1);
        s[count] = '-';
    }
    if (number == 0)
		return mx_strcpy(s, "0");
	if (number == -2147483648)
		return mx_strcpy(s, "-2147483648");
    if(number < 0)
        number = number*-1;
    int i = 0;
    while (i < count){
        s[i] = number % 10 + '0';
        // printf("%c",s[i]);
        number = number / 10;
        i++;
    }
    // printf("%s",s);
    mx_str_reverse(s);
    // printf("%s",s);
    return s;
}

// int main(){
//     char *str = mx_itoa(-228);
//     printf("%s",str);
//     return 0;
// }
