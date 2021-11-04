#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    const unsigned char *str = s;
    for (size_t i = n-1; i != 0; i--)
    {
        // printf("%c", str[i]);
        if(str[i] == (char) c)
            return (void *)(str+i);
    }
    return NULL;
}

// int main(){
//        // Исходный массив
//    unsigned char src[15]="12345678904";
//    // Переменная, в которую будет сохранен указатель
//    // на искомый символ.
//    char *sym;

//    // Вывод исходного массива
//    printf ("src old: %s\n",src);

//    // Поиск требуемого символа
//    sym = mx_memrchr (src, '4', 10);

//    // Если требуемый символ найден, то заменяем его
//    // на символ '!'
//    if (sym != NULL)
//       sym[0]='!';

//    // Вывод исходного массива
//    printf ("src new: %s\n",src);
//    printf ("%s",mx_memrchr("Trinity", 'i', 7));
//     return 0;
// }
