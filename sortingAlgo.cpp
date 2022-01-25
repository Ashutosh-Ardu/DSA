#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

// printing the array
void print(int *ar,int n){
  cout<<"Array: ";
  for(int i=0;i<n;++i)
    cout<<ar[i]<<" ";
  cout<<endl;
}

// for swapping elements while sorting
void swap(int &a,int &b){
  int t=a;
  a=b;
  b=t;
}

// driver for bubble sort (ascending order)
void bubbleSort(int *ar,int n){
  int flag;//for increasing the codes efficiency
  for(int i=0;i<n-1;++i){
    flag=0;
    for(int j=0;j<n;++j){
      if(ar[j]>ar[j+1]){
        flag=1;
        swap(ar[j],ar[j+1]);
      }
    }
    // break the loop if no values are swapped
    if(!flag) break;
  }
}

// driver for selection sort (ascending order)
void selectionSort(int *ar,int n){
  int min;
  for(int i=0;i<n-1;++i){
    min=i;
    for(int j=i+1;j<n;++j){
      if(ar[j]<ar[min]) min=j;
    }
    swap(ar[i],ar[min]);
  }
}

// driver for insertion sort (ascending order)
void insertionSort(int *ar,int n){
  int j,k;
  for(int i=1;i<n;++i){
    k=ar[i];//key value for comparision
    j=i-1;
    while(j>=0 && ar[j]>k){
      swap(ar[j],ar[j+1]);
      j--;
    }ar[j+1]=k;//as after swapping j+1 slot is emptied
  }
}

// merge the partitioned array in a sorted manner (ascending order)
void merge(int *ar,int l,int r,int mid){
  int i=l,j=mid+1,k=l;
  int *b=new int[30];
  while(i<=mid && j<=r){
    if(ar[i]<ar[j])
      b[k++]=ar[i++];
    else
      b[k++]=ar[j++];
  }
  // filling the rest of the elements
  // once  one of the either two of the set is
  // extinguished first
  if(i>mid){
    while(j<=r){
      b[k++]=ar[j++];
    }
  }
  else{
    while(i<=mid){
        b[k++]=ar[i++];
    }
  }

  // reassigning the changes back to the original array
  for(k=l;k<=r;++k)
    ar[k]=b[k];
  delete b;
}

// mergeSort driver code
void mergeSort(int *ar,int l,int r){
  if(l<r){
    int mid=(l+r)/2;
    // first partition
    mergeSort(ar,l,mid);
    // second partition
    mergeSort(ar,mid+1,r);
    // merging both the partitions 
    // in a sorted way 
    merge(ar,l,r,mid);
  }
}

// choosing first element of the array as the pivot
int partitionFirst(int *ar,int l,int r){
  int i=l,j=r,p=ar[l];
  while(i<=j){
    // search for the ri8 place to insert the partition 
    while(i<=r && ar[i]<=p) i++;
    while(j>=l && ar[j]>p) j--;
    if(i<j)
      swap(ar[i],ar[j]);
  }swap(ar[l],ar[j]);//placing the element
  // around which partition was made, in its ri8 place
  return j;
}

// driver code for quicksort (first element as pivot)
// (ascending order)
void quickSortFirst(int *ar,int l,int r){
  if(l<r){
    int p=partitionFirst(ar,l,r);
    quickSortFirst(ar,l,p-1);
    quickSortFirst(ar,p+1,r);
  }
}

// choosing the last element of the array as pivot
// (ascending order)
int partitionLast(int *ar,int l,int r){
  int p=ar[r],i=l,j=r;
  while(i<j){
    // finding the right place to insert the pivot element
    // and at the same time sorting the array around it
    while(i<=r && ar[i]<p) i++;
    while(j>=l && ar[j]>=p) j--;
    if(i<j)
      swap(ar[i],ar[j]);
  }swap(ar[r],ar[i]);
  return i;
}

// driver code for quicksort (last element as pivot)
// (ascending order)
void quickSortLast(int *ar,int l,int r){
  if(l<r){
    // finding the index for partition
    int p=partitionLast(ar,l,r);
    // first partition
    quickSortLast(ar,l,p-1);
    // second partition
    quickSortLast(ar,p+1,r);
  }
}

// choosing the middle element of the array as pivot
// (ascending order)
int partitionMid(int *ar,int l,int r){
  int mid=(l+r)/2;;
  int p=ar[mid],i=l,j=r;
  while(i<=j){
    if(ar[i]<p) i++;
    else if(ar[j]>p) j--;
    else{
      swap(ar[i],ar[j]);
      i++;j--;
    }
  }return i;
}

// driver code for quicksort (middle element as pivot)
// (ascending order)
// most effective form of quicksort
void quickSortMid(int *ar,int l,int r){
  int p=partitionMid(ar,l,r);
  if(l<p-1)
    quickSortMid(ar,l,p-1);
  if(p<r)
    quickSortMid(ar,p,r);
}

// heap sort
// time complexity  O(n log n)
void heapifyTopBottom(int *ar,int index,int n){
  int left = index * 2 + 1; // left child
  int right = index * 2 + 2;// right child
  int max = index;

  if(left < n && ar[left] > ar[max])
    max = left;
  if(right < n && ar[right] > ar[max])
    max = right;
  
  if(max != index){
    swap(ar[max],ar[index]);
    heapifyTopBottom(ar,max,n);
  }
} 

// ascending order sorting
void heapSort(int *ar,int n){
  // first convert the array into a max heap tree
  for(int i= (n/2) - 1 ; i >= 0 ; --i)// this loop only touches the parents
    heapifyTopBottom(ar,i,n);//and not the leaf nodes which are not parents
  
  // now,switch the elements in the last and topmost location
  // decrease the size of the heap by 1
  // continue this cycle for every loop from range n-1 --> 1 (inclusive)
  for(int i=n-1 ; i>0 ;--i){
    swap(ar[0],ar[i]);//swapping the last most and top most
    heapifyTopBottom(ar,0,i);
  }
}

int main(){
  int n;
  cout<<"Total Values: ";
  cin>>n;
  // setting a seed value for creating random values
  // in this case we are passing the current time
  // as our seed
  srand(time(0));
  int *ar=new int[n];
  for(int i=0;i<n;++i) ar[i]=rand()%1000;
  //limiting the values till 1000
  print(ar,n);
  // bubbleSort(ar,n);
  // insertionSort(ar,n);
  // selectionSort(ar,n);
  // mergeSort(ar,0,n-1);
  // quickSortFirst(ar,0,n-1);
  // quickSortLast(ar,0,n-1);
  // quickSortMid(ar,0,n-1);
  heapSort(ar,n);
  print(ar,n);
}