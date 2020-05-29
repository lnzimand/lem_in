/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:43:49 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/05 09:54:16 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*out;
	char		*str;
	char const	*src;

	if (s)
	{
		str = ft_strnew(len);
		out = str;
		src = &s[start];
		if (str)
		{
			while (*src != 0 && len > 0)
			{
				*str++ = *src++;
				len--;
			}
			return (out);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}