/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:35:45 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 06:17:01 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "circular_list.h"
# include "libft.h"
# include "push_swap.h"
# include "utils.h"

/*
1. Modifying the Value (Content) of the First Element:
	If you only want to change the value stored at the first element (e.g.,
		change "ahmad" to "ALI"), you only need two pointers: char **argv.
	This is because you're modifying the content at the memory location,
		not the pointer's address itself.
	void change_value(char **argv)
	{
		argv[0] = "ALI";  // Just changing the value, not the memory address
	}
2. Allocating New Memory and Changing the Reference (Pointer Address):
If you want to allocate new memory and change the pointer's address itself (e.g.,
	pointing to a newly allocated memory),
	you need three pointers: char ***argv.
This is because you need to change the pointer's address in the calling function,
	which requires a pointer to the pointer (char ***argv).

void	allocate_new(char ***argv)
{
	*argv = malloc(2 * sizeof(char *));
		// Allocating new memory for the array of strings
	(*argv)[0] = strdup("ALI");
		// Allocating and setting the first string
	(*argv)[1] = NULL;                   // Null-terminating the array
}

*/
int			push_swap(int *argc, char **argv[]);
/*
- argv is of type char ***, so **argv is of type char *.
- But input is declared as: 	char **input;
		-> This means it expects a char **, not a char *.
*/
int			process_pushswap_data(t_stacks **stacks, t_utils_helpers **helpers,
				int *argc, char ***argv);
t_stack		*init_stack(void);
short		init_stacks_a_b(t_stacks *stacks);
short		init_helpers(t_utils_helpers **helpers);
/*
1. *stacks = ft_calloc(1, sizeof(t_stacks));
	- We are changing the value stored in the pointer,
		which is an address (*stacks).
	- We are not changing the address of the pointer itself.
	- The pointer still lives in the same place in memory;
	 we're just updating where it points.
			So, after calling ft_calloc,
				the memory for 
				stacks (of type t_stacks) will look like this:
				stacks->a.head = NULL;
				stacks->a.tail = NULL;
				stacks->a.size = 0;

				stacks->b.head = NULL;
				stacks->b.tail = NULL;
				stacks->b.size = 0;
			But,
				since a.head and a.tail will point to dynamic list nodes
				(which themselves are dynamically allocated),
				you need to separately allocate memory for these nodes.
*/
short		initialize_ps(t_stacks **stacks, t_utils_helpers **helpers);
void		del_node_data(void *data);
int			terminate_ps(t_stacks *stacks, t_utils_helpers *helpers);
short		prepare_strs_handler(t_utils_helpers *helpers);
short		run_validation_checks(t_stack *list, __int128_t nbr);
short		extract_nbrs_process(t_stacks *stacks, t_utils_helpers *helpers);
void		print_visual_1stack(t_stack *stack, char *stack_name);
void		print_visual_2stacks(t_stack *a, char *na, t_stack *b, char *nb);
/*
|= is a bitwise operation that specifically sets bits in the bitmask.

If you do +=, you might add the same value multiple times
and end up with a number that does not simply represent “set that bit.”
 For instance, if flags already has the bit set,
  adding again will increase the numeric value incorrectly.
   Bitwise OR ensures that once a bit is set, it stays set,
	without messing up other bits.
*/
void		turk_set_flag(t_turk_algo_data *tad, t_stack_flags flag);
/*
&= is the bitwise AND assignment operator.

~flag is the bitwise NOT of flag. The bitwise NOT inverts all bits in flag.
Means:
1. Take ~flag (which has all bits flipped relative to flag),
2. (AND &) that with the current tad->flags.
If			flag = 0b0010 (2 in decimal, in a small 4‐bit world),
				then ~flag = 0b1101.

This effectively clears (unsets) the bits that flag represents.

-= is arithmetic subtraction.
If you subtract the numeric value of flag from tad->flags,
you might accidentally affect bits that shouldn’t be touched;
;;or even produce negative numbers (depending on the initial value of flags).
It does not reliably turn off specific bits.
In a typical 32‐bit integer,
 flag = 2 is actually 00000000 00000000 00000000 00000010 in binary,
		so ~flag becomes 11111111 11111111 11111111 11111101.
*/
void		turk_unset_flag(t_turk_algo_data *tad, t_stack_flags flag);
/*
& is the bitwise AND operator.
(tad->flags & flag) != 0 checks 
if at least one of the bits in flag is also set in tad->flags.
If that result is nonzero, it means the bit(s) you care about are set.
*/
short		turk_has_flag(const t_turk_algo_data *tad, t_stack_flags flag);
/*
** get_node_value:
** Assumes that node->data_s.data.as_ptr points to an int.
*/
int			get_node_value(t_list_node *node);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
/*
Takes an operation of type t_stacks_oprs
and performs the corresponding move on the any stack depending on the operation.
*/
void		perform_ps_operations(t_stacks_oprs op, t_stacks *stacks);
/*
** read_update_indices:
** Updates node indices in the circular list 
and returns the length of the stack :)
*/
long		read_update_indices(t_stack *stack);
long		read_stack_length(t_stack *stack);
/*
** get_ptr_int:
** Returns the integer value stored in the given node.
** Assumes the value is stored as a pointer to int in data_s.data.as_ptr.
*/
int			get_ptr_int(t_list_node *node);
/*
** sort_two:
** Sorts a stack with exactly two nodes.
** If the first node's integer is greater than the second's, it swaps them.
*/
void		sort_two(t_stack *a);
t_list_node	*find_max_node(t_stack *stack);
void		sort_three(t_stack *a);
/*
** find_min_index:
** Returns the index of the node with the smallest integer in stack A.
** Iterates the circular list using only while loops.
*/
long		find_min_data_index(t_stack *stack);
void		sort_five(t_stacks *stacks);
/*
- Will loop refresh all stack (a) indices.
- Will loop refresh all stack (b) indices.
- Will calculate middle point of (a) & (b) in struct.
*/
void	refresh_stacks_all(t_stacks *stacks);
t_list_node *find_target_node(t_list_node *a_node, t_stack *b);
long	compute_push_cost(t_list_node *a_node, t_list_node *b_target, t_stacks *s);

#endif