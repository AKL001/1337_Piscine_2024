/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:41:43 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/13 14:41:45 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	_total_len(char **strs, int size, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += _strlen(strs[i]);
		if (i < size - 1)
		{
			total_len += _strlen(sep);
		}
		i++;
	}
	return (total_len);
}

char	*_strcpy(char *dest, char *srs)
{
	int	i;

	i = 0;
	while (srs[i])
	{
		dest[i] = srs[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	_main_str(int size, char **strs, char *res, char *sep)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < size)
	{
		_strcpy(res + j, strs[i]);
		j += _strlen(strs[i]);
		if (i < size - 1)
		{
			_strcpy(res + j, sep);
			j += _strlen(sep);
		}
		i++;
	}
	res[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	char	*res;
	char	*str;

	if (size <= 0)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	total_len = _total_len(strs, size, sep);
	res = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	res[total_len] = '\0';
	_main_str(size, strs, res, sep);
	return (res);
}
