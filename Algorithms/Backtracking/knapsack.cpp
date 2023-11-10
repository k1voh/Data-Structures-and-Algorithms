#include<iostream>
#define MAX 100
using namespace std;

class knap{
    public:
        void knapsack(int i);
        int c,n,w[MAX],p[MAX],cw = 0,cp = 0,bestp = 0;
        float bound(int i);
};

float knap::bound(int i){
    int cleft =  c - cw;
    int b = cp;
    while(i <= n && w[i] <= cleft){
        cleft -= w[i];
        b += p[i];
        i++;
    }
    if(i<=n){
        b += (p[i]/w[i])*cleft;
    }
    return b;
}

void knap::knapsack(int i){
    if(i > n){
        bestp = cp;
        return;
    }
    if(cw + w[i] <= c){
        cw += w[i];
        cp += p[i];
        knapsack(i+1);
        cw -= w[i];
        cp -= p[i]; 
    }
    if(bound(i+1) > bestp){
        knapsack(i+1);
    }
}

int main(){

    knap K;
    cout << "Enter the number of containers : ";
    cin >> K.n;

    cout << "Enter the Capacity : ";
    cin >> K.c;

    cout << "Enter the Profit and Weight : ";
    for(int i = 0; i < K.n; i++){
        cin >> K.p[i];
        cin >> K.w[i];
    }

    K.knapsack(0);

    cout << K.bestp;
}