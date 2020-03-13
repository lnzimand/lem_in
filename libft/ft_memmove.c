/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:30:29 by lnzimand          #+#    #+#             */
/*   Updated: 2019/09/02 09:30:32 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pt;

	if (!dst && !src)
		return (NULL);
	if (!(pt = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(pt, src, len);
	ft_memcpy(dst, pt, len);
	free(pt);
	return (dst);
}
