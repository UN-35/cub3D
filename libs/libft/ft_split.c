/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:44:58 by melhadou          #+#    #+#             */
/*   Updated: 2024/01/02 18:27:34 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(char *str, char c)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			s++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (s);
}

static char	*dup_str(char *str, char c)
{
	int		i;
	int		l;
	char	*s;

	l = 0;
	while (str[l] && str[l] != c)
		l++;
	s = malloc(l + 1);
	i = 0;
	if (!s)
		return (NULL);
	while (i < l)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static void	ft_free_str(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**str;

	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (count_strs(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i] = dup_str(s, c);
			if (!str[i])
				ft_free_str(str, i);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}
