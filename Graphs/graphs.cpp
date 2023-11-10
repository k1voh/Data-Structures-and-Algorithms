#include<iostream>
#include<stack>
#include<queue>
#define MAX 100
using namespace std;

class graph{
    
public:    
    int graphMat[MAX][MAX] = {0};
    int n; //number of vertices

    void addEdge(int u, int v){
        graphMat[u][v] = 1;
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

    void dfs(int source){
        bool vis[n+1] = {false};
        vis[source] = true;
        stack <int> s;
        s.push(source);
        while(!s.empty()){
            int c = s.top();
            s.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    s.push(i);
                }
            }
            cout << c <<" ";
        }
        cout <<endl;
    }

    void bfs(int source){
        bool vis[n+1] = {false};
        vis[source] = true;
        queue <int> s;
        s.push(source);
        while(!s.empty()){
            int c = s.front();
            s.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    s.push(i);
                }
            }
            cout << c <<" ";
        }
        cout << endl;
    }

    void cycleCheck(int source){
        bool vis[n+1] = {false};
        vis[source] = true;
        stack <int> s;
        s.push(source);
        int FLAG = 1; //flag check for cycle
        while(!s.empty()){
            int c = s.top();
            s.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    s.push(i);
                }
                else if(graphMat[c][i] == 1 && vis[i] == true){
                    FLAG = 0; //works only for directed graph
                }
            }
        }

        if(FLAG == 0){
            cout << "there is a cycle" <<endl;
        }
        else{
            cout << "there is no cycle" <<endl;
        }
    }

    bool motherCheckAlgo(int source){
        //do bfs
        int mother = 0; //count for number of nodes vertex is connected to
        bool vis[n+1] = {false};
        vis[source] = true;
        stack <int> s;
        s.push(source);
        while(!s.empty()){
            int c = s.top();
            mother++;
            s.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    s.push(i);
                }
            }
        }
        return (mother == n);
    }

    void motherCheck(){
        for (int i = 1; i <= n; i++){
            if(motherCheckAlgo(i)) cout << i << " is the Mother Vertex"<<endl;
        }
    }

    bool checkConnected(int source){
        bool vis[n+1] = {false};
        queue <int> q;
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }

        for(int i = 1 ; i <= n;i++){
            if(vis[i] == false){
                return false;
            }
        }
        return true;
    }
    void bfsHelp(int source , bool vis[]){
        //bool vis[n+1] = {false};
        stack <int> s;
        s.push(source);
        vis[source] = true;
        while(!s.empty()){
            int c = s.top();
            s.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    s.push(i);
                }
            }
        }
    }
    int checkComponents(){
        bool vis[n+1] = {false};
        int label = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] == false){
                label++;
                bfsHelp(i,vis);
            }
        }
        return label;
    }

    void greaterThan3(int source){
        bool vis[n+1] = {false};
        vis[source] = true;
        queue <int> s;
        s.push(source);
        int lvl = 0;
        while(!s.empty()){
            int c = s.front();
            s.pop();
            for(int i = 1; i <= n; i++){
                if(graphMat[c][i] == 1 && vis[i] == false){
                    vis[i] = true;
                    s.push(i);
                }
            }
            if(lvl >= 3){
                cout << c <<" ";
            }
            lvl++;
        }
        cout << endl;        
    }

    bool findPath(int source, int dest, int length, int path[], bool vis[]){
        //int i;
        path[length] = source;
        if(source == dest) {
            /*for(i = 0; i < length; i++){
                cout << path[i] <<"->";
            }
            cout << path[i];
            cout << endl;*/
            return true;
        }
        for(int i = 1; i <= n; i++){
            if(graphMat[source][i] == 1 && vis[i] == false){
                length++;
                vis[i] = true;
                findPath(i,dest,length,path,vis);
            }
        }
        return false;
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

    bool vis[n+1] = {false};
    int path[MAX];

    g.showGraph();
    g.dfs(1);
    g.bfs(1);
    g.cycleCheck(1);
    g.motherCheck();
    cout << g.checkComponents()<< " are the number of Components" <<endl;
    if(g.checkComponents() > 1){
        cout << "Graph is Disconnected"<<endl;
    }
    else{
        cout << "Graph is Connected"<<endl;
    }
    g.greaterThan3(1);
    g.findPath(1,6,0,path,vis);
}