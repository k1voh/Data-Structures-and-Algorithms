#include<iostream>
#define MAX 100
using namespace std;

int divide(int arr[], int low, int high){

    int temp;
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i+1);
}


void quickSort(int arr[], int low, int high){

    if(low < high){
        int pivot = divide(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr, pivot+1,high);
    }

}

int main(){
    int arr[MAX];
    int n;

    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter Elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
