#include "libmx.h"

int mx_sqrt(int x){
    if(x<0)
        return 0;
    for (int i=2; i<=x/2; i++){
        if(x==i*i){
            return i;
        }
    }
    return 0;
}
