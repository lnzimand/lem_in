/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:36 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/19 13:48:58 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	int			j;
	int			c;
	int			rem;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			c = 0;
			rem = i;
			while ((needle[j] != '\0') && haystack[i] == needle[j] && i < len)
				c += haystack[i++] - needle[j++];
			if (c == 0 && needle[j] == '\0')
				return ((char*)&haystack[rem]);
			else
				i = rem;
		}
		i++;
	}
	return (NULL);
}
