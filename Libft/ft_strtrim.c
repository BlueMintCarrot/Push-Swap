/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:21:00 by joanda-s          #+#    #+#             */
/*   Updated: 2023/10/07 19:01:09 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getbegin(char const *s1, char const *set)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	if (set[0] == '\0')
		return (0);
	while (s1[m] != '\0')
	{
		while (n == 0)
		{
			while (s1[m] != set[n] && set[n] != '\0')
				n++;
			while (s1[m] == set[n] && set[n] != '\0')
			{
				m++;
				n = 0;
			}
		}
		return (m);
	}
	return (0);
}

static int	ft_getend(char const *s1, char const *set)
{
	int	m;
	int	n;

	m = ft_strlen(s1) - 1;
	n = 0;
	if (set[0] == '\0')
		return (m);
	while (s1[m] >= 0)
	{
		while (n == 0)
		{
			while (s1[m] != set[n] && set[n] != '\0')
				n++;
			while (s1[m] == set[n] && set[n] != '\0')
			{
				m--;
				n = 0;
				if (m == -1 && ++n)
					m++;
			}
		}
		return (m);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	size_t	s;
	size_t	e;

	s = ft_getbegin(s1, set);
	e = ft_getend(s1, set);
	if (s1 == NULL)
		return (NULL);
	final = ft_substr(s1, s, e - s + 1);
	return (final);
}
