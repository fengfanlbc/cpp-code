#include <iostream>
using namespace std;
int merge(int arr[], int aux[], int l, int mid, int r) {
    for (int i = l; i <= r; i++)
    {
        aux[i] = arr[i];
    }
    int count = 0;
    int i = l;
    int j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid)       
        {   
            arr[k] = aux[j];
            j++;
        }else if(j > r){
            arr[k] = aux[i];
            i++;
        }else if (aux[i] <= aux[j])
        {
            arr[k] = aux[i];
            i++;
        }else {
            arr[k] = aux[j];
            j++;
            count += mid - i + 1;
        }
        
    }
    return count;
}

int __reversePairCount(int arr[], int aux[], int l, int r){
    if (l >= r) {
        return 0;
    }
    int mid = l + (r - l + 1) / 2 ;
    int lc = __reversePairCount(arr, aux, l, mid-1);
    int rc = __reversePairCount(arr ,aux, mid, r);
    int mc = merge(arr, aux, l, mid-1, r);
    return lc + rc + mc;
}


int reversePairCount(int arr[], int n){
    int *aux = new int[n];
    return __reversePairCount(arr, aux, 0 ,n-1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,5,7,3,2,1};
    int res = reversePairCount(arr, 7);
    cout << "res:" << res << endl;
    return 0;
}
