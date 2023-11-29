/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:19:20 by joana             #+#    #+#             */
/*   Updated: 2023/11/28 22:06:11 by joanda-s         ###   ########.fr       */
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
	ft_stack_construct(argc, argv, &stack_a);
	ft_is_dup(&stack_a, argc, argv);
	if (argc == 4 && !sorted_three(&stack_a))
		sort_three(&stack_a);
	else if (argc == 6 && is_ordered(&stack_a) == 1)
		sort_five(&stack_a, &stack_b, 0, 0);
	else if (is_ordered(&stack_a) == 1)
		find_what_to_do_biggest(&stack_a, &stack_b);
	while (is_ordered(&stack_a) == 1)
	{
		find_smallest_part_2(&stack_a, &stack_b);
		find_what_to_do_stack_b(&stack_b);
		find_smallest_until_big(&stack_a, &stack_b);
	}
	free (stack_a);
	return (0);
}