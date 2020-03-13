/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:59:35 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/11 11:46:07 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	t;
	char			*pt1;
	const char		*pt2;

	if (!dst && !src)
		return (NULL);
	t = 0;
	pt1 = dst;
	pt2 = src;
	while (t < n)
	{
		pt1[t] = pt2[t];
		t++;
	}
	return (dst);
}
