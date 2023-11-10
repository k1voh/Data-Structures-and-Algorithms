#include<iostream>
#define MAX 100
using namespace std;

class graph{
    
public:    
    int graphMat[MAX][MAX] = {0};
    int n; //number of vertices

    void addEdge(int u, int v, int cost){
        graphMat[u][v] = cost;
        graphMat[v][u] = cost;
    }

    void showGraph(){
        //n = number of vertices
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << graphMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    int minKey(int key[], bool mstSet[]){
        int min = INT_MAX, min_index;
        for (int v = 1; v <= n; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    void printMST(int parent[]){
        cout<<"Edge \tWeight\n";
        for (int i = 1; i < n; i++)
            cout<<parent[i]<<" - "<<i<<" \t"<<graphMat[i][parent[i]]<<" \n";
    }

    void primMST(){
        int parent[n];
        int key[n];
        bool mstSet[n];
        for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < n - 1; count++)
        {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 1; v <= n; v++)
            if (graphMat[u][v] && mstSet[v] == false && graphMat[u][v] < key[v])
            parent[v] = u, key[v] = graphMat[u][v];
        }
        printMST(parent);
    }
};

int main(){

    //graph variables
    int n;
    int e;
    //graph
    int k,h;
    graph g;

    cout << "Enter number of vertices"<<endl;
    cin >> n;

    g.n = n; //global vertices = vertices

    cout << "Enter number of edges"<<endl;
    cin >> e;
    int cost;

    for(int i = 0; i < e; i++){
        cout << "Enter edge i ->  j in format i j cost: ";
        cin >> k;
        cin >> h;
        cin >> cost;
        g.addEdge(k,h, cost);
    }

    g.primMST();

    return 0;
}