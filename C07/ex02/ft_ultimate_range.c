/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:17:00 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/13 11:18:38 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*res;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	res = (int *)malloc(sizeof(int) * size);
	if (!res)
	{
		*range = NULL;
		return (-1);
	}
	*range = res;
	i = 0;
	while (i < size)
	{
		res[i] = min + i;
		i++;
	}
	return (size);
}
