#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    for (size_t i = 0; i < n; i++){
        if(((unsigned char *)src)[i] != (char)c)
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        else
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            return dst;
        }
            
    }
    return NULL;
}

// int main(){
//        // Массив источник данных
//    unsigned char src[15]="1234567890";

//    // Массив приемник данных
//    unsigned char dst[15]="";

//    // Копируем данные из массива src в массив dst
//    mx_memccpy (dst, src,'g', 4);

//    // Вывод массива dst на консоль
//    printf ("dst: %s\n",dst);
//     return 0;
// }
