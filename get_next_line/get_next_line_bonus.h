/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:47:01 by szine-            #+#    #+#             */
/*   Updated: 2023/12/21 23:04:29 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t numelement, size_t elementsize);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char **s1, char *s2);
size_t	ft_strlen(char *str);
void	*ft_memset(void *b, int x, size_t len);
char	*get_next_line(int fd);

#endif