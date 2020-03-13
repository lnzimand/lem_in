/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:59:35 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/19 13:19:49 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			t;
	unsigned char	*pt1;
	unsigned char	*pt2;

	t = 0;
	pt2 = (unsigned char*)s;
	pt1 = (unsigned char *)d;
	if (d == s)
		return (d);
	while (n--)
	{
		*(pt1 + t) = *(pt2 + t);
		if (*(pt2 + t) == (unsigned char)c)
			return (pt1 + t + 1);
		t++;
	}
	return (NULL);
}
