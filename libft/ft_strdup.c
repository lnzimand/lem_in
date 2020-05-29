/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:29:26 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/11 12:18:17 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;

	copy = ft_strnew(ft_strlen(s1));
	if (copy)
		ft_strcpy(copy, s1);
	return (copy);
}