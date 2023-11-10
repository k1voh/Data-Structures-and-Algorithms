//FIND MAXIMUM SUBARRAY SUM

#include<iostream>
#define MAX 100
using namespace std;

//BRUTEFORCE METHOD
int findSum(int arr[], int n){
    int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j <n ; j++){
            sum += arr[j];
        }
    }

    return sum;
}

int main(){

    int arr[MAX],n;
    int sum = 0;

    cout << "Enter size of array : ";
    cin >> n;

    cout << "Enter elements "<<endl;;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }



    cout << findSum(arr,n);

    return 0;
}
