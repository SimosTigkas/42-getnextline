/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:03:44 by stigkas           #+#    #+#             */
/*   Updated: 2023/12/08 11:43:56 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	create_list(t_list	**list, int fd);
void	append(t_list **list, char *buf, int fd);
t_list	*ft_lstlast(t_list *lst);
char	*get_line(t_list *list);
void	cp_str(t_list *list, char *str);
void	clean_the_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
int		len_till_nl(t_list *list);
int		got_newline(t_list *list);

#endif