/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:19:41 by joana             #+#    #+#             */
/*   Updated: 2023/11/27 23:17:10 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h" //colocar / verificar path do meu libft conforme pc da escola
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_bounds
{
	t_list	*last_position;
}		t_bounds;

int			find_biggest(t_list_int **stack);
int			find_smallest_part_2(t_list_int **stack_a, t_list_int **stack_b);
int			ft_intcmp(int i1, int i2);
int			ft_is_int(int argc, char **argv);
int			ft_rotate(t_list_int **stack);
int			ft_rev_rotate(t_list_int **stack);
int			ft_swap(t_list_int **stack);
int			ft_push(t_list_int **sender, t_list_int **receiver);
int			is_ordered(t_list_int **stack);
int			sorted_three(t_list_int **stack);
long long	ft_llato(const char *str);
t_list_int	*iter_list_n_times(t_list_int *stack, int n);
void		bread_and_fred(t_list_int **stack_a, t_list_int **stack_b);
void		bread_and_fred2(t_list_int **stack_a, t_list_int **stack_b);
void		find_smallest_part_1(t_list_int **stack_a, t_list_int **stack_b);
void		find_smallest_until_big(t_list_int **stack_a, t_list_int **stack_b);
void		find_what_to_do_biggest(t_list_int **stack_a, t_list_int **stack_b);
void		find_what_to_do_stack_b(t_list_int **stack);
void		ft_failure(void);
void		ft_is_dup(t_list_int **stack);
void		push_a(t_list_int **stack_a, t_list_int **stack_b);
void		push_b(t_list_int **stack_a, t_list_int **stack_b);
void		rotate_a(t_list_int **stack);
void		rotate_b(t_list_int **stack);
void		rotate_r(t_list_int **stack_a, t_list_int **stack_b);
void		reverse_rotate_a(t_list_int **stack);
void		reverse_rotate_b(t_list_int **stack);
void		reverse_rotate_r(t_list_int **stack_a, t_list_int **stack_b);
void		sort_three(t_list_int **stack);
void		sort_five(t_list_int **stack_a, t_list_int **stack_b, int i,
			int lst_size);
void		ft_stack_construct(int argc, char **argv, t_list_int **stack);
void		swap_a(t_list_int **stack);
void		swap_b(t_list_int **stack);
void		swap_s(t_list_int **stack_a, t_list_int **stack_b);

#endif 
