#include "iostream"
using namespace std;

// Same as min heap just the less than in min heap is swithed to greater than in max heap

struct heap{
	int *ar;
	int capacity,cur;
};

heap* heapInit(){
	heap *ptr = new heap;
	ptr->cur = 0;
	ptr->capacity = 50;
	ptr->ar = new int[50];
	return ptr;
}

void swap(int &a,int &b){
	int t=a;a=b;b=t;
}

void heapifyBT(heap *root,int index){
	int parent = (index - 1) / 2;
	if(root->ar[parent] <  root->ar[index]){
		swap(root->ar[parent],root->ar[index]);
		heapifyBT(root,parent);
	}
}

void heapifyTB(heap *root,int parent){
	int left = parent * 2 + 1;
	int right = parent * 2 + 2;
	int max = parent;

	if(left >= root->cur || left < 0)
		left = -1;

	if(right >= root->cur || right < 0)
		right = -1;
	
	if(left != -1 && root->ar[left] > root->ar[parent])// point of difference from min heap
		max = left;

	if(right != -1 && root->ar[right] > root->ar[max])// point of difference from min heap
		max = right;

	if(max != parent){
		swap(root->ar[parent],root->ar[max]);
		heapifyTB(root,max);
	}
}

void insert(heap *root,int key){
	if(root->cur < root->capacity){// point of difference from min heap
		root->ar[root->cur] = key;
		heapifyBT(root,root->cur);
		root->cur += 1;
	}
}

void show(heap *root){
	for(int i=0;i<root->cur;++i)
		cout<<root->ar[i]<<" ";
	cout<<"\n";
}

void popMax(heap *root){
	if(root->cur){
		root->ar[0] = root->ar[root->cur - 1];
		root->cur -= 1;
		heapifyTB(root,0);
	}
	else
		cout<<"heap is empty\n";
}

int main(){
	int n,key;
	cout<<"total elements: ";
	cin>>n;

	heap *root = heapInit();
	for(int i=0;i<n;++i){
		cin>>key;
		insert(root,key);
	}

	show(root);
	popMax(root);
	show(root);
}