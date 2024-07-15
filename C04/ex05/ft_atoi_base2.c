/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:09:18 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/15 14:09:19 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_base(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (len < 2)
		return (0);
	while (i < len)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	_validchar(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	_charpos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;
	int	len;

	result = 0;
	sign = 1;
	i = 0;
	if (!check_base(base))
		return (0);
	while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	len = _strlen(base);
	while (_vaidechar(str[i], base))
		result = result * len + _charpos(str[i++], base);
	return (result * sign);
}
