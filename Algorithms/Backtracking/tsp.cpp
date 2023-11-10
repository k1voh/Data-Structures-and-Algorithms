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

        //Variables for TSP
        int cc = 0, bestc = 0, bestx[MAX], bestv[MAX] = {0};
        int x[MAX] = {0};

        void addEdge(int u, int v, int cost){
            graphMat[u][v] = cost;
            graphMat[v][u] = cost;
        }

        void swap(int a, int b){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }

        int TSP(){
            for(int i = 1; i <= n; i++){
                x[i] = i;
            }
            tsp(2);
            for(int i = 1; i <= n; i++ ){
                cout << bestx[i] << " ";
            }
            cout <<endl;
            return bestc;
        }

        void tsp(int i){
            if(i == n){
                if(graphMat[x[n-1]][x[n]] != NoEdge && graphMat[x[n]][1] != NoEdge && (cc + graphMat[x[n-1]][x[n]] + graphMat[x[n]][1] < bestc  || bestc == NoEdge)){
                    for(int j = 1; j <= n; j++){
                        bestx[j] = x[j];
                        bestc = cc + graphMat[x[n-1]][x[n]] + graphMat[x[n]][1];
                    }
                }
            }
            else{
                for(int j = 1; j <= n; j++){
                    if(graphMat[x[i-1]][x[j]] != NoEdge && (cc + graphMat[x[i-1]][x[j]] < bestc || bestc == NoEdge)){
                        swap(x[i],x[j]);
                        cc += graphMat[x[i-1]][x[i]];
                        tsp(i+1);
                        cc -= graphMat[x[i-1]][x[i]];
                        swap(x[i],x[j]);
                    }
                }
            }
        }

};

int main(){

    //graph variables
    int n;
    int e;
    //graph
    int k,h,cost;
    graph g;

    cout << "Enter number of vertices"<<endl;
    cin >> n;

    g.n = n; //global vertices = vertices

    cout << "Enter number of edges"<<endl;
    cin >> e;


    for(int i = 0; i < e; i++){
        cout << "Enter edge i <->  j in format i j cost: ";
        cin >> k;
        cin >> h;
        cin >> cost;
        g.addEdge(k,h,cost);
    }

    cout << g.TSP();

    return 0;
}