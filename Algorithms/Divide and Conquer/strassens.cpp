#include<iostream>
#define MAX 100
using namespace std;

void multiply(int a[MAX][MAX], int b[MAX][MAX],int c[MAX][MAX],int row_start,int row_end, int col_start,int col_end){

    int D,E,F,G,H,I,J;
    int C1,C2,C3,C4;

    int a1 = a[row_start][col_start], a2 = a[row_start][col_end-1], a3 = a[row_end-1][col_start], a4 = a[row_end-1][col_end-1];
    int b1 = b[row_start][col_start], b2 = b[row_start][col_end-1], b3 = b[row_end-1][col_start], b4 = b[row_end-1][col_end-1];



    D = a1 * (b2 - b4);
    E = a4 * (b3 - b1);
    F = (a3 + a4) * b1;
    G = (a1 + a2) * b4;
    H = (a3 - a1) * (b1  + b2);
    I = (a2 - a4) * (b3 + b4);
    J = (a1 + a4) * (b1 + b4);

    C1 = E + I + J - G;
    C2 = D + G;
    C3 = E + F;
    C4 = D + H + J - F;

    c[row_start][col_start] = C1;
    c[row_start][col_end-1] = C2;
    c[row_end-1][col_start] = C3;
    c[row_end-1][col_end-1] = C4;
}


int main(){

    int a[MAX][MAX],b[MAX][MAX], c[MAX][MAX] = {0};
    int n;

    cout << "Enter n in NxN : ";
    cin >> n;

    if(n%2 != 0){
        cout << "Only valid with N equal to power of 2";
        return 0;
    }

    cout << "Enter matrix a : ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    cout << "Enter matrix b : ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> b[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            if(i % 2 != 0 || j % 2 != 0){
                continue;
            }
            else{
                multiply(a,b,c,i,i+2,j,j+2);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}
