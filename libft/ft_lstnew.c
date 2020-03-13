/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:51:38 by lnzimand          #+#    #+#             */
/*   Updated: 2019/06/19 13:36:40 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;
	t_list	*lst;

	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = (void*)content;
		temp->content_size = content_size;
	}
	temp->next = NULL;
	lst = temp;
	free(temp);
	return (lst);
}
