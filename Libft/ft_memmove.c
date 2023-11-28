/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:07:15 by joanda-s          #+#    #+#             */
/*   Updated: 2023/04/18 15:06:58 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	if ((size_t)dest - (size_t)src < n)
	{
		i = (int)n - 1;
		while (i >= 0 && i < (int)n)
		{
			(((unsigned char *)dest)[i] = ((unsigned char *)src)[i]);
			i--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			(((unsigned char *)dest)[i] = ((unsigned char *)src)[i]);
			i++;
		}
	}
	return (dest);
}
