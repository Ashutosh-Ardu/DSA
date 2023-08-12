import java.util.*;

public class searchAlgo {
  static void show(int[] ar)
  {
    for(int i : ar)
      System.out.print(i + " ");
    System.out.println();
  }

  static void lSearch(int[]ar,int val)
  {
    for(int i = 0 ;i < ar.length;++i)
    {
      if(ar[i] == val)
      {
        System.out.println("Found at " + i +" index");
        return;
      }
    }
    System.out.println("Not Found");
  }

  static void bSearch(int[]ar,int val)
  {
    int s = 0;
    int e = ar.length - 1;
    
    while(s <= e)
    {
      int m = s + (e - s) / 2;
      System.out.println(m);
      if(ar[m] == val)
      {
        System.out.println("Found at index " + m);
        return;
      }
      else if(val > ar[m])
        s = m + 1;
      else
        e = m - 1;
    }
    System.out.println("Not Found");
  }

  static void bSearchR(int[]ar,int val,int s,int e)
  {
    if(s <= e)
    {
      int m = s + (e - s)/2;
      if(ar[m] == val)
      {
        System.out.println("Found at Index " + m);
        return;
      }
      bSearchR(ar,val,s,m-1);
      bSearchR(ar,val,m+1,e);
    }
  }

  public static void main(String[] args) {
    Random  r = new Random();
    Scanner scan = new Scanner(System.in);

    // int n = 10;
    int n = scan.nextInt();
    int[] ar = new int[n];

    for(int i=0;i<n;i++)
      // ar[i] = r.nextInt(1000);
      ar[i] = scan.nextInt();
    Arrays.sort(ar);
    show(ar);
    int val = scan.nextInt();
    // lSearch(ar,val);
    
    // requires sorted array
    // bSearch(ar,val);
    bSearchR(ar,val,0,n-1);
  }
}
