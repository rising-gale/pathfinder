#include "libmx.h"

void mx_pop_front(t_list **head){
    t_list *next_node = NULL;
    if(head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
    }else {
        next_node = (*head)->next;
        free(*head);
        *head = next_node;        
    }
}
