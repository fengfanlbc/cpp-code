#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;

namespace SortTestHelper {

    int * generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

     int * generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        for(int i = 0; i < swapTimes; i++) {
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for(int i = 0;i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    template<typename T>
    bool isSorted (T arr[], int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t start_time = clock();
        sort(arr, n);
        clock_t end_time = clock();
        assert(isSorted(arr, n));
        cout << sortName << ":" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
        return;
    }

    int* copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
}
