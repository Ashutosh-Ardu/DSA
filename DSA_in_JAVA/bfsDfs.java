import java.util.*;

public class bfsDfs {
  static int cnt = 0;
  static int cur = -1;

  static void bfs(Vector<Vector<Integer>> g,int c,int n,int[]visited,int[]q)
  {
    for(int i=0;i<n;i++)
    {
      if(g.get(c).get(i) > 0 && visited[i] == 0)
      {
        System.out.print(i + 1 + " ");
        visited[i] = 1;
        q[++bfsDfs.cur] = i;
      }
    }

    if(++bfsDfs.cnt <= bfsDfs.cur)
        bfs(g,q[bfsDfs.cnt],n,visited,q);
  }

  static void dfs(Vector<Vector<Integer>> g,int cur,int n,int[]visited)
  {
    visited[cur] = 1;
    for(int i=0;i<n;i++)
    {
      if(g.get(cur).get(i) > 0 && visited[i] == 0)
      {
        System.out.print(i+1+" ");
        dfs(g,i,n,visited);
      }
    }
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();

    Vector<Vector<Integer>> v = new Vector<Vector<Integer>>();;

    for(int i=0;i<n;i++)
    {
      Vector<Integer> t = new Vector<>();
      for(int j=0;j<n;j++)
      {
        int val = scan.nextInt();
        t.add(val);
      }
      v.add(t);
    }

    int ch = scan.nextInt();
    int[] visited  = new int[n];

    if(ch == 1)
    {
      int[] q  = new int[n+1];
      System.out.print("BFS: "+ 1 + " ");
      visited[0] = 1;
      q[++bfsDfs.cur] = 0;
      bfs(v,0,n,visited,q);
    }
    else
    {
      System.out.print("DFS: " + 1 + " ");
      dfs(v,0,n,visited);
    }


    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //     System.out.print(v.get(i).get(j)+" ");
    //   System.out.println();
    // }
  }  
}
