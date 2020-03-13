/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:59:35 by lnzimand          #+#    #+#             */
/*   Updated: 2019/05/27 13:55:13 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	t;
	unsigned char	p;
	char			*pt;

	t = 0;
	p = (unsigned char)c;
	pt = (char*)str;
	while (t < n)
	{
		pt[t] = p;
		t++;
	}
	return (str);
}
