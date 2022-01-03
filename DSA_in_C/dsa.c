// Stack
// #include<stdio.h>
// void push(int ar[],int n){
//     if(n>=100) printf("Stack is full\n");
//     else{
//         int k;
//         scanf("%d",&k);
//         ar[n+1]=k;
//     }
// }
// void pop(int ar[],int *n){
//     if(*n==0){
//         printf("Stack is empty\n");
//     }
//     else{
//         ar[*n]='\0';
//         (*n)--;
//     }
// }
// void disp(int ar[],int n){
//     if(n==0) printf("Stack is empty\n");
//     else{
//         for(int i=1;i<=n;++i) printf("%d ",ar[i]);
//         printf("\n");
//     }
// }
// int main(){
//     int n=0,l=0;
//     int ar[100];
//     while(l!=4){
//         printf("Menu\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
//         scanf("%d",&l);
//         switch(l){
//             case 1:
//             push(ar,n);
//             n++;
//             break;
//             case 2:
//             pop(ar,&n);
//             break;
//             case 3:
//             disp(ar,n);
//             break;
//             default:
//             continue;
//         }
//     }
// }

//  Queue
// #include<stdio.h>
// #include<stdlib.h>
// #define size 10
// int queue[size];
// int front=-1,rear=-1;
// void enqueue(){
//     if(rear>=size) printf("Overflow\n");
//     else{
//         if(front==-1) front=0;
//         printf("Enter element\n");
//         int n;
//         scanf("%d",&n);rear++;
//         queue[rear]=n;
//     }
// }
// void dequeue(){
//     if(front==-1 || front>rear) printf("Underflow\n");
//     else front++;
// }
// void show(){
//     if(front>rear) printf("Underflow\n");
//     else{
//         for(int i=front;i<=rear;++i) printf("%d ",queue[i]);
//     printf("\n");
//     }
// }
// int main(){
//     int choice=0;
//     while(choice!=4){
//     printf("1-Add\n2-Delete\n3-Show\n4-Exit\n");
//     scanf("%d",&choice);
//     switch(choice){
//         case 1:
//             enqueue();
//             break;
//         case 2:
//             dequeue();
//             break;
//         case 3:
//             show();
//             break;
//         default:
//             exit(0);
//     }}
// }

// Circular Queue
// #include<stdio.h>
// #include<stdlib.h>
// #define size 6
// int queue[size];
// int front=-1,rear=-1;

// void enqueue(){
//     if(front==(rear+1)%size) printf("Overflow\n");
//     else{
//         int n;
//         printf("Enter element\n");
//         scanf("%d",&n);
//         if(rear==size-1 && front!=0){
//             rear=0;queue[rear]=n;
//         }else queue[++rear]=n;
//         if(front==-1) front=0;
//     }
// }
// void dequeue(){
//     if(front==-1) printf("Underflow\n");
//     else{
//         int n;
//         n=queue[front];
//         queue[front]=-1;
//         if(front==rear){
//             front=-1;rear=-1;
//         }else front=(front+1)%size;
//         printf("Element deleted %d\n",n);
//     }
// }
// void show(){
//     if(front==-1) printf("Underflow\n");
//     else if(rear>=front){
//         for(int i=front;i<=rear;++i) printf("%d ",queue[i]);
//         printf("\n");
//     }else{
//         for(int i=front;i<size;++i) printf("%d ",queue[i]);
//         for(int i=0;i<=rear;++i) printf("%d ",queue[i]);
//         printf("\n");
//     }
// }
// int main(){
//     int choice=0;
//     while(choice!=4){
//         printf("1-Add\n2-Delete\n3-Show\n4-Exit\n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//                 enqueue();
//                 break;
//             case 2:
//                 dequeue();
//                 break;
//             case 3:
//                 show();
//                 break;
//             default:
//                 exit(0);
//         }
//     }
// }

