/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:52:50 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/06 15:32:06 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	if (!(s1 || !s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s3 = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (s1 && s2)
	{
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
		ft_strcat(s3, "\0");
	}
	return (s3);
}
