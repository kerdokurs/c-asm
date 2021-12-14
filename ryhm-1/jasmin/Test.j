.source Test.java
.class Test
.super java/lang/Object

.method <init>()V
.limit stack 1
.limit locals 1

.var 0 is this LTest; from Label0 to Label1

Label0:
.line 1
  aload_0
  invokespecial java/lang/Object/<init>()V
Label1:
  return
.end method

.method func(II)I
.limit stack 2
.limit locals 3

.var 0 is this LTest; from Label1 to Label2
.var 1 is arg0 I from Label1 to Label2
.var 2 is arg1 I from Label1 to Label2

Label1:
.line 3
  iload_1
  iload_2
  if_icmpge Label0
.line 4
  iconst_1
  ireturn
Label0:
.line 5
  iconst_2
Label2:
  ireturn
.end method

.method func2(FZ)I
.limit stack 4
.limit locals 3

.var 0 is this LTest; from Label0 to Label1
.var 1 is arg0 F from Label0 to Label1
.var 2 is arg1 Z from Label0 to Label1

Label0:
.line 10
  fload_1
  f2d
  dconst_1
  dcmpl
  iflt Label2
  iload_2
  ifeq Label3
  goto Label2
Label1:
Label3:
.line 12
  iconst_1
  ireturn
Label2:
  iconst_2
  ireturn
.end method

.method public static main([Ljava/lang/String;)V
.limit stack 4
.limit locals 2

.var 0 is arg0 [Ljava/lang/String; from Label0 to Label1

Label0:
.line 10
  new Test
  dup
  invokespecial Test/<init>()V
  astore_1

.line 11
  getstatic java.lang.System.out Ljava/io/PrintStream;
  aload_1
  iconst_1
  iconst_2
  invokevirtual Test/func(II)I
  invokevirtual java/io/PrintStream/println(I)V
.line 12
  getstatic java.lang.System.out Ljava/io/PrintStream;
  aload_1
  fconst_2
  iconst_1
  invokevirtual Test/func2(FZ)I
  invokevirtual java/io/PrintStream/println(I)V
Label1:
  return
.end method
