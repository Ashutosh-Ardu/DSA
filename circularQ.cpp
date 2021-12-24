#include "iostream"
using namespace std;
#define size 4
// Circular Queue

struct queue{
  int ar[30];//max size 30 for now
  int f,r;
};

queue* queueInit(){
  queue *str=new queue;
  str->f=str->r=-1;
  return str;
}

// just connect the front n rear of the queue
void push(queue *list){
  int item;
  if(list->f==(list->r+1)%size)//connecting the front n rear
    cout<<"Full\n";
  else{
    cout<<"Value : ";
    cin>>item;
    list->r=(list->r+1)%size;
    list->ar[list->r]=item;
    if(list->f==-1) list->f=0;
  }
}

void pop(queue *str){
  if(str->f==-1)//connecting the front and rear
    cout<<"Empty\n";
  else if(str->f==str->r)
    str->f=str->r=-1;
  else
    str->f=(str->f+1)%size;//connecting the front and rear
}

/*
initial queue
  1<--front
2   3  rear is at 2
5   6
  7
after deletion
  3<--front
_  6 rear is still at 2
2  7
  5
*/
void show(queue *str){
  if(str->f==-1)
    cout<<"Empty\n";
  else{
    if(str->f<=str->r){//for following the circular path
        for (int  i = str->f; i <= str->r; i++){
          cout<<str->ar[i]<<" ";
        }
    }
    else{
      for(int i=str->f;i<size;++i)
        cout<<str->ar[i]<<" ";
      for(int i=0;i<=str->r;++i)
        cout<<str->ar[i]<<" ";
    }
    cout<<endl;
  }
  
}

void search(queue *list){
  if(list->f==-1)
    cout<<"Empty\n";
  else{
    int item;
    cout<<"Value : ";
    cin>>item;
    if(list->f<=list->r){
      for(int i=list->f;i<=list->r;++i){
        if(list->ar[i]==item){
          cout<<"Present"<<endl;
          return;
        }
      }
      cout<<"Not Found\n";
    }
    else{
      for(int i=list->f;i<size;++i){
        if(list->ar[i]==item){
          cout<<"Present"<<endl;
          return;
        }
      }
      for(int i=0;i<=list->r;++i){
        if(list->ar[i]==item){
          cout<<"Present"<<endl;
          return;
        }
      }
      cout<<"Not Found"<<endl;
    }
  }
}



int main(){
  queue *list=queueInit();
  int ch;
  do{
    cout<<"1]Push 2]Pop 3]Show 4]Search 5]Exit\n";
    cin>>ch;
    switch (ch)
    {
    case 1:
      push(list);
      break;
    case 2:
      pop(list);
      break;
    case 3:
      show(list);
      break;
    case 4:
      search(list);
      break;
    default:
      break;
    }
  }while(ch!=5);
}