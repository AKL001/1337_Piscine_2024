/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:17:28 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/15 16:17:29 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	lenght_nbr(int nbr, char *base, int lenght)
{
	int				base_lenght;
	unsigned int	nb;

	base_lenght = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		lenght++;
	}
	else
		nb = nbr;
	while (nb >= (unsigned)base_lenght)
	{
		nb /= base_lenght;
		lenght++;
	}
	lenght++;
	return (lenght);
}

void	ft_putnbr_base_v2(int nbr, char *base, char *nblen)
{
	int		lenght_base;
	long	nb;
	int		i;
	int		len_nblen;

	lenght_base = ft_strlen(base);
	len_nblen = lenght_nbr(nbr, base, 0);
	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		nblen[0] = '-';
		nb *= -1;
		i = 1;
	}
	len_nblen--;
	while (nb >= lenght_base)
	{
		nblen[len_nblen] = base[nb % lenght_base];
		nb /= lenght_base;
		len_nblen--;
	}
	if (nb < lenght_base)
		nblen[i] = base[nb];
}
