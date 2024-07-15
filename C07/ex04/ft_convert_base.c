/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:17:21 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/15 16:18:35 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base_v2(int nbr, char *base, char *nbrf);
int		lenght_nbr(int nbr, char *base, int lenght);

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == 43
			|| str[i] == 45)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nb_base(char str, char *base)
{
	int	nb;

	nb = 0;
	while (base[nb] != '\0')
	{
		if (str == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	whitespaces(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] != '\0') && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count;
	int	nb;
	int	nb2;
	int	base_lenght;

	nb = 0;
	i = 0;
	base_lenght = check_base(base);
	if (base_lenght >= 2)
	{
		count = whitespaces(str, &i);
		nb2 = nb_base(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * base_lenght) + nb2;
			i++;
			nb2 = nb_base(str[i], base);
		}
		return (nb *= count);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*finalnbr;
	int		dcnum;
	int		lenght_nb;

	if (check_base(base_to) == 0 || check_base(base_from) == 0)
		return (0);
	dcnum = ft_atoi_base(nbr, base_from);
	lenght_nb = lenght_nbr(dcnum, base_to, 0);
	finalnbr = (char *)malloc(sizeof(char) * (lenght_nb + 1));
	if (!finalnbr)
		return (0);
	ft_putnbr_base_v2(dcnum, base_to, finalnbr);
	finalnbr[lenght_nb] = '\0';
	return (finalnbr);
}
