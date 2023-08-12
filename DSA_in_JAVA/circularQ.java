import java.util.*;

public class circularQ {
  static Scanner scan = new Scanner(System.in);
  static int front = -1;
  static int rear = -1;
  

  static void push(int[] ar)
  {
    System.out.print("Val: ");
    int val = scan.nextInt();
    if((front) == (rear+1) % 5)
    {
      System.out.println("Max Capacity reached");
      return;
    }
    if(front == -1)
    {
      front = 0;
    }
    rear = (rear + 1) % 5;
    ar[rear] = val;
  }

  static void pop(int[]ar)
  {
    if(front == -1)
    {
      System.out.println("Empty");
      return;
    }
    else if(front == rear)
    {
      front = rear = -1;
      return;
    }
    front = (front + 1) % 5;
  }

  static void show(int[]ar)
  {
    if(front == -1)
    {
      System.out.println("Empty");
      return;
    }
    if(front <= rear)
    {
      for(int i = front;i <= rear;i++)
        System.out.print(ar[i]+" ");
    }
    else
    {
      for(int i=front;i<5;i++)
        System.out.print(ar[i]+" ");
        for(int i=0;i<=rear;i++)
        System.out.print(ar[i]+" ");
    }
    System.out.println();
  }

  public static void main(String[] args) {
    int ch = -1;
    int[]ar = new int[5];
    Scanner scan = new Scanner(System.in);
    do
    {
      System.out.println("1]Push 2]Pop 3]Show 4]Exit");
      ch = scan.nextInt();

      switch(ch)
      {
        case 1 -> push(ar);
        case 2 -> pop(ar);
        case 3 -> show(ar);
      }
    }while(ch != 4);
  }
}
