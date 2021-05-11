#include<iostream>
#include "SortTestHelper.h"
#include "selectSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quickSort.h"
using namespace std;


template<typename T>
void insertSort(T arr[], int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 1; i < n; i++) {
        // 尽量避免交换
        // 1. 先保存待处理元素
        // 2. 如果待处理元素比前一个元素小，先不交换，而是将前一个元素的值直接赋值给当前位置
        // 3. 最后将待处理元素赋值给当前停止位置
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--) {
            //swap(arr[j], arr[j-1]);
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

template<typename T>
void insertSort2(T arr[], int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 1; i < n; i++) {
        int j;
        for (j = i; j > 0 && arr[j-1] > arr[j]; j--) {
            swap(arr[j], arr[j-1]);
            //arr[j] = arr[j-1];
        }
    }
}

int main()
{
    int n = 300000;
    int m = 10;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, m);
    //int *arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int *arr6 = SortTestHelper::copyIntArray(arr1, n);
    int *arr7 = SortTestHelper::copyIntArray(arr1, n);
    int *arr8 = SortTestHelper::copyIntArray(arr1, n);
    int *arr9 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("quickSort3ways", quickSort3ways, arr9, n);
    SortTestHelper::testSort("mergeSortBU", mergeSortBU, arr7, n);
    SortTestHelper::testSort("mergeSort", mergeSort, arr6, n);
    SortTestHelper::testSort("quickSort", quickSort, arr8, n);
    
    // SortTestHelper::testSort("insertSort", insertSort, arr1, n);
    // SortTestHelper::testSort("insertSort2", insertSort2, arr2, n);
    // SortTestHelper::testSort("selectSort", selectSort, arr3, n);
    // SortTestHelper::testSort("bubbleSort", bubbleSort, arr4, n);
    // SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr5, n);
    

    delete arr1;
    delete arr2;
    delete arr3;
    delete arr4;
    delete arr5;
    delete arr6;
    delete arr7;
    delete arr8;
    delete arr9;

    return 0;
}
 