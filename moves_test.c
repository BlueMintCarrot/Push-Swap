/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:08:33 by joana             #+#    #+#             */
/*   Updated: 2023/12/18 17:48:29 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_int	*iter_list_n_times(t_list_int *stack, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

int	ft_rotate(t_list_int **stack)
{
	int	temp;
	int	i;
	int	n;

	i = 1;
	n = ft_lstsize_int(*stack);
	while (i < n)
	{
		temp = (*stack)->content;
		(*stack)->content = (iter_list_n_times(*stack, n - i))->content;
		(iter_list_n_times(*stack, n - i))->content = temp;
		i++;
	}
	return (1);
}

int	ft_rev_rotate(t_list_int **stack)
{
	t_list_int	*last_node;
	int			temp;
	int			i;
	int			n;

	i = 1;
	n = ft_lstsize_int(*stack);
	last_node = ft_lstlast_int(*stack);
	while (i < n)
	{
		temp = last_node->content;
		last_node->content = (iter_list_n_times(*stack, i - 1))->content;
		(iter_list_n_times(*stack, i - 1))->content = temp;
		i++;
	}
	return (1);
}

int	ft_swap(t_list_int **stack)
{
	int	temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	return (1);
}

int	ft_push(t_list_int **sender, t_list_int **receiver)
{
	t_list_int	*temp;

	ft_lstadd_front_int(receiver, ft_lstnew_int((*sender)->content));
	temp = (*sender)->next;
	ft_lstdelone_int(*sender);
	*sender = temp;
	return (1);
}

/*int main(void)
{
	t_list_int *full_list = NULL; // Initialize full_list with NULL
	t_list_int *lst1;
	t_list_int *lst2;
	t_list_int *lst3;
	t_list_int *lst4;
	int		content1 = 1;
	int		content2 = 3;
	int		content3 = 5;
	int		content4 = 4;
	t_list_int *full_list2 = NULL; // Initialize full_list with NULL
	t_list_int *lst5;
	t_list_int *lst6;
	t_list_int *lst7;
	t_list_int *lst8;
	int		content5 = 2;
	int		content6 = 7;
	int		content7 = 9;
	int		content8 = 8;

	lst1 = ft_lstnew_int(content1);
	lst2 = ft_lstnew_int(content2);
	lst3 = ft_lstnew_int(content3);
	lst4 = ft_lstnew_int(content4);
	lst5 = ft_lstnew_int(content5);
	lst6 = ft_lstnew_int(content6);
	lst7 = ft_lstnew_int(content7);
	lst8 = ft_lstnew_int(content8);

	printf("\n");
	// Pass the address of full_list to ft_lstadd_back
	ft_lstadd_back_int(&full_list, lst1);
	ft_lstadd_back_int(&full_list, lst2);
	ft_lstadd_back_int(&full_list, lst3);
	ft_lstadd_back_int(&full_list, lst4);
	ft_lstadd_back_int(&full_list2, lst5);
	ft_lstadd_back_int(&full_list2, lst6);
	ft_lstadd_back_int(&full_list2, lst7);
	ft_lstadd_back_int(&full_list2, lst8);

	printf("Full List 1:\n");
	t_list_int *current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}

	ft_rotate(&full_list);

	printf("After Rotate:\n");

	printf("Full List 1:\n");
	current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}

	ft_rev_rotate(&full_list);
	
	printf("After RevRotate:\n");

	printf("Full List 1:\n");
	current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}

	printf("Full List 2:\n");
	current = full_list2;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}

	ft_push(&full_list, &full_list2);

	printf("After Push:\n");

	printf("Full List 1:\n");
	current = full_list;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}

	printf("Full List 2:\n");
	current = full_list2;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
	

	return (0);
}*/