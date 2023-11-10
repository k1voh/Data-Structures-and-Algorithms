#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int count = 0;
int vertArr[20][20];
int mat[20][20];

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
   //vertArr[v][u] = 1;
}
void trans(int vert)
{

    for(int i=1;i<=vert;i++)
    {

        for(int j=1;j<=vert;j++)
        {
            mat[j][i]=vertArr[i][j];
        }
    }
}
void displayMatrixtrans(int v) {
    cout<<"transpose is"<<endl;
   int i, j;
   for(i = 1; i <= v; i++) {
      for(j = 1; j <= v; j++) {
         cout <<  mat[i][j] << " ";
      }
      cout << endl;
   }
}
void bfs(int source,int n){
        bool visited[n+1]={false};
        int mother=0;
        queue <int> s;
        s.push(source);
        visited[source]=true;
        while(!s.empty()){
            int c=s.front();
            s.pop();
            for(int i=1;i<n+1;i++){
                if(vertArr[c][i]==1 && !visited[i]){
                    visited[i]=true;
                    s.push(i);

                }
            }
            //cout<<c<<" ";
            mother++;
            if(mother==n){
            cout<<source<<"is mother vertex"<<endl;
            }
        }
    }
void dfs(int source,int n){
    bool visited[n+1]={false};
    int mother=0;
        stack <int> s;
        s.push(source);
        visited[source]=true;
        while(!s.empty()){
            int c=s.top();
            s.pop();
            for(int i=1;i<n+1;i++){
                if(vertArr[c][i]==1 && !visited[i]){
                    visited[i]=true;
                    s.push(i);

                }
            }
            cout<<c<<" ";

        }




}




int main() {
    cout<<"enter no of vertices"<<endl;
    int v;
    cin>>v;
    int k=1;
    int i,j;
    while(k<=v)
    {
        int cnt=1;
        int e;
        cout<<"no of edges of vertice "<< k<<endl;
        cin>>e;
        while(cnt<=e)
        {
            cout<<"i , j of matrix"<<endl;
            cin>>i;
            cin>>j;
        add_edge(i,j);
        cnt++;
        }
        k++;
    }
   displayMatrix(v);
   //trans(v);
   //displayMatrixtrans(v);
   /*cout<<"BFS"<<endl;

   bfs(1,v);*//*
   cout<<endl<<"BFS"<<endl;

   bfs(1,v);

   cout <<endl << "The Step count is : "<< count<<endl;*/

    
    for(int i=1;i<=v;i++){
    bfs(i,v);
    cout<<endl;
    }



}
