#include "iostream"
using namespace std;

// flag values for traversing through the stack
// for bfs where childrens of the root node are appended
// for scanning levelwise
int counter=0,cur=-1;

void bfs(int **g,int v,int n,int *visited,int *stack){
  // scanning the edges attached to "v"
  for(int i=1;i<=n;++i){
    if(g[v][i] && !visited[i]){
      cout<<i<<" ";
      stack[++cur]=i;//appending it into the stack
      visited[i]=1;
    }
  }
  // scanning through the childrens
  if(++counter<=cur)
    bfs(g,stack[counter],n,visited,stack);
}

void dfs(int **g,int v,int n,int *visited){
  // marking it visited before traversing for
  // minimum edges option cause there is  
  // backtracking in dfs so the revisit
  // shouldn't be counter
  visited[v]=1;
  // looking for more unvisited nodes
  for(int i=1;i<=n;++i){
    if(g[v][i] && !visited[i]){
      cout<<i<<" ";
      dfs(g,i,n,visited);
    }
  }
}

int main(){
  int n,v,ch;
  cout<<"Total Vertices : ";
  cin>>n;
  // stack of pointers
  // holding stack of integer values
  // which creates a dynamic 2D array
  int **g=new int*[n];
  int *visited=new int[n];
  int *stack=new int[n*n];//bfs also has some revisits

  cout<<"Adjacency Matrix:\n";
  for(int i=1;i<=n;++i){
    g[i]=new int[n];//filling integer values into the 
    // pointer stack
    visited[i]=0;//initially all vertices are unvisited
    for(int j=1;j<=n;++j)
      cin>>g[i][j];
  }

  cout<<"Starting Vertex: ";
  cin>>v;

  cout<<"1]BFS 2]DFS\n";
  cin>>ch;

  switch(ch){
    case 1:
      cout<<"BFS : "<<v<<" ";
      visited[v]=1;
      stack[++cur]=v;
      bfs(g,v,n,visited,stack);
      cout<<endl;
      break;
    case 2:
      cout<<"DFS : "<<v<<" ";
      dfs(g,v,n,visited);
      cout<<endl;
      break;
  }
}