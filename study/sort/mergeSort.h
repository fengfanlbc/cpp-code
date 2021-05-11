#include<iostream>
using namespace std;

template<typename T>
void __merge(T arr[], T aux[], int l, int mid, int r) {
    // 用一个临时空间存储这些元素,避免在原有空间排序时，打乱数组
    // 最好不要在这个位置申请空间，容易造成oom
    // T aux[r-l+1];
    for(int i = l; i <= r; i++){
        //在merge时申请空间，需要考虑offset
        //aux[i-l] = arr[i];
        aux[i] = arr[i];

    }

    // 定义左右边界
    int i = l;
    int j = mid + 1;
    for(int k = l; k <= r; k++) {
        if(i > mid){
            arr[k] = aux[j];
            j++;
        }else if(j > r){
            arr[k] = aux[i];
            i++;
        }else if(aux[i] < aux[j]) {
            arr[k] = aux[i];
            i++;
        }else{
            arr[k] = aux[j];
            j++;
        }
    } 
}

template<typename T>
// 对[l, r]进行归并
void __mergeSort(T arr[], T aux[], int l, int r) {
    // 这里还可以作一定优化，如果元素个数小于10个，那么使用插入排序

    if (l >= r){
        return;
    }
    int mid = (r + l) / 2;
    __mergeSort(arr, aux, l, mid);
    __mergeSort(arr, aux, mid+1, r);
    // 小优化，对于近乎有序的数组，归并前可以先判断，左数组最后一个元素是否比右数组第一个元素大，大才归并
    if (arr[mid] > arr[mid+1]) {
        __merge(arr, aux, l, mid, r);
    }
    
}

template<typename T>
void mergeSort(T arr[], int n) {

    // 在这个直接申请空间，然后作为参数传递, T aux[n] = new T[n] 与下面的区别是? 
    T *aux = new T[n];
    __mergeSort(arr, aux, 0, n-1);
    delete aux;
}

template<typename T>
void mergeSortBU(T arr[], int n){
    T *aux = new T[n];
    // size 表示 归并元素最大间距
    for (int size = 1; size < n; size += size)
    {   
        // i 表示每次归并时首个元素的下标
        for (int i = 0; i + size  < n; i += size + size){
            __merge(arr, aux, i, i+size-1, min(i+2*size-1, n-1));
        }
    }
    
}
