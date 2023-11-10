#include<iostream>
using namespace std;

int count = 0; //global count variable


int linSearch(int a[], int n, int k){
    int i;
    count++;
    for(i = 0; i < n; i++){
        count++;
        count++;
        if(k == a[i]){
            count++;
            return count;
        }
    }
    count++;
    count++;
    return count;
}

int main(){


    int a[25],n,x;
    cout << "Enter number of elements";
    cin >> n;
    int i;
    cout << "Enter elements";
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Enter the number to be searched for";
    cin >> x;
    int result = linSearch(a,n,x);
    cout << result;

    return 0;
}
