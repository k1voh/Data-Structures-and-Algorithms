// TOPOLOGICAL SORTING

#include<iostream>
#include<stack>
using namespace std;

// GREEDY CRITERION : from the remaining vertices select vertex w such that it has no incoming edge <v,w> with a property that v is not already added in the sequence


int vertArr[100][100];
int vis[100] = {0};

void displayMatrix(int v) {
   int i, j;
   for(i = 1; i <= v; i++) {
      for(j = 1; j <=v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
   cout<<endl;
}

void add_edge(int u, int v) {
   vertArr[u][v] = 1;
}

int begin(int a[][100], int w, int n){
    for(int i = 1; i <= n; i++){
        if(a[w][i] == 1){
            return i;
        }
    }
    return 0;
}

int nextVertex(int a[][100], int w, int u, int n){
    for(int i = u+1; i <= n; i++){
        if(a[w][i] == i){
            return i;
        }
    }
    return 0;
}


bool topologicalSort(int n){

    int indeg[n+1], i, j;
    //initialise indegree of every vertice to 0
    for(i = 1; i <= n; i++){
        indeg[i] = 0;
    }

    //find indegree of every vertex and store it in the array
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            indeg[i] += vertArr[j][i];
        }
    }

    cout << "\nThe topological order is:";
    int count = 0;
    int flag[10] = {0};
    int k;
    stack <int> s;
    
    i = 1;
    while(!s.empty()){
        int w;
        w = s.top();
        s.pop();
        vis[i++] = w;
        int u = begin(vertArr,w,n);
        while(u){
            indeg[u]--;
            if(!indeg[u]) s.push(u);
            u = nextVertex(vertArr,w,u,n);
        }
    }

    return (j-1 == n);
}


int main() {
    //graph variables
    int n;
    int e;
    //graph
    int k,h;
    //graph g;

    cout << "Enter number of vertices"<<endl;
    cin >> n;

    //g.n = n; //global vertices = vertices

    cout << "Enter number of edges"<<endl;
    cin >> e;


    for(int i = 0; i < e; i++){
        cout << "Enter edge i ->  j in format i j: ";
        cin >> k;
        cin >> h;
        add_edge(k,h);
    }
   displayMatrix(n);

   cout << topologicalSort(n);
}
