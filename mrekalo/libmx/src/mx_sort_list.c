#include "libmx.h"

void swap(void **a, void **b)
{
    void *temp = *a;
    *a = *b;
    *b = temp;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)){
        if(list == NULL || cmp == NULL)
            return NULL;
        for (t_list *temp1 = list; temp1; temp1 = temp1->next)
            for (t_list *temp2 = list; temp2->next; temp2 = temp2->next)
                if (cmp(temp2->data, temp2->next->data))
                    swap(&temp2->data, &temp2->next->data);  
        return list;
}
