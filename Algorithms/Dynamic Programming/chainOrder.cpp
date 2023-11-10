//Write a program to find the optimal order of multiplication in a chain of matrices and analyze the complexity

#include<iostream>
#define MAX 100
#define MIN INT_MAX
using namespace std;

int matrixOrderChain(int chain[], int i, int j){

    int cnt, minNum = MIN;

    if(i == j){
        return 0;
    }

    for(int k = i; k < j; k++){
        cnt = matrixOrderChain(chain,i,k) + matrixOrderChain(chain, k+1, j) + chain[i-1]*chain[k]*chain[j];

        minNum = min(cnt,minNum);
    }

    return minNum;
}

int main(){
    int arr[MAX], n;

    cout << "Enter size of array : ";
    cin >> n;

    cout << "Enter Elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << matrixOrderChain(arr, 1, n-1);

    return 0;
}
