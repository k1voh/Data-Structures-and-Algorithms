#include<iostream>
using namespace std;

int count = 0;

int binSearch(int arr[], int n, int x){

    int low = 0, high = n;
    count++;
    count++;

    while(low <= high){
        count++;
        count++;
        count++;
        int mid = (low+high)/2;
        if(x == arr[mid]){
            count++;
            return mid;
        }
        else if(x < arr[mid]){
            count++;
            high = mid - 1;
        }
        else{
            count++;
            low = mid + 1;
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
    int result = binSearch(a,n,x);
    cout << result << endl;

    cout << "Number of Steps : " << count;
    return 0;
}