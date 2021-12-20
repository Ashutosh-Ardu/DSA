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
      // kruskal(g,n);
      break;
    case 3:
      // dijkstra(g,n);
      break;
  }
}