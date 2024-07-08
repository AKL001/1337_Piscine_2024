/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteractive_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.your42net>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:27:39 by ablabib           #+#    #+#             */
/*   Updated: 2024/07/07 16:27:54 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		result;
	int		i;

	if (nb < 0)
	{
		return (0);
	}
	result = 1;
	i = 0;
	while (i <= nb)
	{
		result *= i;
		i++;
	}
	return (result);
}
