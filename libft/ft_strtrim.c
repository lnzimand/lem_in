/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:37:34 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/10 11:26:09 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		bgn;
	int		end;
	int		len;

	if (!s)
		return (NULL);
	bgn = 0;
	while (s[bgn] != '\0' && (s[bgn] == 32 || s[bgn] == 9 || s[bgn] == 10))
		bgn++;
	if (s[bgn] == '\0')
		return ("\0");
	end = ft_strlen(s);
	while (s[end] == 32 || s[end] == 9 || s[end] == 10 || s[end] == '\0')
		end--;
	len = end - bgn;
	return (ft_strsub(s, bgn, len + 1));
}
