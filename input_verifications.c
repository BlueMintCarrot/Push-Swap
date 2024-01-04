/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verifications.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:32:24 by joana             #+#    #+#             */
/*   Updated: 2023/12/26 16:11:29 by joana            ###   ########.fr       */
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
	int			i;
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
	t_list_int	*temp;
	t_list_int	*temp2;

	temp = (*stack)->next;
	temp2 = (*stack);
	while ((*stack) != NULL && temp != NULL)
	{
		if (ft_intcmp((*stack)->content, temp->content) == 1)
			ft_failure();
		else if (temp->next == NULL)
		{
			temp = (*stack)->next->next;
			(*stack) = (*stack)->next;
		}
		else
			temp = temp->next;
	}
	(*stack) = temp2;
}

int	is_ordered(t_list_int **stack)
{
	t_list_int	*temp;

	temp = (*stack);
	while ((*stack)->next != NULL
		&& (*stack)->content < (*stack)->next->content)
			*stack = (*stack)->next;
	if ((*stack)->next == NULL)
	{
		(*stack) = temp;
		return (0);
	}
	else
	{
		(*stack) = temp;
		return (1);
	}
}
