/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:29:26 by lnzimand          #+#    #+#             */
/*   Updated: 2019/05/27 14:52:39 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int counter1;
	unsigned int counter2;

	counter1 = 0;
	counter2 = 0;
	while (src[counter1] != '\0')
		counter1++;
	while (counter2 < len)
	{
		dest[counter2] = src[counter2];
		counter2++;
	}
	while (counter1 < len)
	{
		dest[counter1] = '\0';
		counter1++;
	}
	return (dest);
}
