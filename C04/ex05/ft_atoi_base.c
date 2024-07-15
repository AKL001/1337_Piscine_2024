
int _strlen(char *str)
{	
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}
int	check_base(char *str)
{
	int	i;
	int	j;
	int	len;

	len = _strlen(str);
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

int _char_pos(char c, char *base)
{
	int  i;
	i = 0;
	while (base[i])
	{
		if(base[i] == c)
			return i;
		i++;
	}
	return -1;
}

int 	ft_atoi_base(char *str, char *base)
{
	int res = 0;
	int sign = 1;
	int i , pos, base_len;
	i = 0;
	if(!check_base(base))
		return 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	base_len = _strlen(base);
	while(str[i])
	{
		pos = _char_pos(str[i],base);
		if (pos == -1)
			return 0;
		res = res * base_len + pos;
		i++;
	}

	return res * sign;
}
