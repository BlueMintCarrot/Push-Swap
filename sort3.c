/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:52:55 by joana             #+#    #+#             */
/*   Updated: 2023/12/19 20:36:37 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_until_big(t_list_int **stack_a)
{
	int	m;
	int	n;
	t_list_int	*temp;
	t_list_int	*temp2;

	m = 1;
	n = (*stack_a)->content;
	temp = (*stack_a);
	temp2 = (*stack_a)->next;
	while (temp2->next != NULL && m < find_biggest(&temp))
	{
		while ((temp2->next != NULL && (*stack_a)->content < temp2->content))
			temp2 = temp2->next;
		if (find_biggest(&temp) == 2)
			break ;
		if (temp2->next != NULL &&(*stack_a)->content > temp2->content)
		{
			(*stack_a) = temp2;
			n = temp2->content;
            temp2 = temp2->next;
			m++;
		}
	}
	(*stack_a) = temp;
	return (n);
}
void	the_cake_is_a_lie(t_list_int **stack_a, t_list_int **stack_b)
{	
	int	n;
	
	n = find_smallest_until_big(stack_a);
	if ((*stack_b) && (*stack_b)->content > ft_lstlast_int(*stack_a)->content
		&& (*stack_b)->content < n)
	{
		push_a(stack_a, stack_b);
		find_what_to_do_stack_b(stack_b);
		rotate_a(stack_a);
		the_cake_is_a_lie(stack_a, stack_b);
	}
}

int	find_biggest(t_list_int **stack)
{
	int big;
	int bigpos;
	int pos;
	t_list_int *temp;
	
	big = (*stack)->content;
	bigpos = 1;

	temp = (*stack)->next;
	pos = 2;
	while (temp != NULL)
	{
		if (temp->content > big)
		{
			bigpos = pos;
			big = temp->content;
		}
		temp = temp->next;
		pos++;
	}
	return (bigpos);
}
//
//void printNode(void *node) {
//	printf("%d\n", ((t_list_int *)node)->content);
//}

/*int main() {
	t_list_int *full_list = NULL; // Initialize full_list with NULL
	t_list_int *lst1;
	t_list_int *lst2;
	t_list_int *lst3;
	t_list_int *lst4;
	t_list_int *lst5;
	//t_list_int *lst6;
	//t_list_int *lst7;
	//t_list_int *lst8;
	//t_list_int *lst9;
	int content1 = 8;
	int content2 = 6;
	int content3 = 9;
	int content4 = 20;
	int content5 = 2;
	//int content6 = 15;
	//int content7 = 10;
	//int content8 = 6;
	//int content9 = 4;
	t_list_int *full_list2 = NULL; // Initialize full_list with NULL
	t_list_int *lst6;
	// t_list_int *lst6;
	// t_list_int *lst7;
	// t_list_int *lst8;
	int		content6 = 7;
	// int		content6 = 7;
	// int		content7 = 9;
	// int		content8 = 8;

	lst1 = ft_lstnew_int(content1);
	lst2 = ft_lstnew_int(content2);
	lst3 = ft_lstnew_int(content3);
	lst4 = ft_lstnew_int(content4);
	lst5 = ft_lstnew_int(content5);
	//lst6 = NULL;
	//lst7 = ft_lstnew_int(content7);
	//lst8 = ft_lstnew_int(content8);
	//lst9 = ft_lstnew_int(content9);
	lst6 = ft_lstnew_int(content6);
	// lst7 = ft_lstnew_int(content7);
	// lst8 = ft_lstnew_int(content8);

	printf("\n");
	// Pass the address of full_list to ft_lstadd_back
	ft_lstadd_back_int(&full_list, lst1);
	ft_lstadd_back_int(&full_list, lst2);
	ft_lstadd_back_int(&full_list, lst3);
	ft_lstadd_back_int(&full_list, lst4);
	ft_lstadd_back_int(&full_list, lst5);
	//ft_lstadd_back_int(&full_list, lst6);
	//ft_lstadd_back_int(&full_list, lst7);
	//ft_lstadd_back_int(&full_list, lst8);
	//ft_lstadd_back_int(&full_list, lst9);
	//ft_lstadd_back_int(&full_list2, lst6);
	ft_lstadd_back_int(&full_list2, lst6);
	// ft_lstadd_back_int(&full_list2, lst7);
	// ft_lstadd_back_int(&full_list2, lst8);
	// iter_list_n_times(full_list, printNode);
	printf("Full List 1:\n");
	t_list_int *current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	printf("\n");
	printf("Full List 2:\n");
	t_list_int *current2 = full_list2;
	while (current2 != NULL)
	{
		printf("%d\n", current2->content);
		current2 = current2->next;
	}
	the_cake_is_a_lie(&full_list, &full_list2);	
	//find_what_to_do_stack_b(&full_list);
	//printf("%d\n\n", find_biggest(&full_list));
	printf("Full List 1:\n");
	current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	return 0;
}*/