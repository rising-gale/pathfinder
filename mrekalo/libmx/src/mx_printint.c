#include "libmx.h"

void mx_printchar(char c);
void mx_printint(int n);
void mx_printint(int n)
{
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n == 2147483647) {
        write(1, "2147483647", 10);
        return;
    }
    if (n < 0){
        mx_printchar('-');
        n=-n;
    }
    if (n==0) mx_printchar('0');
    int num = n, divider=1;;
    while (num > 0){
        divider = divider*10;
        num=num/10;
    }
    divider = divider/10;
    while (divider >= 1){
        mx_printchar((n/divider)+'0');
        n=n%divider;
        divider = divider/10;
    }
    
}
