/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:13:39 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/03 15:49:08 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strlen(char *str1, char *str2, t_info *info)
{
	int	readwc;

	readwc = info->readwc;
	if (str1)
	{
		while (*str1 != '\0')
		{
			str1++;
			info->wc1++;
		}	
	}
	while (--readwc >= 0 && *str2 != '\n')
	{
		str2++;
		info->wc2++;
	}
	if (*str2 == '\n')
		info->wc2++;
}

void	gnl_strcopy(char *str, char *bufferstr, int len)
{
	while (*str != '\0' && --len >= 0)
	{	
		*bufferstr = *str;
		bufferstr++;
		str++;
	}
}

char	*gnl_strjoin(char *buffer, t_info *info)
{
	char	*init_ptr;

	gnl_strlen(info->finalstr, buffer, info);
	if (info->wc1 == 0)
	{
		info->bufferstr = malloc(sizeof(char) * (info->wc2 + 1));
		info->bufferstr[info->wc2] = '\0';
		init_ptr = info->bufferstr;
		gnl_strcopy(buffer, info->bufferstr, info->wc2);
		gnl_nextline(buffer, info);
		info->finalstr = init_ptr;
		return (info->finalstr);
	}
	info->bufferstr = malloc(sizeof(char) * (info->wc1 + info->wc2 + 1));
	info->bufferstr[info->wc1 + info->wc2] = '\0';
	init_ptr = info->bufferstr;
	gnl_strcopy(info->finalstr, info->bufferstr, info->wc1);
	gnl_strcopy(buffer, &info->bufferstr[info->wc1], info->wc2);
	gnl_nextline(buffer, info);
	info->finalstr = init_ptr;
	return (info->finalstr);
}

void	gnl_nextline(char *buffer, t_info *info)
{
	int	wc;

	wc = info->wc2;
	if (info->readwc != info->wc2)
	{
		while (--wc >= 0)
			buffer++;
		info->wc2 = info->readwc - info->wc2;
		info->nextstr = malloc(sizeof(char) * (info->wc2 + 1));
		info->nextstr[info->wc2] = '\0';
		gnl_strcopy(buffer, info->nextstr, info->wc2);
	}
}

void	gnl_initialize(t_info *info)
{
	info->wc1 = 0;
	info->wc2 = 0;
	info->readwc = 1;
}
