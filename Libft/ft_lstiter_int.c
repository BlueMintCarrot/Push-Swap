/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:18:50 by joanda-s          #+#    #+#             */
/*   Updated: 2024/01/12 19:33:10 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstiter_int(t_list_int *lst)
{
	int			i;
	t_list_int	*temp;

	i = 0;
	temp = lst;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	lst = temp;
	return (i);
}