// Singly Linked List
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node* next;
// }*head=NULL,*temp;
// void finsert(){
//     struct node *ptr;
//     int t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else{
//         printf("Element\n");scanf("%d",&t);
//         ptr->data=t;
//         ptr->next=head;
//         head=ptr;
//     }
// }
// void show(){
//     struct node *ptr;
//     ptr=head;
//     if(ptr==NULL) printf("Underflow\n");
//     else{
//         while(ptr!=NULL){
//             printf("%d ",ptr->data);
//             ptr=ptr->next;
//         }printf("\n");
//     }
// }
// void linsert(){
//     struct node *ptr;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     int t;
//     if(ptr==NULL) printf("Overflow\n");
//     else{
//         printf("Element\n");
//         scanf("%d",&t);
//         if(head==NULL){
//             ptr->data=t;
//             ptr->next=NULL;
//             head=ptr;printf("%d\n",ptr->data);
//         }else{
//             ptr->data=t;
//             temp=head;
//             while(temp->next!=NULL) temp=temp->next;
//             temp->next=ptr;
//             ptr->next=NULL;
//         }
//     }
// }
// void rinsert(){
//     struct node *ptr;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     int t,l;
//     if(ptr==NULL) printf("Overflow\n");
//     else{
//         printf("Element\n");scanf("%d",&t);
//         ptr->data=t;
//         temp=head;
//         printf("Index\n");scanf("%d",&l);
//         for(int i=0;i<l;++i){
//             if(temp==NULL){
//                 printf("Beyond Limit\n");return;
//             }temp=temp->next;
//         }
//         ptr->next=temp->next;
//         temp->next=ptr;
//     }
// }
// void fdelete(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         ptr=head;
//         head=ptr->next;
//         free(ptr);
//     }
// }
// void ldelete(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL){
//         head=NULL;
//         free(head);
//     }else{
//         temp=head;
//         while(temp->next!=NULL){
//             ptr=temp;
//             temp=temp->next;
//         }ptr->next=NULL;
//         free(temp);
//     }
// }
// void rdelete(){
//     struct node *ptr,*pt;
//     int l;
//     printf("Index\n");scanf("%d",&l);
//     ptr=head;
//      for(int i=0;i<l;++i){
//             pt=ptr;
//             ptr=ptr->next;
//             if(ptr==NULL){
//                 printf("Beyond Limits\n");
//                 return;
//             }
//         }pt->next=ptr->next;
//         free(ptr);
// }
// void search(){
//     struct node *ptr;
//     int l,i=0;
//     printf("Value\n");scanf("%d",&l);
//     ptr=head;
//     do{
//         if(ptr->data==l){
//             printf("Found at %d\n",i);
//             return;
//         }i++;ptr=ptr->next;
//     }while(ptr!=NULL);
//     printf("Not Found\n");
// }
// int main(){
//     int ch=0;
//     do{
//         printf("1-Front_Add 2-Last_Add 3-R_Add 4-Front_Delete 5-Last_Delete 6-R_Delete 7-Show 8-Search 9-Exit\n");
//         scanf("%d",&ch);
//         switch (ch)
//         {
//         case 1:
//             finsert();
//             break;
//         case 2:
//             linsert();
//             break;
//         case 3:
//             rinsert();break;
//         case 4:
//             fdelete();
//             break;
//         case 5:
//             ldelete();
//             break;
//         case 6:
//             rdelete();
//             break;
//         case 7:
//             show();
//             break;
//         case 8:
//             search();
//             break;
//         default:
//             exit(0);
//         }
//     }while(ch!=9);
// }

//Doubly Linked List
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     struct node *prev,*next;
//     int data;
// }*head;

// void push(){
//     struct node *ptr;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else if(head==NULL){
//         ptr->next=ptr->prev=NULL;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         head=ptr;
//     }else{
//         ptr->next=head;
//         ptr->prev=NULL;
//         head->prev=ptr;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         head=ptr;
//     }
// }

// void show(){
//     struct node *ptr;
//     ptr=head;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         while(ptr!=NULL){
//             printf("%d ",ptr->data);
//             ptr=ptr->next;
//         }printf("\n");
//     }
// }

// void pushback(){
//     struct node *ptr,*t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else if(head==NULL){
//         ptr->next=ptr->prev=NULL;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         head=ptr;
//     }else{
//         t=head;
//         while(t->next!=NULL) t=t->next;
//         t->next=ptr;
//         ptr->prev=t;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         ptr->next=NULL;
//     }
// }

// void pushbetween(){
//     struct node *ptr,*t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else{
//         int l;printf("Location\n");
//         scanf("%d",&l);
//         t=head;
//         for(int i=0;i<l;++i){
//             t=t->next;
//             if(t==NULL){
//                 printf("Out of Index\n");
//                 return;
//             }
//         }(t->next)->prev=ptr;
//         ptr->next=t->next;
//         ptr->prev=t;
//         t->next=ptr;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//     }
// }

// void pop(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL){
//         head=NULL;
//         free(head);
//     }else{
//         ptr=head;
//         head=head->next;
//         head->prev=NULL;
//         free(ptr);
//     }
// }

// void popback(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL){
//         head=NULL;free(head);
//     }else{
//         ptr=head;
//         while(ptr->next!=NULL) ptr=ptr->next;
//         (ptr->prev)->next=NULL;
//         free(ptr);
//     }
// }

