// Circular Linked List

#include "iostream"
#include "stdlib.h"
using namespace std;

/*
  similar to singly linked list
  only difference
  -the last node ->next should be
  :-head
  :-instead of NULL
*/

struct node{
  int data;
  node *next;
};

node* createNode(){
  node *ptr=new node;
  ptr->next=NULL;
  cout<<"Value : ";
  cin>>ptr->data;
  return ptr;
}

void push(node* &head){
  node *ptr=createNode(),*temp;
  if(ptr){
    if(head==NULL){//empty tree
      head=ptr;
      ptr->next=head;
    }
    else{
      ptr->next=head;
      temp=head;
      while(temp->next!=head)
        temp=temp->next;//for appending the new head into the rear->next
      temp->next=ptr;
      head=ptr;
    }
  }
  else
    cout<<"Heap is Full\n";
}

void pop(node* &head){
  node *ptr,*temp;
  if(head==NULL)
    cout<<"Empty\n";
  else if(head->next==head){
    ptr=head;//single node in the entire list
    head=NULL;
    delete ptr;
  }
  else{
    temp=head;
    while(temp->next!=head)
      temp=temp->next;//appending the new head to rear->next
    ptr=head;//once the old one is deleted
    head=head->next;
    temp->next=head;
    delete ptr;
  }
}

void show(node *head){
  node *ptr=head;
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

void search(node *head){
  node *ptr=head;
  if(ptr){
    int item,i=0;
    cout<<"Value : ";
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

void lpush(node* &head){
  node *ptr=createNode(),*temp=head;
  if(ptr){
    if(head==NULL){
      head=ptr;
      ptr->next=head;
    }
    else{
      while(temp->next!=head)
        temp=temp->next;//reaching the end to insert from the last
      temp->next=ptr;
      ptr->next=head;
    }
  }
}

void lpop(node* &head){
  node *ptr,*temp;
  ptr=temp=head;
  if(ptr){
    if(head->next==head){
      ptr=head;
      head=NULL;
      delete ptr;
    }
    else{
      while(temp->next->next!=head)
        temp=temp->next;//reaching the end to delete from the last
      ptr=temp->next;
      temp->next=head;
      delete ptr; 
    }
  }
  else 
    cout<<"Empty\n";
}

void rpush(node* &head)
{
  node *ptr=head,*temp=createNode();
  if(ptr){
    int pos;
    cout<<"Index : ";
    cin>>pos;//insertion takes places after the 'pos'th index 
    for(int i=0;i<pos;++i){
      ptr=ptr->next;
      if(ptr==NULL || ptr->next==head){
        cout<<"Cannot Insert\n";
        return;
      }
    }
    temp->next=ptr->next;
    ptr->next=temp;
  }
  else
    cout<<"Heap is Full\n";
}

void rpop(node* &head){
  node *ptr=head,*temp;
  if(ptr){
    int pos;
    cout<<"Index : ";
    cin>>pos;//deletion takes places after the 'pos'th index
    for(int i=0;i<pos;++i){
      ptr=ptr->next;
      if(ptr==NULL || ptr->next==head){
        cout<<"Deletion not Possible\n";
        return;
      }
    }
    temp=ptr->next;
    ptr->next=temp->next;
    delete temp;
  }
  else
    cout<<"Empty\n";
}

int main(){
  int ch;
  node *head=NULL,*rear;
  do{
    cout<<"1]Push 2]Pop 3]Show 4]Search  5]Lpush 6]Lpop 7]Rpush 8]Rpop 9]Exit\n";
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