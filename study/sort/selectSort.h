#include<iostream>
// #include "Student.h"
// #include "SortTestHelper.h"
using namespace std;

// 类模板，运行时定义类型，生成具体类型对象，使我们写出来的代码应用更加广泛
template<typename T>
void selectSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    cout << endl;
}

// int main(int argc, char const *argv[])
// {
//     cout << "hellword" << endl;
//     int arr[] = {1,3,2,5,4};
//     selectSort(arr, 5);
//     for (int i=0; i < 5; i++) {
//         cout << arr[i];
//     }
//     cout << endl;


//     float arr2[] = {1.1, 6.7, 4.3 , 5.2};
//     selectSort(arr2, 4);
//     for (int i=0; i < 4; i++) {
//         cout << arr2[i] << endl;
//     }
//     cout << endl;

//     Student arr3[] = {{"a", 95}, {"b", 87}, {"c", 99}, {"d", 77}};
    
//     selectSort(arr3, 4);
//     for (int i=0; i < 4; i++) {
//         cout << arr3[i] << endl;
//     }
//     cout << endl;


//     int n = 100000;
//     int *arr4 = SortTestHelper::generateRandomArray(n, 0, n);
//     SortTestHelper::testSort("selectSort", selectSort, arr4, n);
//     //selectSort(arr4, 100);
//    // SortTestHelper::printArray(arr4, n);
//     return 0;
// }
