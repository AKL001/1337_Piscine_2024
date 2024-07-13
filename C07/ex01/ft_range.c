#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	len;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	dest = (int *)malloc(sizeof(int) * len);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = min + i;
		i++;
	}
	return (dest);
}
