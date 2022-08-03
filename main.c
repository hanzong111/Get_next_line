/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:18:45 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/03 14:38:50 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	FILE *fp = fopen("blank.txt", "r");
	int	fd = fileno(fp);
	char *str;

	str = get_next_line(fd);
	printf("current line is %s\n", str);
	return (0);
}

