#ifndef CIRCULAR_STACK_H
# define CIRCULAR_STACK_H

# include "circular_list.h"

typedef struct s_stack
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

#endif