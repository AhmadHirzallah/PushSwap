#ifndef CIRCULAR_STACK_H
# define CIRCULAR_STACK_H

# include "circular_list.h"

typedef struct s_stack
/*
Understand :     ((  void (*del)(void *);  )) : 
In C, function pointers work a bit differently than normal pointers.
You don't need to use an asterisk (*) when assigning a function pointer.
The name of the function itself acts as a pointer to the function's address in memory.

Works As : (stack->del = del_node_data;)
Same as doingstack->del = &del_node_data;
But the & is optional because the function name already represents its memory address.

When Do You Use *?
You use * when declaring the function pointer: void (*del)(void *);  // Declaration with *
You don't use * when assigning it:  stack->del = del_node_data;
*/
{
    t_circular_lst list;
    void (*del)(void *);
}                       t_stack;

t_stack *create_circ_stack(void (*del)(void *));
void destroy_circ_stack(t_stack *s);
short push_circ_stack(t_stack *s, void *data);
short push_circ_stack_end(t_stack *s, void *data);
void *pop_circ_stack(t_stack *s);
void *peek_circ_stack(const t_stack *s);
size_t get_circ_stack_size(const t_stack *s);
short is_circ_stack_empty(const t_stack *s);
void clear_circ_stack(t_stack *s);
void swap_stack_top_2(t_stack *s);
void rotate_circ_stack(t_stack *s);
void rev_rotate_circ_stack(t_stack *s);
short circ_stack_iter_on_data(t_stack *s, int (*f)(void *));
t_stack *circ_stack_clone(t_stack *s, void *(*copy)(void *), void (*del)(void *));
/*
** remove_top_node:
**   - If the stack is empty, returns NULL.
**   - Otherwise, removes the head node from s->list and returns it.
**   - Does not free the node’s data.
*/
t_list_node *circ_stck_remove_top_node(t_stack *s);
/*
** insert_top_node:
**   - Inserts 'node' at the beginning of s->list.
**   - Updates head, tail, and size accordingly.
*/
void circ_stck_insert_node_at_top(t_stack *s, t_list_node *node);
/*
** push_stack:
**   - Removes the top node from src and inserts it at the top of dest.
**   - This function is modular and leverages remove_top_node() and insert_top_node().
*/
void	circ_stck_push_stack(t_stack *dest, t_stack *src);

#endif