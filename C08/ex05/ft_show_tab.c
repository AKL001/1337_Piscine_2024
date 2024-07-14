/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:05:04 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/14 15:05:11 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		_putnbr(147483648);
	}
	else if (nb < 0)
	{
		_putchar('-');
		nb = -nb;
		_putnbr(nb);
	}
	else if (nb > 9)
	{
		_putnbr(nb / 10);
		_putnbr(nb % 10);
	}
	else
		_putchar(nb + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		_putstr(par[i].str);
		_putstr("\n");
		_putnbr(par[i].size);
		_putstr("\n");
		_putstr(par[i].copy);
		_putstr("\n");
		i++;
	}
}
