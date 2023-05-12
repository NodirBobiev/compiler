.class public outs/FibRec
.super java/lang/Object

.method public static fibonacci(I)I
	.limit stack 20
	.limit locals 2
	iload 0
	i2f
	ldc 0
	i2f
	fcmpg
ifne CS2
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
	ldc 0
	ireturn
	goto IFE1
IFS1:
IFE1:
	iload 0
	i2f
	ldc 1
	i2f
	fcmpg
ifne CS5
	iconst_1
	goto CE5
CS5:
	iconst_0
CE5:
ifeq CS6
	iconst_1
	goto CE6
CS6:
	iconst_0
CE6:
	ifeq IFS4
	ldc 1
	ireturn
	goto IFE4
IFS4:
IFE4:
	iload 0
	i2f
	ldc 2
	i2f
	fcmpg
ifne CS8
	iconst_1
	goto CE8
CS8:
	iconst_0
CE8:
ifeq CS9
	iconst_1
	goto CE9
CS9:
	iconst_0
CE9:
	ifeq IFS7
	ldc 1
	ireturn
	goto IFE7
IFS7:
IFE7:
	iload 0
	i2f
	ldc 2
	i2f
	fsub
	f2i
	invokestatic outs/FibRec/fibonacci(I)I
	iload 0
	i2f
	ldc 1
	i2f
	fsub
	f2i
	invokestatic outs/FibRec/fibonacci(I)I
	fadd
	f2i
	ireturn
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 2
	ldc 5
	istore 1
	getstatic java/lang/System.out Ljava/io/PrintStream;
	iload 1
	invokestatic outs/FibRec/fibonacci(I)I
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

