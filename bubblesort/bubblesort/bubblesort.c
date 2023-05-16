#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("array[%d]: %d\n", i, array[i]);
}

void replace(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compareUp(int x, int y)
{
    return x > y;
}

int compareDown(int x, int y)
{
    return x < y;
}

int compareAbsUp(int x, int y)
{
    return abs(x) > abs(y);
}

int compareAbsDown(int x, int y)
{
    return abs(x) < abs(y);
}


void sort_array(int array[], int n, int (*compare)(int, int))
{
    if (array == NULL)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (compare(array[j], array[j + 1]))
                replace(&array[j], &array[j + 1]);
}

int main()
{
    srand(time(NULL));
    while (1)
    {
        int n;
        printf("\nsize of array: ");
        scanf("%d", &n);


        int a, b;
        printf("\nwrite, please value range [a, b]: ");
        scanf("%d %d", &a, &b);

        int* array = malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++)
        {
            array[i] = (rand() % (b - a + 1)) + a;
        }

        print_array(array, n);

        int mod;
        printf("\nchoose, please, sorting order\n(1=up, 2=down, 3=up for abs, 4=down for abs): ");
        scanf("%d", &mod);
        switch (mod)
        {
        case 1:
            sort_array(array, n, compareUp);
            break;

        case 2:
            sort_array(array, n, compareDown);
            break;

        case 3:
            sort_array(array, n, compareAbsUp);
            break;

        case 4:
            sort_array(array, n, compareAbsDown);
            break;
        }

        print_array(array, n);

        free(array);

        int quit;

        printf("\n1=repeat, 0=end of program: ");
        scanf("%d", &quit);

        if (quit == 0)
        {
            break;
        }
    }

    return 0;
}
