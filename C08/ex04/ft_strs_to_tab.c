/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:30:08 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/14 14:59:21 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = _strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*dest;
	int					i;

	dest = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		dest[i].size = _strlen(av[i]);
		dest[i].str = av[i];
		dest[i].copy = _strdup(av[i]);
		i++;
	}
	dest[i].str = NULL;
	dest[i].copy = NULL;
	return (dest);
}
