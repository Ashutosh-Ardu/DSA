#include "iostream"
using namespace std;

// Doubly Linked List

// a single list is connected to 
// to the list before it n after it (so each list has a total of 2 connections)
/*    					A										B									C
HEAD<---->prev|data|next<---->prev|data|next<--->prev|data|next<--->NULL
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
	dll *ptr=createDLL();
	if(ptr){
		if(head==NULL)
			head=ptr;//empty list
		else{
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
	}
	else
		cout<<"Heap Full\n";
}

void pop(dll* &head){
	dll *ptr=head;
	if(ptr){
		if(head->next==NULL)
			head=NULL;
		else{
			head=head->next;
			head->prev=NULL;
		}
		delete ptr;
	}
	else
		cout<<"Empty\n";
}

void show(dll *head){
	dll *ptr=head;
	if(ptr){
		while(ptr){
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
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
		while(ptr){
			if(ptr->data==item){
				cout<<"Found at "<<i<<endl;
				return;
			}
			i+=1;
			ptr=ptr->next;
		}
		cout<<"Not Found\n";
	}
	else
		cout<<"Empty\n";
}

void lpush(dll* &head){
	dll *temp=head,*ptr=createDLL();
	if(ptr){
		if(head==NULL)
			head=ptr;
		else{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=ptr;
			ptr->prev=temp;
		}
	}
	else
		cout<<"Heap is Full\n";
}

void lpop(dll* &head){
	dll *ptr,*temp=head;
	if(temp){	
		if(head->next==NULL)
			head=NULL;
		else{
			while(temp->next!=NULL)
				temp=temp->next;
			ptr=temp->prev;
			ptr->next=NULL;
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
			if(temp->next==NULL){
				cout<<"Cannot be inserted\n";
				return;
			}
		}
		ptr->next=temp->next;
		ptr->prev=temp;//A<-->C initial
		temp->next=ptr;//A<-->B<-->C final
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
			if(ptr->next==NULL){
				cout<<"Cannot be deleted\n";
				return;
			}
		}
		temp=ptr->next;//A<-->B<-->C initial
		temp->next->prev=ptr;//A<-->C final
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