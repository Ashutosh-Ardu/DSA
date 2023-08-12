import java.util.*;

// bst
class bst
{
  int v;
  bst r,l;

  bst()
  {
    v = 0;
    r = l = null;
  }

  bst(int v)
  {
    this.v = v;
    r = l = null;
  }

  static bst insert(bst root,int v)
  {
    if(root == null)
      return new bst(v);
    else
    {
      bst cur = root;
      bst parent = null;
      while(true)
      {
        parent = cur;
        if(v < parent.v)
        {
          cur = cur.l;
          if(cur == null)
          {
            parent.l = new bst(v);
            return root;
          }
        }
        else
        {
          cur = cur.r;
          if(cur == null)
          {
            parent.r = new bst(v);
            return root;
          }
        }
      }
    }
  }

  static void inorder(bst root)
  {
    if(root != null)
    {
      inorder(root.l);
      System.out.print(root.v+" ");
      inorder(root.r);
    }
  }

  static void preorder(bst root)
  {
    if(root != null)
    {
      System.out.print(root.v+" ");
      inorder(root.l);
      inorder(root.r);
    }
  }
  static void postorder(bst root)
  {
    if(root != null)
    {
      inorder(root.l);
      inorder(root.r);
      System.out.print(root.v+" ");
    }
  }

  static bst[] search(bst cur,bst parent,int v)
  {
    if(cur == null)
    {
      bst ret[] = new bst[2];
      ret[0] = ret[1] = null;
      return ret;
    }
    else
    {
      while(cur != null && cur.v != v)
      {
        parent = cur;
        if(v < parent.v)
          cur = cur.l;
        else
          cur = cur.r;
      }
      bst ret[] = new bst[2];
      ret[0] = parent;
      ret[1] = cur;
      return ret;
    }
  }

  static bst minNode(bst root)
  {
    while(root.l != null)
      root = root.l;
    return root;
  }

  static bst delNode(bst root,int v)
  {
    bst cur = root,parent = null;
    bst ret[] = search(cur,parent,v);
    cur = ret[1];
    parent = ret[0];
    if(cur == null)
    {
      System.out.println("Node not found");
      return cur;
    }
    else if(cur == root)
      return null;
    else if(cur.l == null && cur.r == null)
    {
      if(parent.l == cur)
        parent.l = null;
      else
        parent.r = null;
    }
    else if(cur.l != null && cur.r != null)
    {
      bst t = minNode(cur.r);
      int temp = t.v;
      root = delNode(root,temp);
      cur.v = temp;
    }
    else
    {
      bst ch = (cur.l != null) ? cur.l : cur.r;
      if(parent.l == cur)
        parent.l = ch;
      else
        parent.r = ch;
    }
    return root;
  }
}


public class binarySearchTree
{
  static int ht(bst root)
  {
    if(root == null)
      return 0;
    else
    {
      int left = ht(root.l);
      int right = ht(root.r);
      if(left > right)
        return left + 1;
      return right + 1;
    }
  }

  static void scanLevel(bst root,int l)
  {
    if(root == null)
      return;
    else if(l == 1)
      System.out.print(root.v + " ");
    else
    {
      scanLevel(root.l,l-1);
      scanLevel(root.r,l-1);
    }
  }

  static void bfs(bst root)
  {
    int h = ht(root);

    for(int i=1;i<=h;i++)
      scanLevel(root,i);
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();

    bst ar = null;

    for(int i=0;i<n;i++)
    {
      int v = scan.nextInt();
      ar = ar.insert(ar,v);
    }

    ar.inorder(ar);
    System.out.println();
    bfs(ar);
    System.out.println();
    ar = ar.delNode(ar,45);
    ar.inorder(ar);
    System.out.println();
  }
}