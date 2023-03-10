/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:53 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/27 08:03:52 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	nb_of_agrs_check(argc);
	size = get_num_of_ints(argc, argv);
	array = get_long_arr_from_input(argc, argv);
	array_check(array, size);
	stack_a = get_stack_a(array, size);
	free(array);
	stack_b = get_empty_stack();
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
