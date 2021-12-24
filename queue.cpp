#include "iostream"
using namespace std;

// Queues
// (First in First out) (FIFO)

struct queue{
  int ar[30];//max size of 30 for now
  int f,r;
};

queue* Qinit(){
  queue *str=new queue;
  str->f=str->r=-1;
  return str;
}

// push from front
void push(queue *str){
  int item;
  if(str->r==29)
    cout<<"Overflow\n";
  else{
    cout<<"Value : ";
    cin>>item;
    str->r+=1;
    str->ar[str->r]=item;
    if(str->f==-1) str->f=0;
  }
}

// pop from front
void pop(queue *str){
  if(str->f==-1)
    cout<<"Underflow\n";
  else if(str->r==0)
    str->f=str->r=-1;
  else{
    for(int i=1;i<=str->r;++i){
      str->ar[i-1]=str->ar[i];
    }
    str->r-=1;
  }
}

void show(queue *str){
  if(str->f==-1)
    cout<<"Underflow\n";
  else{
    for(int i=0;i<=str->r;++i)
      cout<<str->ar[i]<<" ";
    cout<<"<--End"<<endl;
  }
}

void search(queue *str){
  if(str->f==-1)
    cout<<"Underflow\n";
  else{
    int item;
    cout<<"Value : ";
    cin>>item;
    for(int i=0;i<=str->r;++i){
      if(str->ar[i]==item){
        cout<<"Found at "<<i<<endl;
        return;
      }
    }
    cout<<"Not Found\n";
  }
}

int main(){
  queue *list=Qinit();
  int ch;
  do{
    cout<<"1]Push 2]Pop 3]Show 4]Search 5]Exit\n";
    cin>>ch;
    switch(ch){
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
      default :
        break;
    }
  }while(ch!=5);
}