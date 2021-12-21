#include "iostream"
#include "stdlib.h"
using namespace std;

// include various functions on bst like
// ->insertion
// ->deletion
// ->searching
// ->tree traversals like
// -->bfs
// -->dfs
// -->inorder
// -->preorder
// -->postorder
// on a bst -->(unbalanced bst!!)<--

// tree framework
struct tree{
  int data;
  tree *left,*right;
};

void insert(tree* &root,int item){
  tree *cur,*parent=NULL,*node=new tree;
  node->data=item;
  // as it is the leaf node
  node->left=node->right=NULL;
  // empty tree
  if(root==NULL) root=node;
  else{
    cur=root;
    // iterate until we get the right spot
    // for 'node'
    while(1){
      parent=cur;
      if(item<parent->data){
        cur=cur->left;
        // if left doesn't exists
        // then thats the place where our node fits ri8 in
        if(cur==NULL){
          parent->left=node;
          return;//as insertion is over
        }
      }
      else{
        cur=cur->right;
        // similarly
        if(cur==NULL){
          parent->right=node;
          return;
        }
      }
    }
  }
}

// finding & returning the minimum node from any given
// point as origin in the bst 
tree* minNode(tree *root){
  while(root->left!=NULL)
    root=root->left;
  return root;
}

void search(tree* &cur,int item,tree* &parent,tree *root){
  cur=root;
  parent=NULL;
  if(cur==NULL) 
    cout<<"Empty Tree\n";
  else{
    // loop goes on until it reaches end of the tree
    // or cur->data=item
    // the result if stored in cur & parent
    // hence no point returning the values
    while(cur!=NULL && cur->data!=item){
      parent=cur;
      if(item<cur->data)
        cur=cur->left;
      else
        cur=cur->right;
    }
  }
}

void del(tree* &root,int item){
  tree *cur,*parent;
  // if that item is present or not
  search(cur,item,parent,root);

  if(cur==NULL )
    cout<<"Item not found\n";
  // last node
  else if(cur==root)
    root=NULL;
  // leaf nodes
  else if(cur->left==NULL && cur->right==NULL){
    if(cur==parent->left)
      parent->left=NULL;
    else
      parent->right=NULL;
    delete cur;
  }
  // complete nodes
  else if(cur->left && cur->right){
    // first find the height node in the left or right subtree
    // which will take the place of the deleted complete node
    tree *ptr=minNode(cur->right);//you can also use max(cur->left)
    // but for the sake this code we will choose right
    // cause we always wanna be "right" :) pun intended
    // we delete the node which is moved to the newly
    // vacated area as it no longer needed in its old position
    int temp=cur->data;
    del(root,temp);
    // and just change the value of the complete node
    // as only the node->data changes not the left & right
    // childrens
    cur->data=temp;
  }
  // partial nodes
  else{
    // as we dont know which child the partial node has
    // hence we check whether the single child which it possess
    // ,is on its left or right using shorthand of if/else
    tree *child=(cur->left)?cur->left:cur->right;

    // now check on which side is the child 
    // present WRT  the parent and swap it with its only child
    if(parent->left==cur)
      parent->left=child;
    else
      parent->right=child;
      delete cur;
  }
}

// inorder used for searching purpose
void lookup(tree *root,int &item){
  if(root){
    if(root->data==item){
      cout<<"Present"<<endl;
      item=-1;
      return;
    }
    lookup(root->left,item);
    lookup(root->right,item);
  }
}

// left->root->right
void inorder(tree *root){
  if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}

// root->left->right
// this is same traversal as DFS 
// in a bst
void preorder(tree *root){
  if(root){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

// left->right->root
void postorder(tree *root){
  if(root){
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
  }
}

//finding the height of a bst
// useful in bfs while moving level->level
int height(tree *root){
  // end of tree
  if(root==NULL) return 0;
  else{
    // height of left subtree
    int left=height(root->left);
    // height of right subtree
    int right=height(root->right);
    // "+1" is for the root of that 
    // particular sub tree
    if(left>right) 
      return left+1;
    else 
      return right+1;
  }
}

// scanning a particular level in a bst 
void scanLevel(tree *root,int level){
  // end of the tree
  if(root==NULL) return;
  // we have the required level
  else if(level==1) cout<<root->data<<" ";
  // traversing the tree 
  // for reaching the specified level
  else{
    // checking for both left & right while 
    // scanning the levels
    scanLevel(root->left,level-1);
    scanLevel(root->right,level-1);
  }
}

// bfs driver
void bfs(tree *root,int n){
  int h=height(root);
  // scanning all the levels present in the bst
  for(int i=0;i<=h;++i)
    scanLevel(root,i);
  // "i" will help in recognizing the ri8 level
}

//driver code
int main(){
  int n,item,ch;
  cout<<"Total Nodes: ";
  cin>>n;

  tree *root=NULL;
  // forming the initial tree with some values
  cout<<"Values:\n";
  for(int i=0;i<n;++i){
    cin>>item;
    insert(root,item);
  }

  do{
    cout<<"1]BFS 2]DFS 3]Inorder 4]Preorder 5]Postorder 6]Delete 7]Search 8]Extra Insertions 9]Exit\n";
    cin>>ch;    

    switch(ch){
      case 1:
        cout<<"BFS : ";
        bfs(root,n);
        cout<<endl;
        break;
      case 2:
        cout<<"DFS : ";
        preorder(root);
        //same as preorder
        cout<<endl;
        break;
      case 3:
        cout<<"Inorder : ";
        inorder(root);
        cout<<endl;
        break;
      case 4:
        cout<<"Preorder : ";
        preorder(root);
        cout<<endl;
        break;
      case 5:
        cout<<"Postorder : ";
        postorder(root);
        cout<<endl;
        break;
      case 6:
        cout<<"Value : ";
        cin>>item;
        del(root,item);
        break;
      case 7:
        cout<<"Value : ";
        cin>>item;
        lookup(root,item);
        if(item!=-1)
          cout<<"Item not found\n";
        break;
      case 8:
        cout<<"Value : ";
        cin>>item;
        insert(root,item);
        break;
      default:
        break;
    }
  }while(ch!=9);
}