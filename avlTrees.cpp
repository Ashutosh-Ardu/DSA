#include "iostream"
#include "stdlib.h"
using namespace std;

struct node{
  int data,height;
  node *left,*right;
};

node* newNode(int key){
  node *ptr = new node;
  ptr->data = key;
  ptr->left = ptr->right = NULL;
  ptr->height = 1;// lowest possible height is "1"
  return ptr;
}

int h(node *root){
  if(!root)// useful during rotations
    return 0;//so that we dont find height for NULL node
  return root->height;// if the node is not NULL
}

int isBalance(node *root){
  if(!root)// same principle as that of "h"
    return 0;//height function
  return h(root->right) - h(root->left); 
}

/*
initial situation
    A
  B
C
after right rotation
  B
C   A
*/

node* rgtRotate(node *root){
  node *newRoot = root->left;
  node *temp = newRoot->right;
  newRoot->right = root;
  root->left = temp;
  root->height = 1 + max(h(root->left),h(root->right));
  newRoot->height = 1 + max(h(newRoot->left),h(newRoot->right));
  return newRoot;
}

/*
initial location
A
  B
    C
2-after left rotation
  B
A   C
*/

node* lftRotate(node *root){
  node *newRoot = root->right;
  node *temp = newRoot->left;
  newRoot->left = root;
  root->right = temp;
  root->height = 1 + max(h(root->left),h(root->right));
  newRoot->height = 1 + max(h(newRoot->left),h(newRoot->right));
  return newRoot;
}

node* minNode(node *root){
  node *cur = root;
  while(cur->left)
    cur = cur->left;
  return cur;
}

node* insert(node *root,int key){
  if(!root)// empty avl tree
    return newNode(key);
  if(key < root->data)//left subtree
    root->left = insert(root->left,key);
  else if(key > root->data)//right subtree
    root->right = insert(root->right,key);
  else
    return root;//if the node value is already present in the tree
  //updating the height after node insertion
  root->height = 1 + max(h(root->left),h(root->right));
  //checking its balance after insertion
  int b = isBalance(root);
  //states explained below
  if(b > 1 && key > root->right->data)//state 1
    return lftRotate(root);
  if(b > 1 && key < root->right->data){//state 2
    root->right = rgtRotate(root->right);
    return lftRotate(root);
  }
  if(b < -1 && key < root->left->data)//state 3
    return rgtRotate(root);
  if(b < -1 && key > root->left->data){//state 4
    root->left = lftRotate(root->left);
    return rgtRotate(root);
  }
  return root;//if already balanced
}

/*
state 1
A
  B
    C
state 2
A
  B
C
state 3
    A
  B
C
state 4
  A
B
  C
*/

node* delNode(node *root,int key){
  if(!root)// empty tree
    return root;
  if(key < root->data)//left subtree
    root->left = delNode(root->left,key);
  else if(key > root->data)//right subtree
    root->right = delNode(root->right,key);
  else{//node to be deleted found
    if(!(root->left) || !(root->right)){ // leaf and partial node
      node *temp = root->left ? root->left : root->right;
      if(!temp){//leaf node
        temp = root;
        root = NULL;
      }
      else//partial node
        *root = *temp;
      delete temp;
    }
    else{// complete node
      node* temp = minNode(root->right);//here max of left subtree can also be used
      root->data = temp->data;
      root = delNode(root->right,root->data);
    }
  }

  if(!root) return root;// for leaf node case (as only one node is left no need to check its balance)

  root->height = 1 + max(h(root->left),h(root->right));
  int b = isBalance(root);
  //states explained above
  if(b > 1 && isBalance(root->right) >=0)//state 1
    return lftRotate(root);
  if(b > 1 && isBalance(root->right) < 0){//state 2
    root->right = rgtRotate(root->right);
    return lftRotate(root);
  }
  if(b < -1 && isBalance(root->left) <=0)//state 3
    return rgtRotate(root);
  if(b < -1 && isBalance(root->left) >0){//state 4
    root->left = lftRotate(root->left);
    return rgtRotate(root);
  }
  return root;
}
// root-->left-->right
void preorder(node *root){
  if(root){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main(){
  int ch,key;
  node *root = NULL;
  do{
    cout<<"1]push 2]pop 3]show(preorder) 4]exit\n";
    cin>>ch;
    switch(ch){
      case 1:
        cout<<"value : ";
        cin>>key;
        root = insert(root,key);
        break;
      case 2:
        cout<<"value : ";
        cin>>key;
        root = delNode(root,key);
        break;
      case 3:
        preorder(root);
        cout<<"\n";
        break;
    }
  }while(ch!=4);
}