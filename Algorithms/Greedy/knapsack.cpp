// 0/1 KNAPSACK PROBLEM

#include<iostream>
using namespace std;

class container{
    public:
        int weight;
        int profit;
        int pos;

};

// GREEDY CRITERION: from the containers choose the one with the minimum weight
void weightSort(container *a, int n){

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

    cout <<endl;
    for(i = 0; i < n; i++){
        cout << a[i].weight <<" ";
    }
    cout <<endl;
}

void profitSort(container *a, int n){

    int i,j;
    container temp;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j].profit < a[j+1].profit){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout <<endl;
    for(i = 0; i < n; i++){
        cout << a[i].weight <<" ";
    }
    cout <<endl;
}

void profdenseSort(container *a, int n){

    int i,j;
    container temp;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n - i - 1; j++){
            if((a[j].profit/a[j].weight) < (a[j+1].profit/a[j+1].weight)){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout <<endl;
    for(i = 0; i < n; i++){
        cout << a[i].weight <<" ";
    }
    cout <<endl;
}

void contLoading_weight(container *c, int cp, int nc){
    weightSort(c,nc);
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

void contLoading_profit(container *c, int cp, int nc){
    profitSort(c,nc);
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

void contLoading_profdense(container *c, int cp, int nc){
    profdenseSort(c,nc);
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
        cout << "Enter profit of container : ";
        cin >> c.profit;
        cout << "Enter rank of container : ";
        cin >> c.pos;
        arr[i] = c;
    }

    contLoading_weight(arr,cap,n);
    contLoading_profit(arr,cap,n);
    contLoading_profdense(arr,cap,n);

    return 0;
}
