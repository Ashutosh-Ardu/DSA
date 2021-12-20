#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

// Linear Search
void linear(int ar[],int n,int item){
  for(int i=0;i<n;++i){
    if(ar[i]==item){
      cout<<"Found "<<item<<" at index "<<i<<endl;
      return;
    }
  }
  cout<<"Not Found\n";
}

// Binary Search (The array passed has to be sorted)
// Assuming the array is in ascending order
void binary(int ar[],int n,int item){
  int start=0,end=n-1;
  int mid;
  while(start<=end){
    mid=(start+end)/2;
    if(ar[mid]==item){
      cout<<"Found "<<item<<" at index "<<mid<<endl;
      return;
    }
    else{
      if(item<ar[mid])
        end=mid-1;
      else
        start=mid+1;
    }
  }
  cout<<"Not Found\n";  
}
// For swapping during sorting
void swap(int &a,int &b){
  int t=a;
  a=b;b=t;
}
// Using bubble sort for sorting
void sort(int ar[],int n){
  bool flag;//increase bubble sort's efficiency
  for(int i=0;i<n-1;++i){
    flag=false;
    for(int j=0;j<n-i-1;++j){
      if(ar[j]>ar[j+1]){//ascending order
        swap(ar[j],ar[j+1]);
        flag=true;
      }
    }
    if(flag==false) return;
    //already sorted no further iterations needed
  }
}

//for printing the current state of the array 
void print(int ar[],int n){
  cout<<"Array: ";
  for(int i=0;i<n;++i)
    cout<<ar[i]<<" ";
  cout<<endl;
}

int main(){
  // Setting the seed for the rand function
  // passing current time as seed
  srand(time(0));
  int n,item,ch;
  cout<<"Total Elements: ";
  cin>>n;
  int ar[n];
  for(int i=0;i<n;++i)
    ar[i]=rand()%1000;
  /* rand gives int values but we want it to be within
    0-1000*/
  sort(ar,n);
  // For printing the current array
  print(ar,n);  
  cout<<"Search Value: ";
  cin>>item;
  cout<<"1-Linear Search 2-Binary Search\n";
  cin>>ch;
  switch(ch){
    case 1:
      linear(ar,n,item);
      break;
    case 2:
      binary(ar,n,item);
      break;
    default:
      cout<<"Wrong Options\n";
  }
}