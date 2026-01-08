#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	is_duplicate(int *arr, int size, int num)
{
    int	i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == num)
            return (1);
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
    int	count;
    int	*numbers;
    int	i;
    int	num;

    if (argc != 2)
    {
        printf("Usage: %s <count>\n", argv[0]);
        return (1);
    }
    count = atoi(argv[1]);
    if (count <= 0)
    {
        printf("Count must be positive\n");
        return (1);
    }
    numbers = malloc(sizeof(int) * count);
    if (!numbers)
        return (1);
    srand(time(NULL));
    i = 0;
    while (i < count)
    {
        num = rand() % (count * 10) - (count * 5);
        if (!is_duplicate(numbers, i, num))
        {
            numbers[i] = num;
            printf("%d", num);
            if (i < count - 1)
                printf(" ");
            i++;
        }
    }
    printf("\n");
    free(numbers);
    return (0);
}