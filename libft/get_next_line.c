/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:05:36 by ybelilov          #+#    #+#             */
/*   Updated: 2017/01/19 19:05:41 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*lstnew(char *content, int fd)
{
	t_lst *p;

	p = malloc(sizeof(t_lst));
	if (!p)
		return (NULL);
	p->content = ft_strcpy(ft_strnew(ft_strlen(content)), content);
	p->fd = fd;
	p->next = NULL;
	return (p);
}

int		checker(t_lst *list, char **line, int r)
{
	char *n;

	n = ft_strchr(list->content, '\n');
	if (n == NULL && r == 0 && list->content[0] != '\0')
	{
		*line = ft_strcpy(ft_strnew(ft_strlen(list->content)), list->content);
		free(list->content);
		return (1);
	}
	if (list->content[0] == '\0' && r == 0)
	{
		free(list->content);
		return (0);
	}
	*line = ft_strncpy(ft_strnew(n - list->content), list->content,
									n - list->content);
	list->content = ft_strcpy(ft_strnew(ft_strlen(n) - 1), n + 1);
	return (1);
}

int		ft_while(int fd, char *content, t_lst *list, char **line)
{
	int r;

	r = 0;
	while ((r = read(fd, content, BUFF_SIZE)) > -1 && fd > -1)
	{
		while (list->next && list->fd != fd && list != NULL)
			list = list->next;
		if (list == NULL)
			list = lstnew(content, fd);
		else if (list->next == NULL && list->fd != fd)
		{
			list->next = lstnew(content, fd);
			list = list->next;
		}
		else if (list->content == NULL && r == 0)
			return (0);
		else
			list->content = ft_strjoin(list->content, content);
		if (ft_strchr(list->content, '\n') || r == 0)
			return (checker(list, line, r));
		ft_strclr(content);
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_lst	listbeg;
	t_lst			*list;
	char			*content;

	list = &listbeg;
	content = ft_strnew(BUFF_SIZE);
	return (ft_while(fd, content, list, line));
}
