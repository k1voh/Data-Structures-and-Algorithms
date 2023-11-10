#include<iostream>
using namespace std;

int count = 0; //global count

int insSort(int a[], int n){

    int i,j;
    int nextkey;

    count++;
    for(i = 1; i < n; i++){
        count++;
        count++;
        nextkey = a[i];
        for(j = i - 1; j >= 0 && nextkey < a[j]; j--){
            count++;
            count++;
            a[j+1] = a[j];
        }
        count++;
        a[j+1] = nextkey;
    }

    for(i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout <<endl;
}

int main(){

    int a[100],n;
    cout << "Enter number of elements";
    cin >> n;
    int i;
    cout << "Enter elements";
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    insSort(a,n);
    cout << "no. of steps : " << count;
    return 0;
    return 0;
}
