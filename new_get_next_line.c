/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:53:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/04 17:41:10 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*arry[1024];
	char		*buffer;
	char		*finalstr;
	t_info		info;
	
	if (fd < 0 || fd > 1024)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	if (arry[fd])
	{
		if(gnl_checks(arry[fd]))
		{
			finalstr = gnl_seperate(arry[fd]);
			arry[fd] = gnl_strsort(fd, buffer, arry, info);
			return (finalstr);
		}
		else
			info.finalstr = arry[fd];
	}
	finalstr = gnl_finalstr(fd, buffer, arry, info);
	arry[fd] = gnl_strsort(fd, buffer, arry, info);
	return (finalstr);
}