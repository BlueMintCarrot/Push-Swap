/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:19:20 by joana             #+#    #+#             */
/*   Updated: 2024/01/12 20:12:43 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_llato(const char *str)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 1;
	z = 0;
	while ((str[x] >= 9 && str[x] <= 13) || (str[x] == 32))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			y = -1;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		z = (z * 10) + (str[x] - 48);
		if (z > INT_MAX || z < INT_MIN)
			ft_failure();
		x++;
	}
	return (z * y);
}

void	ft_stack_construct(int argc, char **argv, t_list_int **stack)
{
	int			i;
	t_list_int	*node;

	i = 1;
	if (!argv[i])
		ft_failure();
	while (i < argc)
	{
		node = ft_lstnew_int(ft_llato(argv[i]));
		if (!node)
			ft_failure();
		else if ((*stack) == NULL)
			*stack = node;
		else
			ft_lstadd_back_int(stack, node);
		i++;
	}
}

void	still_alive(t_list_int **stack_a, t_list_int **stack_b, int argc,
		char **argv)
{
	ft_stack_construct(argc, argv, stack_a);
	ft_is_dup(stack_a);
	while (argc == 4 && !sorted_three(stack_a))
		sort_three(stack_a);
	while (argc == 6 && is_ordered(stack_a) == 1)
		sort_five(stack_a, stack_b, 0, 0);
	if (is_ordered(stack_a) == 1)
		find_what_to_do_biggest(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list_int	*stack_a;
	t_list_int	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (ft_is_int(argc, argv) == 0)
		ft_failure();
	still_alive(&stack_a, &stack_b, argc, argv);
	while (1)
	{
		while (is_ordered(&stack_a) && !stack_b)
			find_smallest_part_2(&stack_a, &stack_b);
		while (is_ordered(&stack_a) && stack_b)
			find_smallest_part_2(&stack_a, &stack_b);
		while (stack_b)
			find_smallest_part_2(&stack_a, &stack_b);
		while (find_smallest(&stack_a) > 1)
			rotate_a(&stack_a);
		if (!is_ordered(&stack_a))
			break ;
	}
	free(stack_a);
	return (0);
}
