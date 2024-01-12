/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:46:56 by joana             #+#    #+#             */
/*   Updated: 2024/01/12 20:05:41 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	are_you_still_there(t_list_int **stack_a, t_list_int **stack_b)
{
	push_a(stack_a, stack_b);
	find_what_to_do_stack_b(stack_b);
	rotate_a(stack_a);
}

void	companion_cube(t_list_int **stack_a, t_list_int **stack_b)
{
	push_b(stack_a, stack_b);
	sort_three(stack_b);
	find_what_to_do_stack_b(stack_b);
}
