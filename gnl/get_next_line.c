/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnzimand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 08:19:56 by lnzimand          #+#    #+#             */
/*   Updated: 2019/09/16 09:30:40 by lnzimand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int		get_line(int fd, char **line, char **store)
{
	int		endl;
	char	*temp;

	temp = store[fd];
	if ((endl = (!(ft_strchr(store[fd], '\n')))))
		*line = ft_strdup(temp);
	else
		*line = ft_strsub(store[fd], 0, (ft_strchr(store[fd], '\n') - \
		store[fd]));
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store[9999];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			b;

	if (fd < 0 || !line || (!store[fd] && !(store[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(store[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[b] = '\0';
		temp = store[fd];
		store[fd] = ft_strjoin(store[fd], buffer);
		ft_strdel(&temp);
	}
	if (b < 0)
		return (b == -1 ? -1 : 0);
	get_line(fd, line, store);
	temp = ft_strchr(store[fd], '\n');
	if (temp != NULL)
		store[fd] = ft_strsub(temp, 1, ft_strlen(temp));
	else
		store[fd] = NULL;
	return (!(!store[fd] && !ft_strlen(*line)));
}
