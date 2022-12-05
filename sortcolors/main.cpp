#include <iostream>

using namespace std;

/**
 * @brief - Sorts colors given the colors 'r', 'w' and 'b'
 *
 * @param arr - Array of characters that are the sorted.
 * @param n - Number of characters or rather elements in the array.
 */
void sortColors(char arr[], int n);

void printArrays(char arr[], int arraySize);
//{'b', 'b', 'r', 'w', 'r', 'b', 'b', 'r', 'w', 'w'};
char testArray[] = {'b', 'b', 'r', 'w', 'r', 'b', 'b', 'r', 'w', 'b'};
int arraySize = 10;

int main()
{

    sortColors(testArray, arraySize);

    return 0;
}

void sortColors(char arr[], int n)
{

    int i = 0;
    int k = n - 1;
    int j = 0;

    while (j != k)
    {
        if (arr[j] == 'b')
        {
            swap(arr[j], arr[k]);
            k--;
        }
        
        if (arr[j] == 'r')
        {

            swap(arr[j], arr[i]);
            i++;
        }

        j++;
    }
}

void printArrays(char arr[], int arraySize)
{

    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << ", ";
    }
}