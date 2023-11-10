#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int selectminvertex2(int val[], bool vis[], int v){
    int mini = INT_MAX;
    int vertex;
    for(int i=1;i<=v;i++){
        if(vis[i] == false && val[i] <= mini){
            mini = val[i];
            vertex = i;
        }
    }
    return vertex;
}

void print(int dist[], int n){
    cout<<"Vertex \t Distance from Source\n";
    for (int i = 1; i <= n; i++)
        cout<< i<< "\t\t"<<dist[i]<<"\n";
}

void findMST2(int a[100][100], int v){
    //int parent[v];
    int value[v];
    bool vis[v];
    for(int i=1;i<=v;i++){
        value[i] = INT_MAX;
        vis[i] = false;
    }
    //parent[0] = -1;
    int src;
    cout << "Enter source : ";
    cin >> src;
    value[src] = 0;

    for(int i=1;i<=v-1;i++){
        int u = selectminvertex2(value, vis, v);
        vis[u] = true;

        for(int j=1;j<=v;j++){
            if(a[u][j] !=0 && vis[j] == false && value[u] != INT_MAX && (value[u] + a[u][j] < value[j])){
                value[j] = value[u] + a[u][j];
                //parent[j] = u;
            }
        }
    }

    print(value,v);
}


int main(){
    int a[100][100];
    int v, e, s, d, w;
    cout<<"Enter v: ";
    cin>>v;
    cout<<"Enter e: ";
    cin>>e;

    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            a[i][j] = 0;
        }
    }

    cout<<"Enter edges with weight : "<<endl;
    for(int i=1;i<=e;i++){
        cin>>s>>d>>w;
        a[s][d] = w;
        a[d][s] = w;
    }

    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<a[i][j]<<"    ";
        }
        cout<<endl;
    }

    findMST2(a,v);
    return 0;
}

