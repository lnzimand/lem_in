/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:51:43 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/20 14:49:26 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		word_count(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static	int		word_length(const char *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s1;

	i = -1;
	j = 0;
	if (!s || !(s1 = (char **)malloc(sizeof(*s1) * (word_count(s, c) + 1))))
		return (NULL);
	while (++i < word_count(s, c))
	{
		k = 0;
		if (!(s1[i] = ft_strnew(word_length(&s[j], c) + 1)))
			s1[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			s1[i][k++] = s[j++];
		s1[i][k] = '\0';
	}
	s1[i] = 0;
	return (s1);
}
