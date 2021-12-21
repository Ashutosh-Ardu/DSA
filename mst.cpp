#include "iostream"
#include "stdlib.h"
using namespace std;
#define inf 10e7 // for comparing
// Minimum Spanning Tree and Shortest Path in a graph

// finding a edge travel to a minimum distance
// vertex for the current position 
int minCostPrisms(int *visited,int *cost,int n){
  // min is used for comparision
  // minVertex stores the actual vertex index
  int min=inf,minVertex;
  for(int i=0;i<n;++i){
    if(cost[i]<min && !visited[i])
      min=cost[i],minVertex=i;
  }
  return minVertex;
}


void printPrims(int **g,int *parent,int n){
  int total=0;
  // starting 'i' from 1 as parent[0]=-1
  cout<<"Minimum Spanning Tree:\n";
  for(int i=1;i<n;++i){
    if(parent[i]<i)
      cout<<parent[i]<<"-->"<<i<<" = "<<g[parent[i]][i]<<endl;
    else
      cout<<i<<"-->"<<parent[i]<<" = "<<g[parent[i]][i]<<endl;
    total+=g[parent[i]][i];
  }
  cout<<"Total Cost : "<<total<<endl;
} 

// prims driver
void prims(int **g,int n){

  int *parent=new int[n];
  int *cost=new int[n];
  int *visited=new int[n];

  // initally all vertices are unvisited
  // & have infinite cost
  for(int i=0;i<n;++i)
    visited[i]=0,cost[i]=inf;
  
  // choosing the starting vertex
  // in this case 0th vertex
  cost[0]=0,parent[0]=-1;

  // finding the next appropriate vertex
  for(int c=0;c<n-1;++c){
    int i=minCostPrisms(visited,cost,n);
    visited[i]=1;

    // accessing the vertices connected to it
    // updating the cost table 
    for(int j=0;j<n;++j){
      if(g[i][j] && !visited[j] && g[i][j]<cost[j])
        cost[j]=g[i][j],parent[j]=i;
    }
  }

  printPrims(g,parent,n); 
}

// now for kruskal's algo we need to convert
// the graph into edges cause in we work with 
// edges rather than vertices

// Hence a struct storing the edge and a list full of it

struct edge{
  int src,dest,cost;
};

struct edgeList{
  //keeping max 30 for now
  edge data[30];
  int n;
};

void printKruskal(edgeList *ar){
  int total=0;
  cout<<"Minimum Spanning Tree:\n";
  for(int i=0;i<ar->n;++i){
    cout<<ar->data[i].src<<"-->"<<ar->data[i].dest<<" = "<<ar->data[i].cost<<endl;
    total+=ar->data[i].cost;
  }
  cout<<"Total Cost : "<<total<<endl;
}

void swap(edge &a,edge &b){
  int t=a.src;a.src=b.src;b.src=t;
  t=a.dest;a.dest=b.dest;b.dest=t;
  t=a.cost;a.cost=b.cost;b.cost=t;
}

// for sorting the edgeList in ascending order
// as required in kruskal's algo
void sort(edgeList *ar){
  int min;
  for(int i=0;i<ar->n-1;++i){
    min=i;
    for(int j=i+1;j<ar->n;++j){
      if(ar->data[j].cost<ar->data[min].cost)
        min=j;
    }
    swap(ar->data[i],ar->data[min]);
  }
}

// finding the current parent of the given vertex
int findParent(int *parent,int i){
  if(parent[i]==i)
    return i;
  else
    return findParent(parent,parent[i]);
}