// void popbetween(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         printf("Location\n");
//         int l;scanf("%d",&l);
//         ptr=head;
//         for(int i=0;i<=l;++i){
//             ptr=ptr->next;
//             if(ptr==NULL || ptr->next==NULL || ptr->prev==NULL){
//                 printf("Cant Delete\n");return;
//             }
//         }
//         (ptr->prev)->next=ptr->next;
//         (ptr->next)->prev=ptr->prev;
//         free(ptr);
//     }
// }

// void search(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         int l,i=0,f=0;printf("Element\n");
//         scanf("%d",&l);
//         ptr=head;
//         while(ptr!=NULL){
//             if(ptr->data==l){
//                 printf("Found %d at index %d\n",l,i);
//                 return;
//             }ptr=ptr->next;i++;
//         }printf("Not Found\n");
//     }
// }

// int main(){
//     int ch=0;
//     do{
//         printf("1-Push 2-Show 3-PushBack 4-PushBetween 5-Pop 6-Popback 7-PopBetween 8-Search 9-Exit\n");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1:
//                 push();break;
//             case 2:
//                 show();break;
//             case 3:
//                 pushback();break;
//             case 4:
//                 pushbetween();break;
//             case 5:
//                 pop();
//                 break;
//             case 6:
//                 popback();
//                 break;
//             case 7:
//                 popbetween();
//                 break;
//             case 8:
//                 search();
//                 break;
//             default:
//                 break;
//         }
//     }while(ch!=9);
// }

// Circular Linked List from Singly Linked List
// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     struct node *next;
//     int data;
// }*head,*rear;

// void push(){
//     struct node *ptr;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else if(head==NULL){
//         int l;printf("Element\n");
//         scanf("%d",&ptr->data);
//         ptr->next=NULL;
//         head=ptr;
//         rear=ptr;
//     }
//     else{
//         int l;printf("Element1\n");
//         scanf("%d",&ptr->data);
//         ptr->next=head;
//         head=ptr;
//         rear->next=ptr;
//     }
// }

// void pushback(){
//     struct node *ptr,*t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else if(head==NULL){
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         ptr->next=NULL;
//         head=ptr;rear=ptr;
//     }else{
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         rear->next=ptr;
//         rear=ptr;
//         ptr->next=head;
//     }
// }

// void show(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         ptr=head;
//         while(ptr->next!=NULL && ptr->next!=head){
//             printf("%d ",ptr->data);
//             ptr=ptr->next;
//         }if(ptr->next==head || ptr->next==NULL) printf("%d ",ptr->data);
//         printf("\n");
//     }
// }

// void pop(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL || head->next==head){
//         head=rear=NULL;
//     }
//     else{
//         ptr=head;
//         head=head->next;
//         rear->next=head;
//         free(ptr);
//     }
// }

// void popback(){
//     struct node *ptr,*t;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL || head->next==head){
//         head=rear=NULL;
//     }
//     else{
//         t=head;
//         while(t->next!=NULL && t->next!=rear) t=t->next;
//         ptr=rear;
//         rear=t;
//         t->next=head;
//         free(ptr);
//     }
// }

// void search(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         int l,i=0;printf("Element\n");
//         scanf("%d",&l);
//         ptr=head;
//         while(ptr->next!=NULL && ptr->next!=head){
//             if(ptr->data==l){
//                 printf("Found %d at index %d\n",l,i);
//                 return;
//             }ptr=ptr->next;i++;
//         }if(ptr->next==NULL || ptr->next==head){
//             if(ptr->data==l){
//                 printf("Found %d at index %d\n",l,i);
//                 return;
//             }
//         }printf("Not Found\n");
//     }
// }

// void pushbetween(){
//     struct node *ptr,*t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else{
//         int l;printf("Location\n");
//         scanf("%d",&l);
//         t=head;
//         for(int i=0;i<l;++i){
//             t=t->next;
//             if(t->next==NULL || t->next==head){
//                 printf("Cant Push\n");
//                 return;
//             }
//         }ptr->next=t->next;
//         t->next=ptr;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//     }
// }

// void popbetween(){
//     struct node *ptr,*t;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         ptr=head;
//         int l;printf("Location\n");
//         scanf("%d",&l);
//         for(int i=0;i<l;++i){
//             ptr=ptr->next;
//             if(ptr->next==NULL || ptr->next==rear){
//                 printf("Cant Delete\n");
//                 return;
//             }
//         }t=ptr->next;
//         ptr->next=t->next;
//         free(t);
//     }
// }

