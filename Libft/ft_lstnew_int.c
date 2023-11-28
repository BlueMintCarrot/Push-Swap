/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:19:35 by joanda-s          #+#    #+#             */
/*   Updated: 2023/11/06 00:50:08 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_int	*ft_lstnew_int(int content)
{
	t_list_int	*new;

	new = malloc(sizeof(t_list_int));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
