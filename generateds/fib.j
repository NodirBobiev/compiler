.class public outs/Fib
.super java/lang/Object

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 6
	ldc 10
	istore 1
	ldc 1
	istore 2
	ldc 0
	istore 3
	ldc 0
	istore 4
FORS1:
	iload 4
	iload 1
if_icmpge FORE1
	iload 3
	istore 5
	iload 2
	istore 3
	iload 5
	i2f
	iload 2
	i2f
	fadd
	f2i
	istore 2
	iinc 4 1
	goto FORS1
FORE1:
	getstatic java/lang/System.out Ljava/io/PrintStream;
	iload 2
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