// int main(){
//     int ch=0;
//     do{
//         printf("1-Push 2-PushBack 3-Show 4-Pop 5-Popback 6-Search 7-PushBetween 8-PopBetween 9-Exit\n");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1:
//             push();
//             break;
//             case 2:
//             pushback();
//             break;
//             case 3:
//             show();
//             break;
//             case 4:
//             pop();
//             break;
//             case 5:
//             popback();
//             break;
//             case 6:
//             search();
//             break;
//             case 7:
//             pushbetween();
//             break;
//             case 8:
//             popbetween();
//             break;
//             default:
//             break;
//         }
//     }while(ch!=9);
// }

// Circular Linked List from Doubly Linked List
// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     struct node *next,*prev;
//     int data;
// }*head,*rear;

// void push(){
//     struct node *ptr;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else if(head==NULL){
//         int l;printf("Element\n");
//         scanf("%d",&ptr->data);
//         ptr->next=ptr->prev=NULL;
//         head=ptr;
//         rear=ptr;
//     }
//     else{
//         int l;printf("Element\n");
//         scanf("%d",&ptr->data);
//         ptr->next=head;
//         ptr->prev=rear;
//         head->prev=rear->next=ptr;
//         head=ptr;
//     }
// }

// void pushback(){
//     struct node *ptr,*t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else if(head==NULL){
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         ptr->next=ptr->prev=NULL;
//         head=ptr;rear=ptr;
//     }else{
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//         rear->next=ptr;
//         ptr->prev=rear;
//         ptr->next=head;
//         rear=ptr;
//     }
// }

// void show(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         ptr=head;
//         while(ptr->next!=NULL && ptr->next!=head){
//             printf("%d ",ptr->data);
//             ptr=ptr->next;
//         }if(ptr->next==head || ptr->next==NULL) printf("%d ",ptr->data);
//         printf("\n");
//     }
// }

// void pop(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL || head->next==head){
//         head=rear=NULL;
//     }
//     else{
//         ptr=head;
//         head=head->next;
//         head->prev=rear;
//         rear->next=head;
//         free(ptr);
//     }
// }

// void popback(){
//     struct node *ptr,*t;
//     if(head==NULL) printf("Underflow\n");
//     else if(head->next==NULL || head->next==head){
//         head=rear=NULL;
//     }
//     else{
//         t=head;
//         while(t->next!=NULL && t->next!=rear) t=t->next;
//         t->next=head;
//         head->prev=t;
//         ptr=rear;
//         rear=t;
//         free(ptr);
//     }
// }

// void search(){
//     struct node *ptr;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         int l,i=0;printf("Element\n");
//         scanf("%d",&l);
//         ptr=head;
//         while(ptr->next!=NULL && ptr->next!=head){
//             if(ptr->data==l){
//                 printf("Found %d at index %d\n",l,i);
//                 return;
//             }ptr=ptr->next;i++;
//         }if(ptr->next==NULL || ptr->next==head){
//             if(ptr->data==l){
//                 printf("Found %d at index %d\n",l,i);
//                 return;
//             }
//         }printf("Not Found\n");
//     }
// }

// void pushbetween(){
//     struct node *ptr,*t;
//     ptr=(struct node*) malloc(sizeof(struct node));
//     if(ptr==NULL) printf("Overflow\n");
//     else{
//         int l;printf("Location\n");
//         scanf("%d",&l);
//         t=head;
//         for(int i=0;i<l;++i){
//             t=t->next;
//             if(t->next==NULL || t->next==head){
//                 printf("Cant Push\n");
//                 return;
//             }
//         }ptr->next=(t->next);
//         ptr->prev=t;
//         (t->next)->prev=t->next=ptr;
//         printf("Element\n");
//         scanf("%d",&ptr->data);
//     }
// }

// void popbetween(){
//     struct node *ptr,*t;
//     if(head==NULL) printf("Underflow\n");
//     else{
//         ptr=head;
//         int l;printf("Location\n");
//         scanf("%d",&l);
//         for(int i=0;i<l;++i){
//             ptr=ptr->next;
//             if(ptr->next==NULL || ptr->next==rear){
//                 printf("Cant Delete\n");
//                 return;
//             }
//         }t=ptr->next;
//         ptr->next=t->next;
//         (t->next)->prev=ptr;
//         free(t);
//     }
// }

// int main(){
//     int ch=0;
//     do{
//         printf("1-Push 2-PushBack 3-Show 4-Pop 5-Popback 6-Search 7-PushBetween 8-PopBetween 9-Exit\n");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1:
//             push();
//             break;
//             case 2:
//             pushback();
//             break;
//             case 3:
//             show();
//             break;
//             case 4:
//             pop();
//             break;
//             case 5:
//             popback();
//             break;
//             case 6:
//             search();
//             break;
//             case 7:
//             pushbetween();
//             break;
//             case 8:
//             popbetween();
//             break;
//             default:
//             break;
//         }
//     }while(ch!=9);
// }

