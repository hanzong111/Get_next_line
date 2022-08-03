/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:20 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/03 14:23:47 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_info
{
	char	*finalstr;
	char	*nextstr;
	char	*buffer;
	char	*bufferstr;
	int		wc1;
	int		wc2;
	int		readwc;
}	t_info;

char	*get_next_line(int fd);
void	gnl_strlen(char *str1, char *str2, t_info *info);
char	*gnl_strjoin(char *buffer, t_info *info);
void	gnl_strcopy(char *str, char *bufferstr, int len);
void	gnl_initialize(t_info *info);
void	gnl_nextline(char *buffer, t_info *info);

#endif