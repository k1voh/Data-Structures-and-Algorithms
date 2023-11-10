#include<iostream>
using namespace std;
int count = 0; //global count

int binSearch(int a[], int h, int l, int k){
    int mid;
    mid = (h+l)/2;

    count++;
    count++;
    count++;
    if(h >= l){
        count++;
        count++;
        count++;
        if(a[mid] > k){
            count++;
            return binSearch(a, mid - 1, l, k);
        }
        else if(a[mid] < k){
            count++;
            return binSearch(a, h, mid + 1,k);
        }
        else if(a[mid] == k){
            count++;
            return mid;
        }
    }
    count++;
    return -1;
}

int main(){
    int a[100], n, x;

    cout << "Enter number of elements";
    cin >> n;
    int i;
    cout << "Enter elements";
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "Enter the number to be searched for";
    cin >> x;
    int result = binSearch(a,n,0,x);
    cout << result << endl;

    cout << "Number of Steps : " << count;
    return 0;
}