// Sorting
// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// void swap(int *a,int *b){
//     int t;
//     t=*a;*a=*b;*b=t;
// }
// void insertion(int ar[],int n){
//     int j,key;
//     for(int i=1;i<n;++i){
//         key=ar[i];
//         j=i-1;
//         while(j>=0 && ar[j]<key){
//             ar[j+1]=ar[j];
//             j--;
//         }ar[j+1]=key;
//     }
// }

// void selection(int ar[],int n){
//     int max;
//     for(int i=0;i<n-1;++i){
//         max=i;
//         for(int j=i+1;j<n;++j){
//             if(ar[j]>ar[max]) max=j;
//         }
//         swap(&ar[i],&ar[max]);
//     }
// }

// void bubble(int ar[],int n){
//     for(int i=0;i<n-1;++i){
//         for(int j=0;j<n-i-1;++j){
//             if(ar[j+1]>ar[j]) swap(&ar[j+1],&ar[j]);
//         }
//     }
// }

// void merge(int ar[],int l,int r,int mid){
//     int i=l,j=mid+1,k=l;
//     int b[100];
//     while(i<=mid && j<=r){
//         if(ar[i]>ar[j]){
//             b[k]=ar[i];i++;
//         }else{
//             b[k]=ar[j];j++;
//         }k++;
//     }if(i>mid){
//         while(j<=r){
//             b[k]=ar[j];j++;k++;
//         }
//     }else{
//         while(i<=mid){
//             b[k]=ar[i];i++;k++;
//         }
//     }for(k=l;k<=r;++k) ar[k]=b[k];
// }

// void mergesort(int ar[],int l,int r){
//     if(l<r){
//         int mid=(l+r)/2;
//         mergesort(ar,l,mid);
//         mergesort(ar,mid+1,r);
//         merge(ar,l,r,mid);
//     }
// }

// // Taking the first element as pivot
// int pivot_pos(int ar[],int l,int r){
//     int pivot=ar[l],i=l,j=r;
//     while(i<j){
//         while(i<=r && ar[i]>=pivot) i++;
//         while(j>=l && ar[j]<pivot) j--;
//         if(i<j) swap(&ar[i],&ar[j]);
//     }swap(&ar[l],&ar[j]);
//     return j;
// }
// void quicksort(int ar[],int l,int r){
//     if(l<r){
//         int p=pivot_pos(ar,l,r);
//         quicksort(ar,l,p-1);
//         quicksort(ar,p+1,r);
//     }
// }

// // Taking the last element as pivot
// int pivot(int ar[],int l,int r){
//     int p=ar[r],i=l,j=r;
//     while(i<=j){
//         while(i<=r && ar[i]<p) i++;
//         while(j>=l && ar[j]>=p) j--;
//         if(i<j) swap(&ar[i],&ar[j]);
//     }swap(&ar[r],&ar[i]);
//     return i;
// }
// void quicksort(int ar[],int l,int r){
//     if(l<r){
//         int p=pivot(ar,l,r);
//         quicksort(ar,l,p-1);
//         quicksort(ar,p+1,r);
//     }
// }

// // Taking the middle element as pivot
// int pivot(int ar[],int l,int r){
//     int mid=(l+r)/2;
//     int p=ar[mid],i=l,j=r;
//     while(i<=j){
//         if(ar[i]<p) i++;
//         else if(ar[j]>p) j--;
//         else{
//             swap(&ar[i],&ar[j]);
//             i++;j--;
//         }
//     }return i;
// }
// void quicksort(int ar[],int l,int r){
//     int p=pivot(ar,l,r);
//     if(l<p-1) quicksort(ar,l,p-1);
//     if(p<r) quicksort(ar,p,r);
// }

// int main(){
//     srand(time(0));
//     int n;scanf("%d",&n);
//     int ar[n];
//     for(int i=0;i<n;++i) ar[i]=rand();
//     for(int i=0;i<n;++i) printf("%d ",ar[i]);
//     printf("\n");
//     // insertion(ar,n);
//     // selection(ar,n);
//     // bubble(ar,n);
//     // mergesort(ar,0,n-1);
//     quicksort(ar,0,n-1);
//     for(int i=0;i<n;++i) printf("%d ",ar[i]);
// }

// Infix to Postfix
// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
// #include<string.h>
// int stack[100];
// int top=-1;
// void push(char c){
//     if(top>=100) printf("Overflow\n");
//     else{
//         top++;stack[top]=c;
//     }
// }

