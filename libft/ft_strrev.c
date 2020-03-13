/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:22:40 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/20 14:48:14 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	*rs;

	j = 0;
	i = ft_strlen(s) - 1;
	if (!(rs = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i >= 0)
		rs[j++] = s[i--];
	return (rs);
}
