/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:42:30 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/18 14:49:50 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (!(dst = malloc(size + 1)))
		return (NULL);
	else
		ft_memset(dst, 0, size);
	dst[size] = '\0';
	return (dst);
}
