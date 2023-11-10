// CONTAINER LOADING PROBLEM

#include<iostream>
using namespace std;

class container{
    public:
        int weight;
        int pos;

};


// GREEDY CRITERION: from the containers choose the one with the minimum weight
void bubbleSort(container *a, int n){

    int i,j;
    container temp;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j].weight > a[j+1].weight){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void contLoading(container *c, int cp, int nc){
    bubbleSort(c,nc);
    int x[100];

    int n = nc;
    for(int i = 1; i <= n; i++){
        x[i] = 0;
    }

    for(int i = 0; i < n && c[i].weight <= cp; i++){
        x[c[i].pos] = 1;
        cp = cp - c[i].weight;
    }

    cout << "The solution vector is : "<<endl;
    for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

int main(){

    int n,i;
    int cap;
    int nc;
    container arr[100];

    cout << "Enter capacity of ship : ";
    cin >> cap;

    cout << "Enter number of objects : ";
    cin >> n;
    cout << "Enter objects " <<endl;
    for(i = 0; i < n; i++){
        container c;
        cout << "Enter weight of container : ";
        cin >> c.weight;
        cout << "Enter rank of container : ";
        cin >> c.pos;
        arr[i] = c;
    }

    contLoading(arr,cap,n);


    return 0;
}
