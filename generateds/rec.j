.class public outs/Rec
.super java/lang/Object

.method public static rec(II)I
	.limit stack 20
	.limit locals 3
	iload 0
	i2f
	ldc 10
	i2f
	fcmpg
ifle CS2
	iconst_1
	goto CE2
CS2:
	iconst_0
CE2:
ifeq CS3
	iconst_1
	goto CE3
CS3:
	iconst_0
CE3:
	ifeq IFS1
	iload 1
	ireturn
	goto IFE1
IFS1:
	iload 0
	i2f
	ldc 1
	i2f
	fadd
	f2i
	iload 1
	i2f
	ldc 11
	i2f
	fadd
	f2i
	invokestatic outs/Rec/rec(II)I
	ireturn
IFE1:
	iload 1
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 1
	getstatic java/lang/System.out Ljava/io/PrintStream;
	ldc 2
	ldc 0
	invokestatic outs/Rec/rec(II)I
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

