import java.util.*;

class edge
{
  int s,e;
  int c;

  edge(int s,int e,int c)
  {
    this.s = s;
    this.e = e;
    this.c = c;
  }

  public  String toString()
  {
    return s + " " + e + " " + c;
  }
}


class SortIt implements Comparator<edge>
{
  public int compare(edge a,edge b)
  {
    return a.c - b.c;
  }
}


public class mst {
  static int inf = 1000000;

  static void primsPrint(int[] parent,Vector<Vector<Integer>> g,int n)
  {
    int total = 0;

    for(int i=1;i<n;i++)
    {
      System.out.println(parent[i]+"-->" + i  + " = "+g.get(i).get(parent[i]));
      total += g.get(parent[i]).get(i);
    }
    System.out.println("Total Cost: "+total);
  }

  static int minCostVertex(int[] cost,int[] visited,int n)
  {
    int min = mst.inf,minVertex = 0;
    for(int i=0;i<n;i++)
    {
      if(visited[i] == 0 && cost[i] < min)
      {
        min = cost[i];
        minVertex = i;
      }
    }
    return minVertex;
  }

  static void prims(Vector<Vector<Integer>> g,int n)
  {
    int[] visited = new int[n];
    int[] cost = new int[n];
    int[] parent = new int[n];

    for(int i=0;i<n;i++)
    {
      cost[i] = mst.inf;
      parent[i] = i;
    }

    cost[0] = 0;

    for(int cur = 0;cur < n-1;cur++)
    {
      int i = minCostVertex(cost,visited,n);
      visited[i] = 1;

      for(int j =0;j <n;j++)
      {
        if(visited[j] == 0 && g.get(i).get(j) > 0 && cost[j] > g.get(i).get(j))
        {
          cost[j] = g.get(i).get(j);
          parent[j] = i;
        }
      }
    }
    primsPrint(parent,g,n);
  }

  
  static int findParent(int[] parent,int i)
  {
    if(parent[i] == i)
      return i;
    return findParent(parent,parent[i]);
  }

  static void printKruskal(edge[] ar,int n)
  {
    int total = 0;
    for(int i=0;i<n;i++)
    {
      System.out.println(ar[i].s+"-->"+ar[i].e+" = "+ar[i].c);
      total += ar[i].c;
    }
    System.out.println("Total Cost: "+total);
  }

  static void kruskal(Vector<Vector<Integer>> g,int n)
  {
    ArrayList<edge> l = new ArrayList<edge>();

    for(int i=1;i<n;i++)
    {
      for(int j = 0;j<i;j++)
      {
        if(g.get(i).get(j) > 0)
        {
          edge e = new edge(i,j,g.get(i).get(j));
          l.add(e);
        }
      }
    }

    // for(int i=0;i<n1;i++)
    //   System.out.println(l[i]);

    int i = 0;
    Collections.sort(l,new SortIt());

    edge f[] = new edge[n-1];
    int n1 = 0;
    int parent[] = new int[n];

    for(i=0;i<n;i++)
      parent[i] = i;
    i = 0;
    while(n1 < n-1)
    {
      edge cur = l.get(i++);
      int sparent = findParent(parent,cur.s);
      int dparent = findParent(parent,cur.e);

      if(sparent != dparent)
      {
        f[n1++] = cur;
        parent[dparent] = sparent;
      }
    }
    printKruskal(f,n1);
  }

  static void printDijkstra(int[]cost,int n)
  {
    int total = 0;
    for(int i=0;i<n;i++)
    {
      System.out.println(1+" --> "+(i + 1) + " = " + cost[i]);
      total += cost[i];
    }
    System.out.println("Total Path Cost: "+total);
  }

  static void dijkstra(Vector<Vector<Integer>> g,int n)
  {
    int[] visited = new int[n];
    int[] cost = new int[n];
    int[] parent = new int[n];

    for(int i=0;i<n;i++)
    {
      cost[i] = mst.inf;
      parent[i] = i;
    }

    cost[0] = 0;
    
    for(int c=0;c<n-1;c++)
    {
      int cur = minCostVertex(cost,visited,n);
      visited[cur] = 1;

      for(int i=0;i<n;i++)
      {
        if(visited[i] == 0 && cost[cur] != mst.inf && g.get(cur).get(i) > 0 && cost[i] > cost[cur] + g.get(cur).get(i))
        {
          cost[i] = cost[cur] + g.get(cur).get(i);
          parent[i] = cur;
        }
      }
    }
    printDijkstra(cost,n);
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    Vector<Vector<Integer>> g = new Vector<Vector<Integer>>();
    int n = scan.nextInt();

    for(int i=0;i<n;i++)
    {
      Vector<Integer> t = new Vector<Integer>();
      for(int j=0;j<n;j++)
      {
        int v = scan.nextInt();
        t.add(v);
      }
      g.add(t);
    }

    int ch = scan.nextInt();
    switch(ch)
    {
      case 1 -> prims(g,n);
      case 2 -> kruskal(g,n);
      case 3 -> dijkstra(g,n);
    }
  }  
}
