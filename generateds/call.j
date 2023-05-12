.class public outs/Call
.super java/lang/Object

.method public static sum(II)I
	.limit stack 20
	.limit locals 3
	iload 0
	i2f
	iload 1
	i2f
	fadd
	f2i
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 3
	ldc 10
	istore 1
	ldc 20
	istore 2
	getstatic java/lang/System.out Ljava/io/PrintStream;
	iload 1
	iload 2
	invokestatic outs/Call/sum(II)I
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

