#include <iostream>

int* BubbleSort(int *arr, int n)
{
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j <= i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int* SelectSort(int *arr, int n) {
   for (int i = 0; i < n; ++i) {
       int minPos = i;
       for (int j = i + 1; j < n; ++j) {
           if (arr[minPos] > arr[j]) {
               minPos = j;
           }
       }
       int temp = arr[i];
       arr[i] = arr[minPos];
       arr[minPos] = temp;
   } 
}

int* InsertSort(int *arr, int n) {
   int i, j, temp;
   for (i = 1; i < n; ++i) {
       temp = arr[i];
       for (j = i; j > 0 && arr[j - 1] > temp; --j) {
           arr[j] = arr[j - 1];
       }
       arr[j] = temp;
   } 
}

int* QuickSort(int *arr, int start, int end) {
    if (start < end) {
        int i = start, j = end, x = arr[i];
        while (i < j) {
            for (; i < j && arr[j] >= x; --j);

            if (i < j)
                arr[i++] = arr[j];
            
            for (; i < j && arr[i] <= x; ++i);

            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        QuickSort(arr, start, x - 1);
        QuickSort(arr, x + 1, end);
    }
}

int main()
{
    int arr[5] = {4,2,7,3,1};
    //BubbleSort(arr, 5);
    //SelectSort(arr, 5);
    //InsertSort(arr, 5);
    QuickSort(arr, 0, 4);
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << ",";
    }
    return 0;
}
