/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:29:42 by joanda-s          #+#    #+#             */
/*   Updated: 2023/10/07 12:41:33 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final;

	i = -1;
	j = 0;
	final = malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (final == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		final[i] = s1[i];
	while (s2[j] != '\0')
		final[i++] = s2[j++];
	final[i] = '\0';
	return (final);
}
