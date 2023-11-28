/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rotate_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:20:39 by joana             #+#    #+#             */
/*   Updated: 2023/11/09 19:31:23 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list_int **stack_a, t_list_int **stack_b)
{
	if ((ft_lstsize_int(*stack_b) == 0))
		return ;
	else if (ft_push(stack_b, stack_a))
		write(1, "pa\n", 3);
	else
		return ;
}

void	push_b(t_list_int **stack_a, t_list_int **stack_b)
{
	if ((ft_lstsize_int(*stack_a) == 0))
		return ;
	else if (ft_push(stack_a, stack_b))
		write(1, "pb\n", 3);
	else
		return ;
}

void	rotate_a(t_list_int **stack)
{
	if ((ft_lstsize_int(*stack) <= 1))
		return ;
	else if (ft_rotate(stack))
		write(1, "ra\n", 3);
	else
		return ;
}

void	rotate_b(t_list_int **stack)
{
	if ((ft_lstsize_int(*stack) <= 1))
		return ;
	else if (ft_rotate(stack))
		write(1, "rb\n", 3);
	else
		return ;
}

void	rotate_r(t_list_int **stack_a, t_list_int **stack_b)
{
	if ((ft_lstsize_int(*stack_a) <= 1) || (ft_lstsize_int(*stack_b) <= 1))
		return ;
	else if (ft_rotate(stack_a) && ft_rotate(stack_b))
		write(1, "rr\n", 3);
	else
		return ;
}
