/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:14:08 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/03 15:55:57 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_info		info;
	char		*buffer;
	static char	*nextstr;
	static int	linecount;

	if (linecount > 0)
		info.finalstr = nextstr;
	gnl_initialize(&info);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	info.readwc = read(fd, buffer, BUFFER_SIZE);
	gnl_strjoin(buffer, &info);
	if (info.nextstr)
		nextstr = info.nextstr;
	printf("Next line is %s\n", nextstr);
	linecount++;
	return (info.finalstr);
}
