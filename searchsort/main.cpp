#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int searchValue, vector<int> arr);
void selectionSort(vector<int> arr);

int main()
{
    // vector <int> arr = {2,4,5,7,8,9,12,14,17,19,22,25,27,28,33,37};
    // vector <int> arr = {2,4,5,7,8,9,12,14,17,19,22,25,27,28,33,37};
    // cout << binarySearch(500, arr) << endl;

    vector<int> arr = {4, 2, 6, 1, 3, 7, 5};
    // selectionSort(arr);

    return 0;
}

int binarySearch(int searchValue, vector<int> arr)
{
    int firstIndex = 0;
    int lastIndex = arr.size() - 1;
    int midIndex;

    while (lastIndex - firstIndex >= 0)
    {
        midIndex = (lastIndex + firstIndex) / 2;

        cout << firstIndex << " " << midIndex << " " << lastIndex << endl;

        if (arr[midIndex] == searchValue)
        {
            return midIndex;
        }

        if (arr[midIndex] < searchValue)
        {
            firstIndex = midIndex + 1;
        }
        else
        {
            lastIndex = midIndex - 1;
        }
    }

    return -1;
}

void selectionSort(vector<int> arr)
{
    int i = 0;
    int arraySize = arr.size();

    while (i < arraySize)
    {
        int min = i;
        for (int m = i; m < arraySize; m++)
        {
            if (arr[min] > arr[m])
            {
                min = m;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        for (int n = 0; n < arraySize; n++)
        {
            cout << arr[n] << " ";
        }
        cout << endl;
        i++;
    }
}
