#include<iostream>
#define MAX 100
using namespace std;

class graph{
    
public:    
    int graphMat[MAX][MAX] = {0};
    int n; //number of vertices

    void addEdge(int u, int n, int cost){
        graphMat[u][n] = cost;
        graphMat[n][u] = cost;
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

    int mindist(int dist[], bool sp[]){
        int min = INT_MAX, min_index;
        for (int v = 1; v <= n; v++)
            if (sp[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }

    void print(int dist[]){
        cout<<"Vertex \t Distance from Source\n";
        for (int i = 1; i <= n; i++)
            cout<< i<< "\t\t"<<dist[i]<<"\n";
    }

    void dijkstra(int src)
    {
        int dist[n];
        bool sp[n];
        for (int i = 1; i <= n; i++)
            dist[i] = INT_MAX, sp[i] = false;
        dist[src] = 0;
        for (int count = 1; count <= n - 1; count++)
        {
            int u = mindist(dist, sp);
            sp[u] = true;
            for (int v = 1; v <= n; v++)
                if (!sp[v] && graphMat[u][v] && dist[u] != INT_MAX&& dist[u] + graphMat[u][v] < dist[v])
                    dist[v] = dist[u] + graphMat[u][v];
        }
        print(dist);
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

    int src;
    cout << "Enter source for dijkstra : ";
    cin >> src;
    g.dijkstra(src);

    return 0;
}