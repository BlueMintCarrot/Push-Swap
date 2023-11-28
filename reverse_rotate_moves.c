/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:22:06 by joana             #+#    #+#             */
/*   Updated: 2023/11/09 19:35:42 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list_int **stack)
{
	if ((ft_lstsize_int(*stack) <= 1))
		return ;
	else if (ft_rev_rotate(stack))
		write(1, "rra\n", 4);
	else
		return ;
}

void	reverse_rotate_b(t_list_int **stack)
{
	if ((ft_lstsize_int(*stack) <= 1))
		return ;
	else if (ft_rev_rotate(stack))
		write(1, "rrb\n", 4);
	else
		return ;
}

void	reverse_rotate_r(t_list_int **stack_a, t_list_int **stack_b)
{
	if ((ft_lstsize_int(*stack_a) <= 1) && (ft_lstsize_int(*stack_b) <= 1))
		return ;
	else if (ft_rev_rotate(stack_a) && ft_rev_rotate(stack_b))
		write(1, "rrr\n", 4);
	else
		return ;
}
