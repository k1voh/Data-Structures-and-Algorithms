#include<iostream>
#define MAX 100
using namespace std;

class Loading{

    public:
        int n,w[MAX],c,bestw = 0,bestx[MAX] = {0},cw = 0,r = 0,x[MAX] = {0};

        int MaxLoading(){
            for(int i = 1; i <= n; i++){
                r += w[i];
            }
            maxLoading(1);
            for(int i = 1; i <= n; i++){
                cout << bestx[i] << " ";
            }
            cout <<endl;
            return bestw;
        }

        void maxLoading(int i){
            if(i > n){
                for(int j = 1; j <= n; j++){
                    bestx[j] = x[j];
                }
                bestw = cw;
                return;
            }

            r -= w[i];
            if(cw + w[i] <= c){
                x[i] = 1;
                cw += w[i];
                maxLoading(i+1);
                cw -= w[i];
            }
            if(cw + r >bestw){
                x[i] = 0;
                maxLoading(i+1);
                r+=w[i];
            }
        }
};


int main(){

    Loading L;

    cout << "Enter number of containers : ";
    cin >> L.n;

    cout << "Enter Capacity : ";
    cin >> L.c;

    cout << "Enter Weight : ";
    for(int i = 1; i <= L.n; i++){
        cin >> L.w[i];
    }

    cout << L.MaxLoading();

    return 0;
}