#include "iostream"
#include "stdlib.h"
using namespace std;

// stacks
// last in first out (LIFO)
struct stack{
  int ar[30];//max size = 30
  int n;
};

stack* stackInit(){
  stack *str=new stack;
  str->n=-1;
  return str;
}

void append(stack *str){
  int item;
  if(str->n>=30) cout<<"Overflow\n";
  else{
    cout<<"Value : ";
    cin>>item;
    str->n+=1;
    str->ar[str->n]=item;
  }
}

void pop(stack *str){
  if(str->n==-1) cout<<"Underflow\n";
  else{
    if(str->n==0) str->n=-1;
    else str->n-=1;
  }
}

void show(stack *str){
  if(str->n==-1) cout<<"Underflow\n";
  else{
    for(int i=0;i<=str->n;++i)
      cout<<str->ar[i]<<" ";
    cout<<"<--Top\n";
  }
}

int main(){
  stack *list=stackInit();
  int ch;
  do{
    cout<<"1]Push 2]Pop 3]Show 4]Exit\n";
    cin>>ch;
    switch(ch){
      case 1:
        append(list);
        break;
      case 2:
        pop(list);
        break;
      case 3:
        show(list);
        break;
      default:
        break;
    }
  }while(ch!=4);
}