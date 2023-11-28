/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:32:24 by joana             #+#    #+#             */
/*   Updated: 2023/11/28 00:03:13 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_failure(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_is_int(int argc, char **argv)
{
	int	i;
	static int	j;

	i = 0;
	while (++i < argc)
	{
		if (!argv[i][0])
			return (0);
		else if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& ft_isdigit(argv[i][j + 1]) == 0)
			return (0);
		else
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			while (argv[i][j])
			{
				if (ft_isdigit(argv[i][j]) == 0)
					return (0);
				j++;
			}
		}
		j = 0;
	}
	return (1);
}

int	ft_intcmp(int i1, int i2)
{
	if (i1 == i2)
		return (1);
	else
		return (0);
}

void	ft_is_dup(t_list_int **stack)
{
	t_list_int	*stack_copy1;
	t_list_int	*stack_copy2;

	stack_copy1 = *stack;
	stack_copy2 = (*stack)->next;
	while (stack_copy1 && stack_copy2)
	{
		if (ft_intcmp(stack_copy1->content, stack_copy2->content) == 1)
			ft_failure();
		else if (!(stack_copy2->next))
		{
			stack_copy2 = stack_copy1->next->next;
			stack_copy1 = stack_copy1->next;
		}
		else
			stack_copy2 = stack_copy2->next;
	}
}

int	is_ordered(t_list_int **stack)
{
	while ((*stack)->next != NULL &&
		(*stack)->content < (*stack)->next->content)
			*stack = (*stack)->next;
	if ((*stack)->next == NULL)
		return (0);
	else
		return (1);
}
