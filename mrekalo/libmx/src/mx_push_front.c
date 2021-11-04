#include "libmx.h"

void mx_push_front(t_list **list, void *data){
    if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    t_list * new_node = mx_create_node(data);
    new_node->next = *list;
    *list = new_node;
}


// int main(){
//     void *data;
//     t_list *head = mx_create_node(data);
//     head->next = mx_create_node(data);
//     mx_push_front(&head, data);
//     return 0;
// }
