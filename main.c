/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:16:38 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/05 20:45:05 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int     main(void)
{
    FILE *fp = fopen("blank.txt", "r");
    int     fd = fileno(fp);
	FILE *fp2 = fopen("blank2.txt", "r");
    int     fd2 = fileno(fp2);
	char	*str;

	str = get_next_line(fd);
	printf("After everything the Finalstr is %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("After everything the Finalstr is %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("After everything the Finalstr is %s\n", str);
	free(str);
	str = get_next_line(fd2);
	printf("After everything the Finalstr is %s\n", str);
	free(str);
    return (0);
}