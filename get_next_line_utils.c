/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:39:11 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/05 20:55:24 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strlen(char *str1, char *str2, t_info *info)
{
	int	readwc;

	readwc = info->readwc;
	info->wc1 = 0;
	info->wc2 = 0;
	if (str1)
	{
		while (*str1 != '\0')
		{
			info->wc1++;
			str1++;
		}
	}
	while (--readwc >= 0)
	{
		if (*str2 == '\n')
		{
			info->wc2++;
			return ;
		}
		info->wc2++;
		str2++;
	}
	return ;
}

/* Type 1 is Partial copy */
/* Type 2 is Whole copy   */
void	gnl_strcopy(char *buffer, char *newstr, int len, int type)
{
	while (*buffer != '\0' && --len >= 0)
	{
		if (type == 1)
		{	
			if (*buffer == '\n')
			{
				*newstr = '\n';
				return ;
			}
		}
		*newstr = *buffer;
		newstr++;
		buffer++;
	}
}

char	*gnl_strdup(char *newstr, int type)
{
	int		i;
	int		wc;
	char	*finalstr;

	wc = 0;
	i = -1;
	while (newstr[++i] != '\0')
		wc++;
	finalstr = malloc(sizeof(char) * (wc + 1));
	finalstr[wc] = '\0';
	gnl_strcopy(newstr, finalstr, wc, type);
	return (finalstr);
}

void	gnl_strjoin(char *buffer, t_info *info)
{
	char	*firststr;
	char	*newstr;
	char	*init_ptr;

	gnl_strlen(info->finalstr, buffer, info);
	if (info->wc1 == 0)
	{
		firststr = malloc(sizeof(char) * (info->wc2 + 1));
		firststr[info->wc2] = '\0';
		gnl_strcopy(buffer, firststr, info->wc2, 1);
		info->finalstr = firststr;
		return ;
	}
	newstr = malloc(sizeof(char) * (info->wc1 + info->wc2 + 1));
	newstr[info->wc1 + info->wc2] = '\0';
	init_ptr = info->finalstr;
	gnl_strcopy(info->finalstr, newstr, info->wc1, 1);
	gnl_strcopy(buffer, &newstr[info->wc1], info->wc2, 1);
	free(init_ptr);
	info->finalstr = gnl_strdup(newstr, 2);
	free(newstr);
}

char	*gnl_finalstr(int fd, char *buffer, t_info *info)
{
	while ((info->readwc = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (gnl_checks(buffer))
		{
			gnl_strjoin(buffer, info);
			return (info->finalstr);
		}
		gnl_strjoin(buffer, info);
	}
	return (info->finalstr);
}