// kruskal's driver
void kruskal(int **g,int n){
  // converting the adjacency matrix into a
  // "edgeList"
  edgeList *stack=new edgeList;
  stack->n=0;
  // moving i from 1->n and j from 0->i
  // for e.g. n=5
  // *****
  // *****
  // *****
  // *****
  // *****
  // but g[i][j]=g[j][i]
  // to reduce redundancy
  // 
  // *
  // **
  // ***
  // ****
  // this covers all the necessary edges
  for(int i=1;i<n;++i){
    for(int j=0;j<i;++j){
      if(g[i][j]){
        stack->data[stack->n].src=j;
        stack->data[stack->n].dest=i;
        stack->data[stack->n].cost=g[i][j];
        stack->n+=1;
      }
    }
  }
  // for testing purposes
  // printKruskal(stack);
  sort(stack);
  // printKruskal(stack);

  // storing the final edgelist sequence
  // which will make up the MST
  edgeList *final=new edgeList[n-1];
  final->n=0;
  int *parent=new int[n];
  for(int i=0;i<n;++i)
    parent[i]=i;//initializing for further operations

  int c=0;//counter
  while(final->n<n-1){
    edge cur=stack->data[c++];
    // checking whether choosing this particular edge
    // leads to a loop or not
    int sparent=findParent(parent,cur.src);
    int dparent=findParent(parent,cur.dest);

    // if it doesn't
    if(sparent!=dparent){
      final->data[final->n]=cur;
      parent[dparent]=sparent;
      final->n+=1;
    }
  }

  printKruskal(final);
}


// finding the next minimum distance vertex to move to
// from the current location
// as dijkstra is always from source -> destination 
int minCostDijkstra(int *visited,int *cost,int n){
  int min=inf,minVertex;
  for(int i=0;i<n;++i){
    if(cost[i]<min && !visited[i])
      min=cost[i],minVertex=i;
  }
  return minVertex;
}

void printDijkstra(int *cost,int n){
  // assuming the first vertex in the stack 
  // to be our source
  cout<<"Shortest Distance Map :\n";
  int src=0;
  for(int i=0;i<n;++i)
    cout<<src<<"-->"<<i<<" = "<<cost[i]<<endl;
}

// dijkstra's driver
void dijkstra(int **g,int n){
  // initializing necessary arrays
  int *visited=new int[n];
  int *parent=new int[n];
  int *cost=new int[n];

  // setting up the array for further updations
  // as initially all the vertices are unvisited 
  // and have infinite distance
  for(int i=0;i<n;++i)
    cost[i]=inf,visited[i]=0;

  // choosing first vertex in the stack as our origin
  // can be user input if needed
  cost[0]=0,parent[0]=-1;

  // first we choose the  suitable vertex 
  // from the current cost table
  for(int c=0;c<n;++c){
    int i=minCostDijkstra(visited,cost,n);
    // mark it visited as we are on it at the moment
    visited[i]=1;

    // now traversing through all the connections 
    // that particular vertex has and choosing the minimum
    // among them
    for(int j=0;j<n;++j){
      // conditions for the point to be chosen
      // i]should not be visited initially
      // ii]there should be link between the parent vertex and the chosen vertex
      // iii]the parent vertex should be reachable meaning the
      // minCost function should return something other than inf
      // iv]the cost of reaching that vertex through the parent vertex
      // should be less than the current cost of reaching the chosen vertex 
      if(g[i][j] && cost[i]!=inf && !visited[j] && cost[i]+g[i][j]<cost[j])
        cost[j]=cost[i]+g[i][j],parent[j]=i;
    }
  }
  printDijkstra(cost,n);
}

int main(){
  int n,ch;
  cout<<"Total Vertices: ";
  cin>>n;
  // filling it with array of pointers
  int **g=new int*[n];
  
  cout<<"Adjacency Matrix:\n";
  for(int i=0;i<n;++i){
    // filling it with actual integer data
    // in memory
    g[i]=new int[n];
    for(int j=0;j<n;++j)
      cin>>g[i][j];
  }

  cout<<"1]Prims 2]Kruskal 3]Dijkstra\n";
  cin>>ch;

  switch(ch){
    case 1:
      prims(g,n);
      break;
    case 2:
      kruskal(g,n);
      break;
    case 3:
      dijkstra(g,n);
      break;
  }
}