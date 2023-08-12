import java.util.*;

class heaps
{
  int cur,cap;
  int ar[];

  heaps()
  {
    cur = 0;
    cap = 50;
    ar = new int[cap];
  }
}

public class maxHeap {
  static void show(heaps hp)
  {
    if(hp.cur > 0)
    {
      for(int i = 0;i<hp.cur;i++)
        System.out.print(hp.ar[i]+" ");
      System.out.println();
    }
    else
      System.out.println("Empty Heap");
  }

  static void heapifyTB(heaps hp,int ind)
  {
    int l = ind * 2 + 1;
    int r = ind * 2 + 2;
    int m = ind;

    if(l < hp.cur && hp.ar[l] > hp.ar[m])
      m = l;
    if(r < hp.cur && hp.ar[r] > hp.ar[m])
      m = r;
    
    if(m != ind)
    {
      int t = hp.ar[m];
      hp.ar[m] = hp.ar[ind];
      hp.ar[ind] = t;
      heapifyTB(hp,m);
    }
  }

  static void heapifyBT(heaps hp,int ind)
  {
    int p = (ind - 1) / 2;

    if(hp.ar[ind] > hp.ar[p])
    {
      int t = hp.ar[p];
      hp.ar[p] = hp.ar[ind];
      hp.ar[ind] = t;
      heapifyBT(hp,p);
    }
  }

  static void insert(heaps hp,int v)
  {
    if(hp.cur < hp.cap)
    {
      hp.ar[hp.cur] = v;
      heapifyBT(hp,hp.cur);
      hp.cur++;
    }
  }

  static void pop(heaps hp)
  {
    if(hp.cur > 0)
    {
      hp.ar[0] = hp.ar[--hp.cur];
      heapifyTB(hp,0);
    }
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();

    heaps hp = new heaps();

    for(int i=0;i<n;i++)
    {
      int v = scan.nextInt();
      insert(hp,v);
    }
    show(hp);
    pop(hp);
    show(hp);
  }  
}
