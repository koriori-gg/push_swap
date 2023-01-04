#include "../include/push_swap.h"

int	*coordinate_compression(int size, char **argv)
{
	int *array;
	int	i;
	int j;
	int	tmp;

	i = 0;
	array = calloc(size, sizeof(int));
	while (i < size)
	{
		array[i] = atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

//TODO: 名前考える
int	shrink_number(int *array, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == nbr)
			return (i + 1);
		i++;
	}
	return (i + 1);
}
/*
int	main(int argc, char **argv)
{
	int i, size;
	int *array;

	array = coordinate_compression(argc - 1, argv);
	i = 0;
	size = argc - 1;
	while (i < size)
	{
		printf("array[%d] : %d\n", i , array[i]);
		i++;
	}
	return(0);
}
*/