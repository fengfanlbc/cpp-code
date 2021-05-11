#include<iostream>
using namespace std;

template<typename T>
int partition(T arr[], int l , int r) {
    swap(arr[l], arr[rand()%(r-l+1) + l]);
    T e = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if(arr[i] < e){
            swap(arr[j+1], arr[i]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
    
}

template<typename T>
int partition2(T arr[], int l, int r) 
{
    swap(arr[l], arr[rand()%(r-l+1) + l]);
    T e = arr[l];
    int i = l + 1;
    int j = r;
    while(true)
    {
        while(i <= r && arr[i] < e)
        {
            i++;
        }
        while (j >= l + 1 && arr[j] > e)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[j], arr[l]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r){
    if (l >= r) {
        return;
    }
    //int j = partition(arr, l, r);
    int j = partition2(arr, l, r);
    __quickSort(arr, l, j-1);
    __quickSort(arr, j+1, r); 
}

template<typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}



//*******************

template<typename T>
void __quickSort3ways(T arr[], int l, int r){
    if (l >= r) {
        return;
    }
    swap(arr[l], arr[rand() % (r-l + 1) + l]);
    T e = arr[l];
    int lt = l; // [l, l+1...,lt ] < e
    int gt = r + 1;// [gt, gt+1...,r] > e
    int i = l + 1; //[lt+1,...,i] = e
    while( i < gt) {
        if (arr[i] < e) {
            swap(arr[lt+1], arr[i]);
            lt++;
            i++;
        }else if (arr[i] > e) {
            swap(arr[gt-1], arr[i]);
            gt--;
            // 这里不能i++， 因为swap 后原先gt-1 位置的元素还没有做过比较
            //i++;        
        }else{
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    __quickSort3ways(arr, l, lt-1);
    __quickSort3ways(arr, gt, r);
}

template<typename T>
void __quickSort3ways2(T arr[], int l, int r){
    if (l >= r) {
        return;
    }
    swap(arr[l], arr[rand() % (r-l + 1) + l]);
    T e = arr[l];
    int lt = l; // [l, l+1...,lt ] < e
    int gt = r + 1;// [gt, gt+1...,r] > e
    int i = l + 1; //[lt+1,...,i] = e
    while( i < gt) {
        if (arr[i] < e) {
            swap(arr[lt+1], arr[i]);
            lt++;
            i++;
        }else if (arr[i] > e) {
            swap(arr[gt-1], arr[i]);
            gt--;
            // 这里不能i++， 因为swap 后原先gt-1 位置的元素还没有做过比较
            //i++;        
        }else{
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    __quickSort3ways(arr, l, lt-1);
    __quickSort3ways(arr, gt, r);
}
// three ways quick sort
template<typename T>
void quickSort3ways(T arr[], int n) {
    srand(time(NULL));
    __quickSort3ways(arr, 0, n-1);
}