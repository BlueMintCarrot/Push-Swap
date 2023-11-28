/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:10:01 by joana             #+#    #+#             */
/*   Updated: 2023/11/09 19:46:37 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list_int **stack)
{
	if (ft_swap(stack))
		write(1, "sa\n", 3);
	else
		return ;
}

void	swap_b(t_list_int **stack)
{
	if (ft_swap(stack))
		write(1, "sb\n", 3);
	else
		return ;
}

void	swap_s(t_list_int **stack_a, t_list_int **stack_b)
{
	if ((ft_lstsize_int(*stack_a) < 2) || (ft_lstsize_int(*stack_b) < 2))
		return ;
	if (ft_swap(stack_a) && ft_swap(stack_b))
		write(1, "ss\n", 3);
	else
		return ;
}