// char pop(){
//     if(top==-1){
//         return '0';
//     }
//     else{
//         char c=stack[top];
//         stack[top]='\0';
//         top--;
//         return c;
//     }
// }

// int isoperator(char c){
//     if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return 1;
//     else return 0;
// }

// int pred(char c){
//     if(c=='^') return 3;
//     else if(c=='*' || c=='/') return 2;
//     else if(c=='+' || c=='-') return 1;
//     else return 0;
// }

// int main(){
//     int n;
//     char str[100],x;scanf("%s",str);
//     n=strlen(str);
//     for(int i=0;i<n;++i){
//         char cur=str[i];
//         if(cur==' ') continue;
//         if(cur=='(') push(cur);
//         else if(isdigit(cur) || isalpha(cur)) printf("%c",cur);
//         else if(isoperator(cur)){
//             if(pred(cur)>pred(stack[top])) push(cur);
//             else{
//                 x=pop();
//                 while(isoperator(x)==1 && pred(x)>=pred(cur)){
//                     printf("%c",x);
//                     x=pop();
//                 }push(cur);// to compensate for the extra pop for the dissatisfied round of the loop
//                 if(x!='0') push(x);
//             }
//         }
//         else if(cur==')'){
//             x=pop();
//             while(x!='('){
//                 printf("%c",x);
//                 x=pop();
//             }
//         }
//     }while(top!=-1){
//         printf("%c",stack[top]);
//         --top;
//     }
// }

// Binary Search Tree
// #include<stdio.h>
// #include<stdlib.h>

// struct tree{
//     int data;
//     struct tree *l,*r;
// };

// void insert(struct tree **root,int item){
//     struct tree *cur,*parent,*node;
//     node=(struct tree*)malloc(sizeof(struct tree));
//     node->data=item;
//     node->l=node->r=NULL;
//     if(*root==NULL) *root=node;
//     else{
//         cur=*root;
//         parent=NULL;
//         while(1){
//             parent=cur;
//             if(item<parent->data){
//                 cur=cur->l;
//                 if(cur==NULL){
//                     parent->l=node;
//                     return;
//                 }
//             }else{
//                 cur=cur->r;
//                 if(cur==NULL){
//                     parent->r=node;
//                     return;
//                 }
//             }
//         }
//     }
// }

// struct tree* min(struct tree *root){
//     while(root->l!=NULL) root=root->l;
//     return root;
// }

// void search(struct tree **cur,int item,struct tree **parent,struct tree *root){
//     *cur=root;
//     *parent=NULL;
//     if(cur==NULL) printf("Empty tree\n");
//     else{
//         while(*cur!=NULL && (*cur)->data!=item){
//             *parent=*cur;
//             if(item<(*cur)->data) *cur=(*cur)->l;
//             else *cur=(*cur)->r;
//         }
//     }
// }

// void delete(struct tree **root,int item){
//     struct tree *cur,*parent;
//     search(&cur,item,&parent,*root);
//     if(cur==NULL) printf("Node not found\n");
//     else if(cur==*root) *root=NULL;
//     else if(cur->l==NULL && cur->r==NULL){
//         if(cur==parent->l) parent->l=NULL;
//         else parent->r=NULL;
//         free(cur);
//     }
//     else if(cur->l && cur->r){
//         struct tree *temp=min(cur->r);
//         int t=temp->data;
//         delete(root,temp->data);
//         cur->data=t;
//     }else{
//         struct tree *child=(cur->l)?cur->l:cur->r;
//         if(cur==parent->l) parent->l=child;
//         else parent->r=child;
//         free(cur);
//     }
// }

// void preorder(struct tree *root){
//     if(root){
//         printf("%d ",root->data);
//         preorder(root->l);
//         preorder(root->r);
//     }
// }

// void inorder(struct tree *root){
//     if(root){
//         inorder(root->l);
//         printf("%d ",root->data);
//         inorder(root->r);
//     }
// }

// void postorder(struct tree *root){
//     if(root){
//         postorder(root->l);
//         postorder(root->r);
//         printf("%d ",root->data);
//     }
// }

// int main(){
//     struct tree *root;
//     root=NULL;
//     int n,temp,t;printf("Total Nodes\n");
//     scanf("%d",&n);
//     for(int i=0;i<n;++i){
//         scanf("%d",&temp);
//         insert(&root,temp);
//     }
//     printf("Inorder\n");
//     inorder(root);
//     printf("\n");
//     printf("Preorder\n");
//     preorder(root);
//     printf("\n");
//     printf("Postorder\n");
//     postorder(root);
//     printf("\n");
//     printf("Total Deletions\n");
//     scanf("%d",&t);
//     for(int i=0;i<t;++i){
//         printf("Item: ");
//         scanf("%d",&temp);
//         delete(&root,temp);
//     }
//     printf("Inorder\n");
//     inorder(root);
//     printf("\n");
//     printf("Preorder\n");
//     preorder(root);
//     printf("\n");
//     printf("Postorder\n");
//     postorder(root);
//     printf("\n");
// }

