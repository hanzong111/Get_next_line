/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:13:39 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/02 21:30:33 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strlen(char *str1, char *str2, t_info *info)
{
	if (str1)
	{
		while (*str1 != '\0')
		{
			str1++;
			info->wc1++;
		}	
	}
	while (*str2 != '\0' && *str2 != '\n')
	{
		str2++;
		info->wc2++;
	}
	if (*str2 == '\n')
		info->wc2++;
}

void	gnl_strcopy(char *str, t_info *info, int len)
{
	while (*str != '\0' && --len>= 0)
	{	
		*info->bufferstr = *str;
		info->bufferstr++;
		str++;
	}
}

void	gnl_strjoin(char *buffer, t_info *info)
{
	char	*init_ptr;

	gnl_strlen(info->finalstr, buffer, info);
	if (info->wc1 == 0)
	{
		info->bufferstr = malloc(sizeof(char) * (info->wc2 + 1));
		init_ptr = info->bufferstr;
		gnl_strcopy(buffer, info, info->wc1);
		info->finalstr = init_ptr;
		free(init_ptr);
		return ;
	}
	info->bufferstr = malloc(sizeof(char) * (info->wc1 + info->wc2 + 1));
	init_ptr = info->bufferstr;
	gnl_strcopy(info->finalstr, info, info->wc1);
	// free(info->finalstr);
	gnl_strcopy(buffer, info, info->wc2);
	*info->bufferstr = '\0';
	info->finalstr = init_ptr;
}
