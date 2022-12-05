#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2);
vector<int> mergeSort(vector<int> arr);
vector<int> threeWayMerge(vector<int> arr1, vector<int> arr2, vector<int> arr3);
vector<int> threeWayMergeSort(vector<int> arr);

void printArray(vector<int> arr);

int main()
{
    /*
    // Merge function tests
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    vector<int> mergedArray = merge(arr1, arr2);

    int size1 = (int)mergedArray.size();
    for (int i = 0; i < size1; i++)
    {
        cout << mergedArray[i] << " ";
    }

    // merge sort function tests
    vector<int> arr = {10, 9, 4, 5, 3, 2, 7, 8, 6, 1};
    vector<int> sorted = mergeSort(arr);
    int size2 = sorted.size();

    for (int i = 0; i < size2; i++)
    {
        cout << sorted[i] << " ";
    }

    // ThreeWayMerge function tests
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {15, 25, 35, 45, 55, 65, 75};
    vector<int> arr3 = {17, 27, 37, 47, 57, 67, 77, 87, 97};

    vector<int> result = threeWayMerge(arr1, arr2, arr3);
    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i] << " ";
    }

    */

    // ThreeWayMergeSort function tests
    vector<int> arr = {524, 400, 945, 522, 400, 43, 617, 780, 641, 588, 94, 102, 513, 758, 376, 905, 759, 47, 533, 335};
    vector<int> result2 = threeWayMergeSort(arr);
    int size = (int)result2.size();
    for (int i = 0; i < size; i++)
    {
        cout << result2[i] << " ";
    }

    return 0;
}

vector<int> merge(vector<int> arr1, vector<int> arr2)
{

    vector<int> sortedArray;

    int arr1Size = (int)arr1.size();
    int arr2Size = (int)arr2.size();

    int arr1Index = 0, arr2Index = 0;

    while (arr1Index < arr1Size && arr2Index < arr2Size)
    {

        if (arr1[arr1Index] <= arr2[arr2Index])
        {
            sortedArray.push_back(arr1[arr1Index]);
            arr1Index++;
        }
        else
        {
            sortedArray.push_back(arr2[arr2Index]);
            arr2Index++;
        }
    }

    while (arr1Index < arr1Size)
    {
        sortedArray.push_back(arr1[arr1Index]);
        arr1Index++;
    }

    while (arr2Index < arr2Size)
    {
        sortedArray.push_back(arr2[arr2Index]);
        arr2Index++;
    }

    return sortedArray;
}

vector<int> mergeSort(vector<int> arr)
{

    vector<int> sortArray;

    int arraySize = (int)arr.size();

    if (arraySize == 1)
    {
        vector<int> base;
        base.push_back(arr[0]);
        return base;
    }
    else
    {
        int mid = (arraySize - 1) / 2;

        vector<int> tempArray1 = vector<int>(arr.begin(), arr.begin() + mid + 1);
        vector<int> a = mergeSort(tempArray1);

        vector<int> tempArray2 = vector<int>(arr.begin() + mid + 1, arr.begin() + arraySize);

        vector<int> b = mergeSort(tempArray2);

        vector<int> merged = merge(a, b);

        sortArray.insert(sortArray.begin(), merged.begin(), merged.end());
    }

    return sortArray;
}

vector<int> threeWayMerge(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    vector<int> sortedArray;

    int arr1Size = (int)arr1.size();
    int arr2Size = (int)arr2.size();
    int arr3Size = (int)arr3.size();

    int arr1Index = 0, arr2Index = 0, arr3Index = 0;

    while (arr1Index < arr1Size && arr2Index < arr2Size && arr3Index < arr3Size)
    {

        if (arr1[arr1Index] < arr2[arr2Index])
        {
            if (arr1[arr1Index] < arr3[arr3Index])
            {
                sortedArray.push_back(arr1[arr1Index]);
                arr1Index++;
            }
            else
            {
                sortedArray.push_back(arr3[arr3Index]);
                arr3Index++;
            }
        }
        else
        {
            if (arr2[arr2Index] < arr3[arr3Index])
            {
                sortedArray.push_back(arr2[arr2Index]);
                arr2Index++;
            }
            else
            {
                sortedArray.push_back(arr3[arr3Index]);
                arr3Index++;
            }
        }
    }

    while (arr1Index < arr1Size && arr2Index < arr2Size)
    {
        if (arr1[arr1Index] < arr2[arr2Index])
        {
            sortedArray.push_back(arr1[arr1Index]);
            arr1Index++;
        }
        else
        {
            sortedArray.push_back(arr2[arr2Index]);
            arr2Index++;
        }
    }

    while (arr1Index < arr1Size && arr3Index < arr3Size)
    {
        if (arr1[arr1Index] < arr3[arr3Index])
        {
            sortedArray.push_back(arr1[arr1Index]);
            arr1Index++;
        }
        else
        {
            sortedArray.push_back(arr3[arr3Index]);
            arr3Index++;
        }
    }

    while (arr2Index < arr2Size && arr3Index < arr3Size)
    {
        if (arr2[arr2Index] < arr3[arr3Index])
        {
            sortedArray.push_back(arr2[arr2Index]);
            arr2Index++;
        }
        else
        {
            sortedArray.push_back(arr3[arr3Index]);
            arr3Index++;
        }
    }

    while (arr1Index < arr1Size)
    {
        sortedArray.push_back(arr1[arr1Index]);
        arr1Index++;
    }

    while (arr2Index < arr2Size)
    {
        sortedArray.push_back(arr2[arr2Index]);
        arr2Index++;
    }

    while (arr3Index < arr3Size)
    {
        sortedArray.push_back(arr3[arr3Index]);
        arr3Index++;
    }

    return sortedArray;
}

vector<int> threeWayMergeSort(vector<int> arr)
{

    int arraySize = (int)arr.size();
    vector<int> sortedArray;

    if (arraySize == 1)
    {
        vector<int> base;
        base.push_back(arr[0]);
        return base;
    }
    else if (arraySize == 2)
    {
        vector<int> base;
        if (arr[0] < arr[1])
        {
            base.push_back(arr[0]);
            base.push_back(arr[1]);
        }
        else
        {
            base.push_back(arr[1]);
            base.push_back(arr[0]);
        }
        return base;
    }
    else
    {
        int firstMid = (arraySize - 1) / 3;
        int secondMid = (2 * (arraySize - 1)) / 3;

        vector<int> a = threeWayMergeSort(vector<int>(arr.begin(), arr.begin() + firstMid + 1));

        vector<int> b = threeWayMergeSort(vector<int>(arr.begin() + firstMid + 1, arr.begin() + secondMid + 1));

        vector<int> c = threeWayMergeSort(vector<int>(arr.begin() + secondMid + 1, arr.begin() + arraySize));

        vector<int> merged = threeWayMerge(a, b, c);

        sortedArray.insert(sortedArray.end(), merged.begin(), merged.end());
    }

    return sortedArray;
}
