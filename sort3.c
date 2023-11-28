/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:52:55 by joana             #+#    #+#             */
/*   Updated: 2023/11/27 21:53:38 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest_until_big(t_list_int **stack_a, t_list_int **stack_b)
{
	int	m;
	int	n;

	m = 0;
	while (m < find_biggest(stack_a))
	{
		while ((*stack_a)->content < (*stack_a)->next->content)
			(*stack_a)->next = (*stack_a)->next->next;
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			(*stack_a) = (*stack_a)->next;
			n = (*stack_a)->content;
			m++;
		}
	}
	if ((*stack_b)->content > ft_lstlast_int(*stack_a)->content
		&& (*stack_b)->content < n)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		find_smallest_until_big(stack_a, stack_b);
	}
}
