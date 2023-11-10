#include<iostream>
using namespace std;

void graphTranspose(int a[][100], int n){
    int temp, i, j;
    int trans[100][100];

    for( i = 1; i<=n; i++){
        for( j = 1; j<=n; j++){
            trans[j][i] = a[i][j];
        }
    }

    for( i = 1; i <= n; i++){
        for( j = 1; j <= n; j++){
            cout << trans[i][j] <<" ";
        }
        cout << endl;
    }
}

int main(){

    int n, arr[100][100], i,j;
    cout << "size : ";
    cin>>n;
    
    cout<<"enter elements : ";
    for( i = 1; i <= n;i++){
        for( j = 1; j <= n;j++){
            cin >> arr[i][j];
        }
    }

    graphTranspose(arr,n);

}