// BFS & DFS on trees
// #include "stdio.h"
// #include "stdlib.h"
// #define sc scanf
// #define pr printf

// // data structure for tree
// typedef struct tree{
//   int data;
//   struct tree *left,*right;
// }tree;


// void insert(tree **root,int item){
//   tree *cur,*parent=NULL,*node=(tree*)malloc(sizeof(tree));
//   node->data=item;
//   node->left=node->right=NULL;
//   // empty tree
//   if(*root==NULL) *root=node;
//   else{
//     // searching for the right spot for insertion
//     cur=*root;
//     while(1){
//       // fixing the parent & moving the cur pointer
//       parent=cur;
//       if(item<parent->data){
//         cur=cur->left;
//         // end of the current tree
//         if(cur==NULL){
//           parent->left=node;
//           return;
//         }
//       }
//       else{
//         cur=cur->right;
//         // end of the current tree
//         if(cur==NULL){
//           parent->right=node;
//           return;
//         }
//       }
//     }
//   }
// }

// // dfs driver (Same as preorder)
// void dfs(tree *root){
//   if(root){
//     pr("%d ",root->data);
//     dfs(root->left);
//     dfs(root->right);
//   }
// }

// // finding the height of the tree
// int height(tree *root){
//   if(root==NULL) return 0;
//   else{
//     // comparing the height left & right
//     // & taking the max out of them
//     int left=height(root->left);
//     int right=height(root->right);
//     // '+1' for the root level
//     if(left>right) return left+1;
//     else return right+1;
//   }
// }

// // scanning each level
// void scanLevel(tree *root,int level){
//   // end of the tree
//   if(root==NULL) return;
//   // leaf node (level hit)
//   else if(level==1) pr("%d ",root->data);
//   // searching for the right level
//   else{
//     scanLevel(root->left,level-1);
//     scanLevel(root->right,level-1);
//   } 
// }

// // BFS driver
// void bfs(tree *root){
//   int h=height(root);
//   // scanning each level
//   for(int i=0;i<=h;++i){
//     scanLevel(root,i);
//   }
// }


// int main(){
//   int n,item;
//   pr("Total Nodes: ");
//   sc("%d",&n);
//   pr("Values:\n");
//   // initializing the tree
//   tree *root=NULL;
//   for(int i=0;i<n;++i){
//     sc("%d",&item);
//     insert(&root,item);
//   }
//   pr("BFS: ");
//   bfs(root);
//   pr("\n");
//   pr("DFS: ");
//   dfs(root);
//   pr("\n");
// }


// BFS & DFS on graphs
// #include "stdio.h"
// #include "stdlib.h"
// #define pr printf
// #define sc scanf
// // pointers for bfs traversals
// int f=0,r=-1,count=0;
// //bfs driver 
// void bfs(int **g,int v,int n,int visited[],int q[]){
// 	for(int i=0;i<n;++i){
// 		if(g[v][i] && !visited[i]){
//       // pushing vertex into the visited queue
//       // and marking it visited
// 			q[++r]=i;
//       visited[i]=1;
//       pr("%d ",i);
//     }
// 	}
//   // f pointer to scan for the unvisited nodes
//   // connected to the already visited nodess
// 	if(++f<=r){
// 		// exploring the visited vertices one by one
// 		bfs(g,q[f],n,visited,q);
// 	}
// }

// void dfs(int **g,int v,int n,int visited[]){
// 	visited[v]=1;
// 	for(int i=0;i<n;++i){
// 		if(g[v][i] && !visited[i]){
// 			pr("%d ",i);
// 			// exploring other connected vertex
// 			dfs(g,i,n,visited);
// 		}
// 	}
// }

