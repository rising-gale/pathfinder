#include "libmx.h"

t_list *mx_create_node(void *data){
    t_list *created_node = (t_list*)malloc(16);
    created_node -> next = NULL;
    created_node -> data = data;
    return created_node;
}
