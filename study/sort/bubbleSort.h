#include<iostream>
// #include "Student.h"
// #include "SortTestHelper.h"
using namespace std;

// 类模板，运行时定义类型，生成具体类型对象，使我们写出来的代码应用更加广泛
template<typename T>
void bubbleSort(T arr[], int n) {
    // 判断是否发生过交换, 避免已经有序时还进行交换
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < n; i++)
        {
            if (arr[i-1] > arr[i]) {
                swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);  
}

template<typename T>
void bubbleSort2(T arr[], int n) {
    // 判断是否发生过交换, 避免已经有序时还进行交换
    int newn;
    do
    {
        newn = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i-1] > arr[i]) {
                swap(arr[i-1], arr[i]);
                newn = i;
            }
        }
        n = newn;
    } while (newn > 0);  
}