// int main(){
// 	int n,ch,start;
// 	pr("Total Vertices: ");
// 	sc("%d",&n);
// 	// the graph (dynamic allocation)
// 	int **g=(int**)malloc(n*(sizeof(int*)));
// 	// the visited array (dynamic allocation)
// 	int *visited=(int*)malloc(n*(sizeof(int)));
// 	// the queue for storing the current node 
// 	// to be explore fully (dynamic allocation)
// 	// used in dfs
// 	int *q=(int*)malloc(n*(sizeof(int)));
// 	for(int i=0;i<n;++i){
// 		// 2D array dynamic allocation
// 		g[i]=(int*)malloc(n*(sizeof(int)));
// 		// initializing visited & q to zero 
// 		visited[i]=0;
// 		for(int j=0;j<n;++j){
// 			sc("%d",&g[i][j]);
// 		}
// 	}
// 	pr("Starting Vertex: ");
// 	sc("%d",&start);
// 	pr("1-BFS 2-DFS\n");
// 	sc("%d",&ch);
// 	switch(ch){
// 		case 1:
//       // Pushing first element
//       q[++r]=start;
//       visited[start]=1;
//       pr("BFS: %d ",start);
// 			bfs(g,start,n,visited,q);
// 			pr("\n");
// 			break;
// 		case 2:
// 			pr("%d ",start);
// 			dfs(g,start,n,visited);
// 			pr("\n");
// 			break;
// 	}
// }


// Kruskal , Prims & Dijkstra's Algorithm
// #include "stdio.h"
// #include "stdlib.h"
// #define pr printf
// #define sc scanf
// #define INF 10e6

// int minCostPrims(int *visited,int *cost,int n){
// 	int min=INF,minVertex;
// 	for(int i=0;i<n;++i){
// 		if( !visited[i] && cost[i]<min)
// 			min=cost[i],minVertex=i;
// 	}
// 	return minVertex;
// }

// void printPrism(int **g,int *parent,int n){
// 	int total=0;
// 	pr("Minimum Spanning Tree:\n");
// 	for(int i=1;i<n;++i){
// 		if(parent[i]<i)
// 			pr("%d-->%d = %d\n",parent[i],i,g[parent[i]][i]);
// 		else
// 			pr("%d-->%d = %d\n",i,parent[i],g[parent[i]][i]);
// 		total+=g[parent[i]][i];
// 	}
// 	pr("Total Cost: %d\n",total);
// }

// void prims(int **g,int n){
// 	int *parent=(int*)malloc(n*(sizeof(int)));
// 	int *cost=(int*)malloc(n*(sizeof(int)));
// 	int *visited=(int*)malloc(n*(sizeof(int)));
// 	for(int i=0;i<n;++i)
// 		cost[i]=INF,visited[i]=0;
// 	cost[0]=0,parent[0]=-1;
// 	for(int c=0;c<n-1;++c){
// 		int i=minCostPrims(visited,cost,n);
// 		visited[i]=1;
// 		for(int j=0;j<n;++j){
// 			if( !visited[j] && g[i][j] && g[i][j]<cost[j])
// 				cost[j]=g[iz
// 		}
// 	}
// 	printPrism(g,parent,n);
// }

// int minCostDijkstra(int *visited,int *cost,int n){
// 	int min=INF,minVertex;
// 	for(int i=0;i<n;++i){
// 		if( !visited[i] && cost[i]<min)
// 			min=cost[i],minVertex=i;
// 	}
// 	return minVertex;
// }

// void printDijkstra(int *cost,int n){
// 	int src=0;
// 	for(int i=0;i<n;++i){
// 		pr("%d--%d = %d\n",src,i,cost[i]);
// 	}
// }

// void dijkstra(int **g,int n){
// 	int *parent=(int*)malloc(n*(sizeof(int)));
// 	int *visited=(int*)malloc(n*(sizeof(int)));
// 	int *cost=(int*)malloc(n*(sizeof(int)));
// 	for(int i=0;i<n;++i)
// 		cost[i]=INF,visited[i]=0;
// 	parent[0]=-1,cost[0]=0;
// 	for(int c=0;c<n-1;++c){
// 		int i=minCostDijkstra(visited,cost,n);
// 		visited[i]=1;
// 		for(int j=0;j<n;++j){
// 			if(!visited[j] && g[i][j] && cost[i]!=INF && cost[i]+g[i][j]<cost[j])
// 			cost[j]=cost[i]+g[i][j],parent[j]=i;
// 		}
// 	}
// 	printDijkstra(cost,n);
// }

// int main(){
// 	int n,ch;	
// 	pr("Total Vertices: ");
// 	sc("%d",&n);
// 	int **g=(int**)malloc(n*(sizeof(int*)));
// 	for(int i=0;i<n;++i){
// 		g[i]=(int*)malloc(n*(sizeof(int)));
// 		for(int j=0;j<n;++j){
// 			sc("%d",&g[i][j]);
// 		}
// 	}
// 	pr("1-Prims 2-Kruskal 3-Dijkstra\n");
// 	sc("%d",&ch);
// 	switch(ch){
// 		case 1:
// 		prims(g,n);
// 			break;
// 		case 2:
// 			break;
// 		case 3:
// 			dijkstra(g,n);
// 			break;
// 	}
// }
