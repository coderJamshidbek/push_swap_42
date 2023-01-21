/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 08:15:21 by jergashe          #+#    #+#             */
/*   Updated: 2023/01/21 11:25:53 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/lib_push_swap.h"

int	ft_is_all_digits(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (ft_isdigit(str[index]) == 0 && ft_is_space_char(str[index]) == 0
			&& str[index] != '-' && str[index] != '+')
			return (0);
		index++;
	}
	return (1);
}

int	get_nb_of_ints_in_1_argv(char *input)
{
	int		index;
	char	**split_num;

	split_num = ft_split(input, ' ');
	if (split_num == NULL)
		exit(2);// SPLIT ERROR // SHOW ERROR!!!
	index = 0;
	while (split_num[index] != NULL)
		index++;
	free(split_num);
	return (index);
}

int	get_num_of_ints(int argc, char **argv)
{
	int	count;
	int	index;

	index = 1;
	count = 0;
	while (index < argc)
	{
		if (ft_is_all_digits(argv[index]) == 0)
			exit_with_msg(NON_NUMERIC);
		count += get_nb_of_ints_in_1_argv(argv[index]);
		index++;
	}
	return (count);
}

int	fill_array(long *array, char *str, int start_index)
{
	char	**str_array;
	int		index;

	str_array = ft_split(str, ' ');
	if (str_array == NULL)
		exit(2); // SPLIT ERROR // SHOW ERROR!!!
	index = 0;
	while (str_array[index] != NULL)
	{
		array[start_index + index] = ft_atol(str_array[index]);
		index++;
	}
	free(str_array);
	return index;
}

long	*get_long_arr_from_input(int argc, char **argv)
{
	int		array_index;
	long	*array;
	int		array_size;
	int		argv_index;

	array_size = get_num_of_ints(argc, argv);
	array = malloc(sizeof(*array) * array_size);
	if (array == NULL)
		return (NULL);
	argv_index = 1;
	array_index = 0;
	while (argv_index < argc)
	{
		array_index += fill_array(array, argv[argv_index], array_index);
		argv_index++;
	}	
	return (array);
}
