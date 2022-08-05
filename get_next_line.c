/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:53:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/05 21:10:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_checks(char *buffer)
{
	while (*buffer != '\0')
	{
		if (*buffer == '\n')
			return (1);
		else
			buffer++;
	}
	return (0);
}

char	*gnl_strsort(char *buffer, t_info *info)
{
	char	*nextstr;
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	while (*buffer != '\n' && --info->readwc >= 0)
		buffer++;
	if (info->readwc == 0)
		return (NULL);
	else
	{
		buffer++;
		info->readwc--;
		while (buffer[i++] != '\0' && --info->readwc >= 0)
			wc++;
		nextstr = malloc(sizeof(char) * (wc + 1));
		nextstr[wc] = '\0';
		gnl_strcopy(buffer, nextstr, wc, 2);
		return (nextstr);
	}
}

void	gnl_seperate(char *buffer, t_info *info)
{
	while (*buffer != '\n')
		buffer++;
	buffer++;
	info->finalstr = gnl_strdup(buffer, 2);
}

char	*get_next_line(int fd)
{
	static char	*arry[1024];
	char		*buffer;
	t_info		info;

	if (fd < 0 || fd > 1024)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	info.finalstr = NULL;
	if (arry[fd])
	{
		free(info.finalstr);
		if(gnl_checks(arry[fd]))
		{
			gnl_seperate(arry[fd], &info);
			free(arry[fd]);
			gnl_finalstr(fd, buffer, &info);
			arry[fd] = gnl_strsort(buffer, &info);
			free(buffer);
			return (info.finalstr);
		}
		else
		{
			info.finalstr = gnl_strdup(arry[fd], 2);
			free(arry[fd]);
			gnl_finalstr(fd, buffer, &info);
			arry[fd] = gnl_strsort(buffer, &info);
			free(buffer);
			return (info.finalstr);
		}
	}
	gnl_finalstr(fd, buffer, &info);
	arry[fd] = gnl_strsort(buffer, &info);
	free(buffer);
	return (info.finalstr);
}
