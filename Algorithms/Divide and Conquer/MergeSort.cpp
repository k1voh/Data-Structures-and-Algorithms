#include<iostream>
#define MAX 100
using namespace std;

void Merge(int arr[], int l, int mid, int r) {

  int n1 = mid - l + 1;
  int n2 = r - mid;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[mid + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    Merge(arr, l, m, r);
  }
}


int main() {
    int arr[MAX];
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter elements : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
