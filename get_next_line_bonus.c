/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:53:05 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/12 18:48:53 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_checks(char *buffer)
{
	if (buffer != NULL)
	{
		while (*buffer != '\0')
		{
			if (*buffer == '\n')
				return (1);
			else
				buffer++;
		}
	}
	return (0);
}

char	*gnl_strsort(char *buffer, t_info *info)
{
	char	*nextstr;
	int		wc;
	int		i;
	int		readwc;

	wc = 0;
	i = 0;
	readwc = info->readwc;
	while (*buffer != '\n' && --readwc >= 0)
		buffer++;
	if (info->readwc == 0 && !info->finalstr)
	{
		free(info->finalstr);
		info->finalstr = NULL;
		return (NULL);
	}
	else
	{
		buffer++;
		readwc--;
		while (buffer[i++] != '\0' && --readwc >= 0)
			wc++;
		nextstr = malloc(sizeof(char) * (wc + 1));
		nextstr[wc] = '\0';
		gnl_strcopy(buffer, nextstr, wc, 2);
		return (nextstr);
	}
}

void	gnl_seperate(char *buffer, t_info *info)
{
	int		wc;
	int		i;

	i = 0;
	wc = 0;
	while (buffer[wc] != '\n')
		wc++;
	wc++;
	info->finalstr = malloc(sizeof(char) * (wc + 1));
	info->finalstr[wc] = '\0';
	while (--wc >= 0)
	{
		info->finalstr[i] = buffer[i];
		i++;
	}
	if (buffer[i])
	{
		info->nextstr = gnl_strdup(&buffer[i], 2);
		free(buffer);
		return ;
	}
	if (!buffer[i])
	{
		info->nextstr = NULL;
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*arry[1024];
	char		*buffer;
	t_info		info;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	info.finalstr = NULL;
	if (arry[fd])
	{
		free(info.finalstr);
		if (gnl_checks(arry[fd]))
		{
			gnl_seperate(arry[fd], &info);
			arry[fd] = info.nextstr;
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
