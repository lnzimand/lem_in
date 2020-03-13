/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:16:18 by lnzimand          #+#    #+#             */
/*   Updated: 2019/05/27 15:08:04 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int		cnt1;
	size_t	cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (s1[cnt1] != '\0')
		cnt1++;
	while (cnt2 < n && s2[cnt2])
	{
		s1[cnt1] = s2[cnt2];
		cnt1++;
		cnt2++;
	}
	s1[cnt1] = '\0';
	return (s1);
}
