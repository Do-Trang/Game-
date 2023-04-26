#ifndef GLOBAL_Random
#define GLOBAL_Random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class Random
{
public:
    void Swap(int *number_1, int *number_2);
    void ShuffleArray(int *arr, int n);
    void generate(int arr[], int n);

private:
};

void Random ::Swap(int *number_1, int *number_2)
{
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}

void Random ::ShuffleArray(int *arr, int n)
{
    srand(time(NULL));

    int minPosition;
    int maxPosition = n - 1;
    int swapPosition;

    int i = 0;
    while (i < n - 1)
    {
        minPosition = i + 1;
        swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;

        Swap(&arr[i], &arr[swapPosition]);
        i++;
    }
}
void Random::generate(int arr[], int n)
{

    this->ShuffleArray(arr, n);
}
#endif
