/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:30:55 by joanda-s          #+#    #+#             */
/*   Updated: 2023/04/18 15:02:27 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbl, size_t sizebl)
{
	size_t	tlsize;
	void	*res;

	tlsize = sizebl * nbl;
	res = malloc(tlsize);
	if (res == NULL)
	{
		return (NULL);
	}
	if (nbl == 0 || sizebl == 0)
	{
		return (res);
	}
	ft_memset(res, 0, tlsize);
	return (res);
}
