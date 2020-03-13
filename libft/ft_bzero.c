/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:59:35 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/02 13:13:50 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	unsigned int	t;
	char			*ptr;

	t = 0;
	ptr = str;
	if (n == 0)
		return (str);
	else
		while (t < n)
		{
			*ptr++ = 0;
			t++;
		}
	return (ptr);
}
