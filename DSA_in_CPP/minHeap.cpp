#include "iostream"
using namespace std;

struct heap{
	int *ar;
	int capacity,cur;// max size and current position of the counter
};

heap* heapInit(){
	heap *ptr = new heap;
	ptr->cur = 0;
	ptr->capacity = 50;// 50 for now
	ptr->ar = new int[50];
	return ptr;
}

void swap(int &a,int &b){
	int t=a;a=b;b=t;
}

void heapifyBT(heap *root,int index){
	int parent = (index - 1) / 2;// floor value is taken 
	if(root->ar[parent] > root->ar[index]){//parent < (should be) child
		swap(root->ar[parent],root->ar[index]);
		heapifyBT(root,parent);// bottom to top heapify
	}
}

void heapifyTB(heap *root,int parent){
	int left = parent * 2 + 1;// with starting index as 0
	int right = parent * 2 + 2;
	int min = parent;

	if(left >= root->cur || left < 0)
		left = -1;// these error values can occur while recursive calls

	if(right >= root->cur || right < 0)
		right = -1;
	
	if(left != -1 && root->ar[left] <root->ar[parent])
		min = left;// parent < (should be) child

	if(right != -1 && root->ar[right] <root->ar[parent])
		min = right;

	if(min != parent){
		swap(root->ar[parent],root->ar[min]);
		heapifyTB(root,min);// top to bottom heapify
	}
}

void insert(heap *root,int key){
	if(root->cur < root->capacity){
		root->ar[root->cur] = key;
		heapifyBT(root,root->cur);//first find the right positions for all the elements
		root->cur += 1;// then increment the counter as heap's range is from 0-->counter-1
	}
}

void show(heap *root){
	for(int i=0;i<root->cur;++i)
		cout<<root->ar[i]<<" ";
	cout<<"\n";
}

void popMin(heap *root){
	if(root->cur){
		root->ar[0] = root->ar[root->cur - 1];// with lately added value
		root->cur -= 1;
		heapifyTB(root,0);//as the value is push from bottom to the top 
	}//hence we need to heapify from top to bottom
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
	popMin(root);
	show(root);
}