import java.util.*;

class avl
{
  int val,ht;
  avl left, right;

  avl(int val)
  {
    this.val = val;
    ht = 1;
    left = right = null;
  }
}

public class avlTrees {
  static int height(avl root)
  {
    if(root == null)
      return 0;
    return root.ht;
  }

  static int upHt(avl root)
  {
    if(root == null)
      return 0;
    return 1 + Math.max(height(root.left),height(root.right));
  }

  static int Bal(avl root)
  {
    if(root == null)
      return 0;
    return height(root.right) - height(root.left);
  }

  static void show(avl root)
  {
    if(root != null)
    {
      show(root.left);
      System.out.print(root.val + " ");
      show(root.right);
    }
  }

  static avl rr(avl root)
  {
    avl nroot = root.right;
    avl t = nroot.left;

    nroot.left = root;
    root.right = t;

    root.ht = upHt(root);
    nroot.ht = upHt(nroot);

    return nroot;
  }
  
  static avl ll(avl root)
  {
    avl nroot = root.left;
    avl t = nroot.right;

    nroot.right = root;
    root.left = t;

    root.ht = upHt(root);
    nroot.ht = upHt(nroot);

    return nroot;
  }

  static avl insert(avl root,int val)
  {
    if(root == null)
      return new avl(val);
    else if(val < root.val)
      root.left = insert(root.left,val);
    else if(val > root.val)
      root.right = insert(root.right,val);
    else
      return root;
    
    root.ht = upHt(root);
    int b = Bal(root);

    if(b > 1 && val > root.right.val)
      return rr(root);
    else if(b > 1 && val < root.right.val)
    {
      root.right = ll(root.right);
      return rr(root);
    }
    else if(b < -1 && val < root.left.val)
      return ll(root);
    else if(b < -1 && val > root.left.val)
    {
      root.left = rr(root.left);
      return ll(root);
    }
    return root;
  }

  static avl minNode(avl root)
  {
    while(root.left != null)
      root = root.left;
    return root;
  }

  static avl delNode(avl root,int val)
  {
    if(root == null)
    {
      System.out.println("Value not Found");
      return root;
    }
    else if(val < root.val)
      root.left = delNode(root.left,val);
    else if(val > root.val)
      root.right = delNode(root.right,val);
    else
    {
      if(root.left == null || root.right == null)
      {
        avl child = (root.left != null) ? root.left : root.right;

        if(child == null)
          root = null;
        else
          root = child;
        return root;
      }
      else 
      {
        avl nroot = minNode(root.right);
        int t = nroot.val;
        root = delNode(root,t);
        root.val = t;
        return root;
      }
    }

    if(root == null)
      return root;

    root.ht = upHt(root);
    int b = Bal(root);

    if(b > 1 && Bal(root.right) >= 0)
      return rr(root);
    else if(b > 1)
    {
      root.right = ll(root.right);
      return rr(root);
    }
    else if(b < -1 && Bal(root.left) <= 0)
      return ll(root);
    else if(b < -1)
    {
      root.left = rr(root.left);
      return ll(root);
    }
    return root;
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    avl root = null;

    for(int i=0;i<n;i++)
    {
      int val = scan.nextInt();
      root = insert(root,val);
    }

    show(root);
    System.out.println();
    root = delNode(root,30);
    show(root);
    System.out.println();
  }
}
