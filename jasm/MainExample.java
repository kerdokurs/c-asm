public class Main {
  public int func(int x, int y) {
    if (x < y)
      return 1;
    else
      return 2;
  }

  public static void main(String[] args) {
    Test t = new Test();
    System.out.println(t.func(1, 2));
  }
}
