#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j] || str[i] == '-' || str[i] == '+')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
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

	baselen = ft_strlen(base);
	if (baselen < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base_recursive((unsigned long long)(-nbr), base, baselen);
	}
	else
	{
		ft_putnbr_base_recursive((unsigned long long)nbr, base, baselen);
	}
}
