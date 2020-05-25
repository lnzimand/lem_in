/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:48:57 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/19 13:50:04 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	w_count(int n)
{
	int		i;
	long	j;

	i = 0;
	j = n;
	if (j < 0)
	{
		j = j * -1;
		i++;
	}
	while (j > 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s1;
	int		negative;
	int		i;
	long	j;

	i = 0;
	j = n;
	negative = 0;
	if (!(s1 = (char*)malloc(sizeof(char) * (w_count(n) + 1))))
		return (NULL);
	if (j == 0)
		return ("0");
	if (j < 0 && (j *= -1))
		negative = 1;
	while (j > 0)
	{
		s1[i++] = j % 10 + '0';
		j /= 10;
	}
	if (negative == 1)
		s1[i++] = '-';
	s1[i] = '\0';
	ft_strrev(s1);
	return (s1);
}
