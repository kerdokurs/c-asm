public class Test {
  int func(int x, int y) {
    if (x < y)
      return 1;
    else
      return 2;
  }

  int func2(float x, boolean b) {
    if (x > 1.0 && b)
      return 1;
    else
      return 2;
  }

  public static void main(String[] args) {
    Test t = new Test();
    System.out.println(t.func(1, 2));
    System.out.println(t.func2(1.1, true));
  }
}
