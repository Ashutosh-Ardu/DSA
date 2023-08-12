import java.util.*;

public class sortAlgos {
  static void show(int []ar,int n)
  {
    for(int i : ar)
      System.out.print(i + " ");
    System.out.println();
  }

  static void bSort(int []ar,int n)
  {
    for(int i=0;i<n-1;i++)
    {
      boolean b = false;
      for(int j=0;j<n-1-i;j++)
      {
        if(ar[j] > ar[j+1])
        {
          int t = ar[j];
          ar[j] = ar[j+1];
          ar[j+1] = t;
          b = true;
        }
      }
      if(b == false)
        break;
    }
    // return ar;
  }

  static void iSort(int []ar,int n)
  {
    int min;
    for(int i=0;i<n-1;i++)
    {
      min = i;
      for(int j = i+1;j < n;j++)
      {
        if(ar[j] < ar[min])
          min = j;
      }
      int t = ar[min];
      ar[min] = ar[i];
      ar[i] = t;
    }
    // return ar;
  }

  static void sSort(int[] ar,int n)
  {
    int j,key;
    for(int i=1;i<n;i++)
    {
      j = i - 1;
      key = ar[i];
      while(j >= 0 && ar[j] > key)
        ar[j+1] = ar[j--];
      ar[j+1] = key;
    }
    // return ar;
  }

  static void merge(int[] ar,int s,int e,int m)
  {
    int k = s,i = s,j = m+1;
    int b[] = new int[100];

    while(i <= m && j <= e)
    {
      if(ar[i] < ar[j])
        b[k++] = ar[i++];
      else
        b[k++] = ar[j++];
    }

    if(i > m)
    {
      while(j <= e)
        b[k++] = ar[j++];
    }
    else
    {
      while(i <= m)
        b[k++] = ar[i++];
    }
    // return b;
    for(k = s;k<=e;k++)
      ar[k] = b[k];
  }

  static void mSort(int[] ar,int s,int e)
  {
    if(s < e)
    {
      int m = (s + e) / 2;
      mSort(ar,s,m);
      mSort(ar,m+1,e);
      merge(ar,s,e,m);
    }
    // return ar;
  }

  static int pivot1(int[]ar,int s,int e)
  {
    int p = ar[s],i = s,j = e;

    while(i < j)
    {
      while(i <= e && ar[i] <= p)
        i++;
      while(j >= s && ar[j] > p)
        j--;
      if(i < j)
      {
        int t = ar[i];
        ar[i] = ar[j];
        ar[j] = t;
      }
    }
    int t = ar[s];
    ar[s] = ar[j];
    ar[j] = t;
    return j;
  }

  static void qSort1(int []ar,int s,int e)
  {
    if(s < e)
    {
      int p = pivot1(ar,s,e);
      qSort1(ar, s, p-1);
      qSort1(ar,p+1,e);
    }
  }

  static int pivot2(int[]ar,int s,int e)
  {
    int p = ar[e],i = s,j = e;

    while(i < j)
    {
      while(i <= e && ar[i] < p)
        i++;
      while(j >= s && ar[j] >= p)
        j--;
      if(i < j)
      {
        int t = ar[i];
        ar[i] = ar[j];
        ar[j] = t;
      }
    }
    int t = ar[s];
    ar[s] = ar[i];
    ar[i] = t;
    return i;
  }

  static void qSort2(int []ar,int s,int e)
  {
    if(s < e)
    {
      int p = pivot1(ar,s,e);
      qSort2(ar, s, p-1);
      qSort2(ar,p+1,e);
    }
  }

  static int pivot3(int[]ar,int s,int e)
  {
    int i = s,j = e,m = (s+e)/2;
    int p = ar[m];

    while(i < j)
    {
      if(ar[i] < p)
        i++;
      else if(ar[j] > p)
        j--;
      else
      {
        int t = ar[i];
        ar[i] = ar[j];
        ar[j] = t;
      }
    }
    return i;
  }

  static void qSort3(int []ar,int s,int e)
  {
    if(s < e)
    {
      int p = pivot3(ar,s,e);
      if(s < p-1)
        qSort3(ar, s, p-1);
      if(p < e)
        qSort3(ar,p+1,e);
    }
  }

