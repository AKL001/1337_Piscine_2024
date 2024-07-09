/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:23:27 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/09 10:23:28 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
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

int	main(int arc, char *str[])
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		while (0 < len)
		{
			write(1, &str[i][len - 1], 1);
			len--;
		}
		write(1, "\n", 1);
		i++;
	}
}
