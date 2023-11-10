//Write a program to find the shortest path between every pair of vertices in a given graph using dynamic programming technique.

#include<iostream>
#define MAX 100
#define INF INT_MAX
using namespace std;

class graph{

public:
    int graphMat[MAX][MAX] = {0};
    int n; //number of vertices

    void addEdge(int u, int v, int cost){
        graphMat[u][v] = cost;
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

    void allPairs(int key[][MAX]){

        int c[MAX][MAX];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                c[i][j] = graphMat[i][j];
                key[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(c[i][j] == 0){
                    c[i][j] = INF;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            c[i][i] = 0;
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    int t1 = c[i][k];
                    int t2 = c[k][j];
                    int t3 = c[i][j];

                    if(t1 != INF && t2 != INF && (t3 == INF || t1 + t2 < t3)){
                        c[i][j] = t1+t2;
                        key[i][j] = k;
                    }
                }
            }
        }
        
        cout << "The key graph is : "<<endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << key[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main(){

    //graph variables
    int n;
    int e;
    //graph
    int k,h,c;
    graph g;

    cout << "Enter number of vertices"<<endl;
    cin >> n;

    g.n = n; //global vertices = vertices

    cout << "Enter number of edges"<<endl;
    cin >> e;


    for(int i = 0; i < e; i++){
        cout << "Enter edge i ->  j in format i j cost: ";
        cin >> k;
        cin >> h;
        cin >> c;
        g.addEdge(k,h,c);
    }

    int key[MAX][MAX] = {0};

    g.allPairs(key);

}
