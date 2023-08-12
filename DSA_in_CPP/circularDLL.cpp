#include "iostream"
using namespace std;

// Doubly Linked Circular List

// a single list is connected to 
// to the list before it n after it (so each list has a total of 2 connections)
/*    					A										B									C
HEAD<---->prev|data|next<---->prev|data|next<--->prev|data|next<--->HEAD
*/ 

/*
	You can use diff (git) command to find the difference
	between dll and circular dll
	the only difference is tht
	rear->next = HEAD
	instead of 
	rear->next = NULL
*/

struct dll{
	int data;
	dll *prev,*next;//only thing from SLL (prev)
};

dll* createDLL(){
	dll *temp=new dll;
	cout<<"Value: ";
	cin>>temp->data;
	temp->prev=temp->next=NULL;
	return temp;
}

void push(dll* &head){
	dll *ptr=createDLL(),*temp=head;
	if(ptr){
		if(head==NULL){
			head=ptr;//empty list
			head->next=head;//creating the circular link
		}
		else{
			while(temp->next!=head)
				temp=temp->next;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
			temp->next=head;//pointing to the new head node
		}
	}
	else
		cout<<"Heap Full\n";
}

void pop(dll* &head){
	dll *ptr,*temp;
	ptr=temp=head;
	if(ptr){
		if(head->next==head){
			head=NULL;
		}
		else{
			while(temp->next!=head)
				temp=temp->next;
			head=head->next;
			head->prev=NULL;
			temp->next=head;//pointing to the new head after the pop operation
		}
		delete ptr;
	}
	else
		cout<<"Empty\n";
}

void show(dll *head){
	dll *ptr=head;
	if(ptr){
		while(ptr->next!=head){
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<ptr->data<<endl;
	}
	else
		cout<<"Empty\n";
}

void search(dll *head){
	dll *ptr=head;
	if(ptr){
		int item,i=0;
		cout<<"Value: ";
		cin>>item;
		while(ptr->next!=head){
			if(ptr->data==item){
				cout<<"Found at "<<i<<endl;
				return;
			}
			i+=1;
			ptr=ptr->next;
		}
		if(ptr->data==item)
			cout<<"Found at "<<i<<endl;
		else
			cout<<"Not Found\n";
	}
	else
		cout<<"Empty\n";
}

void lpush(dll* &head){
	dll *temp=head,*ptr=createDLL();
	if(ptr){
		if(head==NULL){
			head=ptr;
			head->next=head;
		}
		else{
			while(temp->next!=head)
				temp=temp->next;
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=head;//extra link for creating the circular effect
		}
	}
	else
		cout<<"Heap is Full\n";
}

void lpop(dll* &head){
	dll *ptr,*temp=head;
	if(temp){	
		if(head->next==head)
			head=NULL;
		else{
			while(temp->next!=head)
				temp=temp->next;
			ptr=temp->prev;
			ptr->next=head;
		}
		delete temp;
	}
	else
		cout<<"Empty\n";
}

void rpush(dll* &head){
	dll *ptr=createDLL(),*temp=head;
	if(ptr){
		int pos;
		cout<<"Index : ";
		cin>>pos;
		for(int i=0;i<pos;++i){
			temp=temp->next;
			if(temp->next==head){
				cout<<"Cannot be inserted\n";
				return;
			}
		}
		ptr->next=temp->next;
		ptr->prev=temp;
		temp->next=ptr;
	}	
	else
		cout<<"Heap is Full\n";
}

void rpop(dll* &head){
	dll *ptr=head,*temp;
	if(ptr){
		int pos;
		cout<<"Index : ";
		cin>>pos;
		for(int i=0;i<pos;++i){
			ptr=ptr->next;
			if(ptr->next->next==head){//cause u cant delete the last list
				cout<<"Cannot be deleted\n";//hence u make the second last list
				return;// as the deadend
			}
		}
		temp=ptr->next;
		temp->next->prev=ptr;
		ptr->next=temp->next;
		delete temp;
	}
	else	
		cout<<"Empty\n";
}

int main(){
	int ch;
	dll *head=NULL;
	do{
		cout<<"1]Push 2]Pop 3]Show 4]Search 5]Lpush 6]Rpop 7]Rpush 8]Rpop 9]Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				push(head);
				break;
			case 2:
				pop(head);
				break;
			case 3:
				show(head);
				break;
			case 4:
				search(head);
				break;
			case 5:
				lpush(head);
				break;
			case 6:
				lpop(head);
				break;
			case 7:
				rpush(head);
				break;
			case 8:
				rpop(head);
				break;
		}
	}while(ch!=9);
}