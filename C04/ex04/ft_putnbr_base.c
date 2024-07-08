/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:49 by ablabib           #+#    #+#             */
/*   Updated: 2024/06/27 17:13:27 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
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

void	ft_putnbr_base_recursive(unsigned int unbr, char *base, int baselen)
{
	char	mysymbol;

	if (unbr >= (unsigned int)baselen)
	{
		ft_putnbr_base_recursive(unbr / baselen, base, baselen);
	}
	mysymbol = base[unbr % baselen];
	ft_putchar(mysymbol);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;

	if (!check_base(base))
		return ;
	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base_recursive((unsigned int)-nbr, base, baselen);
	}
	else
	{
		ft_putnbr_base_recursive((unsigned int)nbr, base, baselen);
	}
}
