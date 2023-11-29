/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:18:50 by joanda-s          #+#    #+#             */
/*   Updated: 2023/11/28 21:33:24 by joanda-s         ###   ########.fr       */
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
