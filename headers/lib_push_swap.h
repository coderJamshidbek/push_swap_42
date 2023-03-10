/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 08:03:28 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 11:27:39 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>

# include "../libft_42/libft.h"

# define SORTED 0
# define NON_NUMERIC 1
# define DUPLICATE 2
# define RANGE 3
# define ARGC 4
# define MALLOC 5

typedef struct s_node
{
	struct s_node	*next;
	int				index_sorted;
	int				num;
}t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}t_stack;

// push_swap.c

// check_array.c
int		nb_of_agrs_check(int argc);
void	array_check(long *array, int size);

// errors.c
void	exit_with_msg(int error_index);

// init_stack.c
t_stack	*get_empty_stack(void);
t_stack	*get_stack_a(long *array, int size);

// node
t_node	*get_new_node_with_num(int num);

// parse.c
int		get_num_of_ints(int argc, char **argv);
long	*get_long_arr_from_input(int argc, char **argv);

// sort_array.c
int		get_index(long *arr, int size, int num);
void	bubble_sort_array(long *array, int size);

// sort_utils.c
int		is_sorted(t_stack *stack);
int		get_min_index(t_stack *stack);
int		count_rotations_to_top(t_stack *stack, t_node *node);
int		count_rotations_to_down(t_stack *stack, t_node *node);

// sort_utils_2.c
t_node	*get_max_node(t_stack *stack);
t_node	*get_min_node(t_stack *stack);

// sort.c
void	sort(t_stack *stack_a, t_stack *stack_b);

// k_sort.c
void	k_sort1(t_stack *stack_a, t_stack *stack_b);
void	k_sort2(t_stack *stack_a, t_stack *stack_b);

// utils.c
void	print_array(long *array, int size);
void	print_node_num(t_node *node);
void	print_node_index(t_node *node);
void	print_node(t_node *node);
void	print_nodes(t_node *head, int include_ind);

// free_stack.c
void	free_stack(t_stack *stack);

// pop_stack.c
t_node	*pop_stack(t_stack *stack);
t_node	*pop_last(t_stack *stack);

// print_stack.c
void	print_stack(t_stack *stack, int incl_index);

// push_stack.c
void	push_to_from(t_stack *stack_1, t_stack *stack_2, char *msg);
void	push_head(t_stack *stack, t_node *node);
void	push_tail(t_stack *stack, t_node *node);

// rotate_stack.c
void	rotate_stack(t_stack *stack, char *msg);
void	reverse_rotate_stack(t_stack *stack, char *msg);

// swap_stack.c
void	swap_stack(t_stack *stack, char *msg);

#endif