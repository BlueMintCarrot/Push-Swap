/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:33:07 by joanda-s          #+#    #+#             */
/*   Updated: 2023/11/06 01:45:49 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_int(t_list_int **lst, t_list_int *new)
{
	if ((*lst) == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
