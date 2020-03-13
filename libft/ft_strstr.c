/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:36 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/05 10:01:20 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int c;
	int	rem;

	i = 0;
	if (haystack == needle || needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			c = 0;
			rem = i;
			while ((needle[j] != '\0') && c == 0)
				c += haystack[i++] - needle[j++];
			if (c == 0)
				return ((char*)&haystack[rem]);
			else
				i = rem;
		}
		i++;
	}
	return (NULL);
}
