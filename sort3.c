/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:52:55 by joana             #+#    #+#             */
/*   Updated: 2023/11/28 22:04:21 by joanda-s         ###   ########.fr       */
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

//int	stack_backup2(t_list_int **stack)
//{
//	int			*avbup;
//	int			i;
//	int			acbup;
//	t_list_int	*temp;
//
//	i = 0;
//	avbup = NULL;
//	temp = (*stack);
//	while(*stack)
//	{
//		(*stack) = (*stack)->next;
//		i++;
//	}
//	(*stack) = temp;
//	acbup = i;
//	return (acbup);
//}

int	*stack_backup(t_list_int **stack)
{
	size_t	i;
	size_t	m;
	int	*avbup;
	t_list_int	*temp;
	
	i = 0;
	m = ft_lstsize_int(*stack);
	avbup = (int *)malloc(m * sizeof(int));
	if (!avbup)
		return (NULL);
	temp = (*stack);
	while (i < m)
	{
		avbup[i] = (*stack)->content;
		i++;
		(*stack) = (*stack)->next;
	}
	(*stack) = temp;
	return (avbup);
}

void	ft_stack_construct_int(int argc, int *argv, t_list_int **stack)
{
	int			i;
	t_list_int	*node;

	i = 1;
	if (!argv)
		ft_failure();
	while (i <= argc)
	{
		node = ft_lstnew_int(ft_llato(ft_itoa(argv[i])));
		if (!node)
			ft_failure();
		else if ((*stack) == NULL)
			*stack = node;
		else
			ft_lstadd_back_int(stack, node);
		i++;
	}
}

int	find_biggest(t_list_int **stack)
{
	int biggest;
	int biggestPos;
	int pos;
	t_list_int * stkit;
	
	biggest = (*stack)->content;
	biggestPos = 1;

	stkit = (*stack)->next;
	pos = 2;
	while (stkit != NULL)
	{
		if (stkit->content > biggest)
			biggestPos = pos;
		stkit = stkit->next;
		pos++;
	}
	return (biggestPos);
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
	int content5 = 7;
	//int content6 = 15;
	//int content7 = 10;
	//int content8 = 6;
	//int content9 = 4;
	//t_list_int *full_list2 = NULL; // Initialize full_list with NULL
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
	//lst6 = ft_lstnew_int(content6);
	//lst7 = ft_lstnew_int(content7);
	//lst8 = ft_lstnew_int(content8);
	//lst9 = ft_lstnew_int(content9);
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
	//ft_lstadd_back_int(&full_list, lst6);
	//ft_lstadd_back_int(&full_list, lst7);
	//ft_lstadd_back_int(&full_list, lst8);
	//ft_lstadd_back_int(&full_list, lst9);
	// ft_lstadd_back_int(&full_list2, lst5);
	// ft_lstadd_back_int(&full_list2, lst6);
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
	printf("%d\n\n", findBiggest(&full_list));
	printf("Full List 1:\n");
	t_list_int *current2 = full_list;
	while (current2 != NULL)
	{
		printf("%d\n", current2->content);
		current2 = current2->next;
	}
	return 0;
}*/