/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:49:38 by stigkas           #+#    #+#             */
/*   Updated: 2023/12/08 09:03:07 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) == -1)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	clean_the_list(&list);
	return (next_line);
}

void	cp_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

void	clean_the_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[j++] = last_node->str_buf[i];
	buf[j] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	got_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}
