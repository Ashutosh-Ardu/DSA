#include "iostream"
using namespace std;
// Singly Linked List
// rough diagram
/*
simple structure
Head -->data|nextAddress
         |
      Address
data|nextAddress
         |
      Address
data|nextAddress
         |
         Null
last list
A train of data connected to the next list from 
head-->Null (rear)
*/

// SLL framework
struct link{
  int data;
  link *next;
};

link* create(int item){
  link *head=new link;
  head->data=item;
  head->next=NULL;
  return head;
}

void push(link* &head){//calling it using call by reference method
  int item;
  cout<<"Value : ";
  cin>>item;
  link *ptr=create(item);
  if(ptr){
    if(head==NULL)
      head=ptr;//if list is initially empty
    else{
      ptr->next=head;//connecting the new list to the old one
      head=ptr;//and making the new list as head
    }//hence creating a train of lists
  }// new    old
  //  12|B12 24|Null
  //  (A12)  (B12)
  else
    cout<<"Heap Full\n";
}

void pop(link* &head){//calling it using call by reference method
  link *ptr;
  if(head==NULL)
    cout<<"Empty\n";
  else if(head->next==NULL){
    ptr=head;
    head=NULL;
    delete ptr;
  }
  else{
    ptr=head;
    head=head->next;
    delete ptr;
  }
}

void show(link *head){
  link *ptr=head;
  if(ptr){
    ptr=head;
    cout<<"List==> ";
    while(ptr){
      cout<<ptr->data<<" ";
      ptr=ptr->next;//jumping from list to list
    }
    cout<<endl;
  }
  else
    cout<<"Empty\n";
}

void search(link *head){
  link *ptr=head;
  if(ptr){//similar method as show
    int item,i=0;
    cout<<"Value : ";
    cin>>item;
    while(ptr){
      if(ptr->data==item){
        cout<<"Found at "<<i<<endl;
        return;
      }
      i++;
      ptr=ptr->next;
    }
    cout<<"Not Found\n";
  }
  else
    cout<<"Empty\n";
}

void lpush(link* &head){
  int item;
  cout<<"Value : ";
  cin>>item;
  link *temp,*ptr=create(item);
  if(ptr){
    if(head==NULL)
      head=ptr;//empty list
    else{
      temp=head;
      while(temp->next!=NULL)
        temp=temp->next;
      temp->next=ptr;
    }
  }
  else
    cout<<"Heap Full\n";
}

void rpush(link* &head){//used to add numbers in between only.
  int item,pos;//u cant add at the start or at the end only in the middle
  cout<<"Value : ";
  cin>>item;
  cout<<"Index : ";
  cin>>pos;
  link *temp=head,*ptr=create(item);
  if(ptr && temp){
    for(int i=0;i<pos;++i){
      temp=temp->next;
      if(temp==NULL){
        cout<<"Cannot be inserted\n";
        return;//if pos is 1 then item is inserted after
      }//index 1 of the current list
    }
    ptr->next=temp->next; //initial A-B   (C)
    temp->next=ptr;//final A-C-B (C->B) (A->C)
  }
  else
    cout<<"Heap Full\n";
}

void lpop(link* &head){
  link *ptr=head,*temp;
  if(ptr){
    if(head->next==NULL){//list with only one element
      head=NULL;//hence after poping the last element
      delete ptr;//its empty
    }
    else{
      while(ptr->next->next!=NULL)
        ptr=ptr->next;//moving the pointer to the second last node
      temp=ptr->next;//making the nextAddr of Second last node as null
      ptr->next=NULL;//and later deleting the hanging node 
      delete temp;//ptr-->second last node ,temp-->last node
    }
  }
  else
    cout<<"Empty\n";
}

void rpop(link* &head){
  int pos;//removing the element at index pos
  cout<<"Index : ";
  cin>>pos;
  link *ptr=head,*temp;
  if(ptr){
    for(int i=0;i<pos;++i){
      ptr=ptr->next;
      if(ptr==NULL){
        cout<<"Cannot be inserted\n";
        return;
      }
    }
    temp=ptr->next;//initial A-C-B 
    ptr->next=temp->next;//final A-B   deleted (C)
    delete temp;
  }
  else
    cout<<"Empty\n";
}

int main(){
  link *head=NULL;
  int ch;
  do{
    cout<<"1]Push 2]Pop 3]Show 4]Search 5]Lpush 6]Lpop\n\n7]Rpush 8]Rpop 9]Exit\n";
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
      default:
        break;
    }
  }while(ch!=9);
}