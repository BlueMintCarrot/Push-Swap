/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:35:21 by joana             #+#    #+#             */
/*   Updated: 2023/11/30 01:29:42 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_three(t_list_int **stack)
{
	if (((*stack)->content < (*stack)->next->content)
		&& ((*stack)->content < (*stack)->next->next->content)
		&& ((*stack)->next->content < (*stack)->next->next->content))
		return (1);
	return (0);
}

void	sort_three(t_list_int **stack)
{
	if (ft_lstsize_int(*stack) <= 1)
		return ;
	else if (ft_lstsize_int(*stack) == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			swap_b(stack);
	}
	else if (((*stack)->content > (*stack)->next->content)
		&& ((*stack)->content < (*stack)->next->next->content))
		swap_a(stack);
	else
		rotate_a(stack);
}

void	bread_and_fred(t_list_int **stack_a, t_list_int **stack_b)
{
	while (!sorted_three(stack_a))
		sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	bread_and_fred_2(t_list_int **stack_a, t_list_int *temp)
{
	(*stack_a)->next = temp;
	rotate_a(stack_a);
}

void	sort_five(t_list_int **stack_a, t_list_int **stack_b, int i,
		int lst_size)
{
	t_list_int	*temp;

	lst_size = ft_lstsize_int(*stack_a);
	while (lst_size > 3)
	{
		temp = (*stack_a)->next;
		i = 1;
		while ((*stack_a)->content < (*stack_a)->next->content)
		{
			if (i == lst_size - 1)
			{
				(*stack_a)->next = temp;
				push_b(stack_a, stack_b);
				lst_size--;
				break ;
			}
			(*stack_a)->next = (*stack_a)->next->next;
			i++;
		}
		if ((*stack_a)->next != NULL && i != lst_size)
			bread_and_fred_2(stack_a, temp);
	}
	bread_and_fred(stack_a, stack_b);
}

/*int	main(void)
{
	int	i;
	int	lst_size;
	t_list_int *full_list = NULL; // Initialize full_list with NULL
	t_list_int *lst1;
	t_list_int *lst2;
	t_list_int *lst3;
	t_list_int *lst4;
	t_list_int *lst5;
	int content1 = 8;
	int content2 = 6;
	int content3 = 9;
	int content4 = 20;
	int content5 = 7;
	t_list_int *full_list2 = NULL; // Initialize full_list with NULL
	// t_list_int *lst5;
	// t_list_int *lst6;
	// t_list_int *lst7;
	// t_list_int *lst8;
	// int		content5 = 2;
	// int		content6 = 7;
	// int		content7 = 9;
	// int		content8 = 8;

	lst1 = ft_lstnew_int(content1);
	lst2 = ft_lstnew_int(content2);
	lst3 = ft_lstnew_int(content3);
	lst4 = ft_lstnew_int(content4);
	lst5 = ft_lstnew_int(content5);
	// lst6 = ft_lstnew_int(content6);
	// lst7 = ft_lstnew_int(content7);
	// lst8 = ft_lstnew_int(content8);

	printf("\n");
	// Pass the address of full_list to ft_lstadd_back
	ft_lstadd_back_int(&full_list, lst1);
	ft_lstadd_back_int(&full_list, lst2);
	ft_lstadd_back_int(&full_list, lst3);
	ft_lstadd_back_int(&full_list, lst4);
	ft_lstadd_back_int(&full_list, lst5);
	// ft_lstadd_back_int(&full_list2, lst5);
	// ft_lstadd_back_int(&full_list2, lst6);
	// ft_lstadd_back_int(&full_list2, lst7);
	// ft_lstadd_back_int(&full_list2, lst8);

	printf("Full List 1:\n");
	t_list_int *current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}

	//while (!sorted_three(&full_list))
	//find_biggest(&full_list);
	printf("%d\n", find_biggest(&full_list));

	// printf("After Rotate:\n");
	//
	printf("Full List 1:\n");
	current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	//
	// ft_rev_rotate(&full_list);
	//
	// printf("After RevRotate:\n");
	//
	// printf("Full List 1:\n");
	// current = full_list;
	// while (current != NULL)
	//{
	//    printf("%d\n", current->content);
	//    current = current->next;
	//}
	//
	// printf("Full List 2:\n");
	// current = full_list2;
	// while (current != NULL)
	//{
	//    printf("%d\n", current->content);
	//    current = current->next;
	//}
	//
	// ft_push(&full_list, &full_list2, int i);
	//
	// printf("After Push:\n");
	//
	// printf("Full List 1:\n");
	// current = full_list;
	// while (current != NULL)
	//{
	//    printf("%d\n", current->content);
	//    current = current->next;
	//}
	//
	// printf("Full List 2:\n");
	// current = full_list2;
	// while (current != NULL)
	//{
	//    printf("%d\n", current->content);
	//    current = current->next;
	//}
	//
	return (0);
}*/