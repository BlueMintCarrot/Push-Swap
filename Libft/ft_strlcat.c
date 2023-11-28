/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:47:08 by joanda-s          #+#    #+#             */
/*   Updated: 2023/10/06 15:43:35 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dest);
	if (destsize <= j)
		return (destsize + ft_strlen(src));
	while (src[i] != '\0' && (j + 1) < destsize)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (j + ft_strlen(&src[i]));
}
