/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:18:05 by joana             #+#    #+#             */
/*   Updated: 2023/11/27 22:58:00 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_list_int **stack)
{
	t_list_int	*temp;
	t_list_int	*temp2;
	int			m;

	m = 1;
	temp = (*stack);
	temp2 = (*stack)->next;
	while (temp2)
	{
		if (temp->content < temp2->content)
			temp = temp2;
		temp2 = temp2->next;
	}
	temp2 = (*stack);
	while (temp2->content != temp->content)
	{
		m++;
		temp2 = temp2->next;
	}
	return (m);
}

void	find_what_to_do_biggest(t_list_int **stack_a, t_list_int **stack_b)
{
	int	m;

	if (find_biggest(stack_a) <= ft_lstsize_int(*stack_a) / 2)
	{
		m = find_biggest(stack_a);
		while (m != 1)
		{
			push_b(stack_a, stack_b);
			sort_three(stack_b);
			m--;
			if (m == 1)
				rotate_a(stack_a);
		}
	}
	if (find_biggest(stack_a) > ft_lstsize_int(*stack_a) / 2)
	{
		m = ft_lstsize_int(*stack_a) - find_biggest(stack_a);
		while (m != 0)
		{
			reverse_rotate_a(stack_a);
			m--;
		}
	}
}

void	find_smallest_part_1(t_list_int **stack_a, t_list_int **stack_b)
{
	int	m;

	m = ft_lstsize_int(*stack_a);
	while ((*stack_a)->next != NULL)
	{
		while ((*stack_b)->content < (*stack_a)->content && m != 0)
		{
			(*stack_a) = (*stack_a)->next;
			m--;
		}
		if ((*stack_b)->content > (*stack_a)->content)
			break ;
	}
	if (m == 0)
	{
		push_b(stack_a, stack_b);
		rotate_a(stack_a);
	}
}

int	find_smallest_part_2(t_list_int **stack_a, t_list_int **stack_b)
{
	int	m;

	m = 0;
	while ((*stack_a)->next != NULL || m++ <= 1)
	{
		while ((*stack_a)->content < (*stack_a)->next->content)
			(*stack_a)->next = (*stack_a)->next->next;
		if ((*stack_a)->content > (*stack_a)->next->content)
			(*stack_a) = (*stack_a)->next;
	}
	if (m <= 1)
	{
		if (((*stack_b)->content < (*stack_a)->content)
			&& ((*stack_b)->content < (*stack_a)->next->content))
		{
			push_b(stack_a, stack_b);
			sort_three(stack_b);
			rotate_a(stack_a);
		}
	}
	if (m == 2)
		find_smallest_part_1(stack_a, stack_b);
	return (m);
}

void	find_what_to_do_stack_b(t_list_int **stack)
{
	int	m;

	m = 0;
	while ((*stack)->next != NULL)
	{
		while ((*stack)->content < (*stack)->next->content)
			(*stack)->next = (*stack)->next->next;
		if ((*stack)->content > (*stack)->next->content)
		{
			(*stack) = (*stack)->next;
			m++;
		}
	}
	while (m != 0)
	{
		if (m-- <= ft_lstsize_int(*stack) / 2)
			rotate_b(stack);
		if (m-- > ft_lstsize_int(*stack) / 2)
			reverse_rotate_b(stack);
	}
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
	t_list_int *lst6;
	t_list_int *lst7;
	t_list_int *lst8;
	t_list_int *lst9;
	int content1 = 8;
	int content2 = 6;
	int content3 = 9;
	int content4 = 20;
	int content5 = 7;
	int content6 = 15;
	int content7 = 10;
	int content8 = 6;
	int content9 = 4;
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
	lst6 = ft_lstnew_int(content6);
	lst7 = ft_lstnew_int(content7);
	lst8 = ft_lstnew_int(content8);
	lst9 = ft_lstnew_int(content9);
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
	ft_lstadd_back_int(&full_list, lst6);
	ft_lstadd_back_int(&full_list, lst7);
	ft_lstadd_back_int(&full_list, lst8);
	ft_lstadd_back_int(&full_list, lst9);
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
	//printf("%d\n", find_biggest(&full_list));

	// printf("After Rotate:\n");
	//
	find_what_to_do(&full_list, &full_list2);

	printf("Full List 1:\n");
	current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	printf("Full List 2:\n");
	t_list_int *current2 = full_list2;
	current2 = full_list2;
	while (current2 != NULL)
	{
		printf("%d\n", current2->content);
		current2 = current2->next;
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