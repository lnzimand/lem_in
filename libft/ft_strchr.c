/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:32:13 by lnzimand          #+#    #+#             */
/*   Updated: 2019/05/24 12:45:27 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*dest;

	dest = (char*)str;
	while (*str != '\0')
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	if (*str == '\0' && *str == c)
	{
		dest = (char*)str;
		return (dest);
	}
	return (NULL);
}
