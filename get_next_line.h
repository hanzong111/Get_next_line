/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:44:20 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/02 21:30:46 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>

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

void	gnl_strlen(char *str1, char *str2, t_info *info);
void	gnl_strjoin(char *buffer, t_info *info);
void	gnl_strcopy(char *str, t_info *info, int len);

#endif