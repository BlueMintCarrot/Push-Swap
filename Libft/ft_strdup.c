/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:08:02 by joanda-s          #+#    #+#             */
/*   Updated: 2023/10/06 15:42:58 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (duplicate == NULL)
		return (NULL);
	ft_memcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}
