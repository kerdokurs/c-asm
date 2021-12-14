.source Main.java
.class Main
.super java/lang/Object

.method <init>()V
.limit stack 1
.limit locals 1

.var 0 is this LMain; from Label0 to Label1

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
.var 0 is this LMain; from Label1 to Label2
.var 1 is arg0 I from Label1 to Label1
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

.method public static main([Ljava/lang/String;)V
.limit stack 4
.limit locals 2

.var 0 is arg0 [Ljava/lang/String; from Label0 to Label1

Label0:
.line 10
  new Main
  dup
  invokespecial Main/<init>()V
  astore_1

.line 11
  getstatic java.lang.System.out Ljava/io/PrintStream;
  aload_1
  iconst_1
  iconst_2
  invokevirtual Main/func(II)I
  invokevirtual java/io/PrintStream/println(I)V
Label1:
  return
.end method
