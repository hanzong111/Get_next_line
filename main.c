/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:18:45 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/02 21:33:13 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	try(int fd, char *buffer)
{
	int	value; 
	int i = -1;

	value = read (fd, buffer, BUFFER_SIZE);
	while ( buffer[++i] != '\0')
		printf("Line[%d] : %c\n", i, buffer[i]);
	printf("IN FUNCTION :%d\n", value);
}

int	main(void)
{
	// char	buffer[BUFFER_SIZE];
	// FILE *fp = fopen("blank.txt", "r");
	// int	fd = fileno(fp);
	// int	i = -1;
	// while ( ++i <= 1)
	// 	try(fd, buffer);
	t_info	info;
	char	*str1 = "hahaha";
	char	*str2 = "boomh\nNONO";

	info.finalstr = str1;
	info.wc1 = 0;
	info.wc2 = 0;
	gnl_strjoin(str2, &info);
	printf("Final str is : %s", info.finalstr);
	return (0);
}
