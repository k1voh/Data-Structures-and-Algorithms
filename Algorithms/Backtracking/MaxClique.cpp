#include<iostream>
#define MAX 100
#define NoEdge 0
#define INF INT_MAX
using namespace std;

class graph{

    public:
        //Graph Variables
        int graphMat[MAX][MAX] = {0};
        int n;

        //Variables for Max Clique
        int cn = 0, bestn = 0, bestx[MAX], bestv[MAX] = {0};
        int x[MAX] = {0};

        void addEdge(int u, int v){
            graphMat[u][v] = 1;
            graphMat[v][u] = 1;
        }

        void maxClique(int i){
            if(i > n){
                for(int j = 1; j <= n; j++){
                    bestx[j] = x[j];
                }
                bestn = cn;
                return;
            }

            int ok = 1;
            for(int j = 1; j < i; j++){
                if(x[j] && graphMat[i][j]==NoEdge){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                x[i] = 1;
                cn++;
                maxClique(i+1);
                x[i] = 0;
                cn--;
            }
            if(cn + n - i > bestn){
                x[i] = 0;
                maxClique(i+1);
            }
        }

        int MaxClique(){
            maxClique(1);
            for(int j = 1; j <= n ; j++){
                cout << bestx[j] << " ";
            }
            cout <<endl;
            return bestn;
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


    for(int i = 0; i < e; i++){
        cout << "Enter edge i ->  j in format i j: ";
        cin >> k;
        cin >> h;
        g.addEdge(k,h);
    }

    cout << g.MaxClique();

    return 0;
}