  static int getMax(int[]ar,int n)
  {
    int m = ar[0];
    for(int i =1;i<n;i++)
    {
      if(ar[i] > m)
        m = ar[i];
    }
    return m;
  }

  static void dSort(int[]ar,int pos,int n)
  {
    int output[] = new int[n];
    int cnt[] = new int[10];

    for(int i = 0;i<n;i++)
      cnt[(ar[i]/pos)%10]++;
    
    for(int i=1;i<n;i++)
      cnt[i] += cnt[i-1];
    
    for(int i=n-1;i>=0;i--)
      output[--(cnt[(ar[i]/pos)%10])] = ar[i];
    
    for(int i=0;i<n;i++)
      ar[i] = output[i];
  }

  static void cSort(int[]ar,int n)
  {
    int output[] = new int[n];
    int cnt[] = new int[1000];

    for(int i = 0;i<n;i++)
      cnt[ar[i]]++;
    
    for(int i=1;i<1000;i++)
      cnt[i] += cnt[i-1];
    
    for(int i=n-1;i>=0;i--)
      output[--(cnt[ar[i]])] = ar[i];
    
    for(int i=0;i<n;i++)
      ar[i] = output[i];
  }

  static void rSort(int[]ar,int n)
  {
    int m = getMax(ar,n);

    for(int i=1;m/i>0;i*=10)
      dSort(ar,i,n);
  }

  static void shSort(int[]ar,int n)
  {
    for(int g = n/2;g > 0;g/=2)
    {
      for(int i=g;i<n;i++)
      {
        int j = i;
        int k = ar[i];
        for(;j >= g && ar[j-g] > k;j-=g)
          ar[j] = ar[j-g];
        ar[j] = k;
      }
    } 
  }

  static void heapifyTB(int[]ar,int ind,int n)
  {
    int l = (ind * 2) + 1;
    int r = (ind * 2) + 2;
    int mx = ind;

    if(l < n && ar[l] > ar[mx])
      mx = l;
    if(r < n && ar[r] > ar[mx])
      mx = r;
    
    if(mx != ind)
    {
      int t = ar[mx];
      ar[mx] = ar[ind];
      ar[ind] = t;
      heapifyTB(ar,mx,n);
    }
  }

  static void hSort(int[]ar,int n)
  {
    for(int i=n/2-1;i>=0;i--)
      heapifyTB(ar,i,n);
    
    for(int i=n-1;i>0;i--)
    {
      int t = ar[0];
      ar[0] = ar[i];
      ar[i] = t;
      heapifyTB(ar,0,i);
    }
  }

  class bucket
  {
    int ar[];
    int n;

    bucket()
    {
      ar = new int[10];
      n = 0;
    }
  }

  static void bucSort(int[]ar,int n)
  {
    bucket b[] = new bucket[10];
    sortAlgos t = new sortAlgos();
    for(int i=0;i<10;i++)
    {
      b[i] = t.new bucket();
    }

    for(int i=0;i<n;i++)
    {
      int ind = ar[i] / 100;
      b[ind].ar[b[ind].n] = ar[i];
      b[ind].n++;
    }

    int index = 0;
    for(int i=0;i<10;i++)
    {
      iSort(b[i].ar,b[i].n);
      for(int j=0;j<b[i].n;j++)
        ar[index++] = b[i].ar[j];
    }
  }

  public static void main(String[] args) {
    Random r = new Random();
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    
    int ar[] = new int[n];
    for(int i=0;i<n;i++)
      ar[i] = r.nextInt(1000);
    
    show(ar,n);
    // bSort(ar,n);
    // sSort(ar,n);
    // iSort(ar,n);
    // mSort(ar,0,n-1);
    // qSort1(ar,0,n-1);
    // qSort2(ar,0,n-1);
    // qSort3(ar,0,n-1);
    // rSort(ar,n);
    // cSort(ar,n);
    // bucSort(ar,n);
    // hSort(ar,n);
    // shSort(ar,n);
    show(ar,n);
  }  
}
