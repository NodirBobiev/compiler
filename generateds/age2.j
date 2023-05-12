.class public outs/Age2
.super java/lang/Object

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 3
	ldc 18
	istore 1
	ldc 999
	istore 2
	iload 1
	i2f
	ldc 18
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
	iload 2
	i2f
	ldc 1000
	i2f
	fcmpg
ifle CS5
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
	getstatic java/lang/System.out Ljava/io/PrintStream;
	ldc 1000
	invokevirtual java/io/PrintStream.println(I)V
	return
	goto IFE4
IFS4:
	getstatic java/lang/System.out Ljava/io/PrintStream;
	ldc 999
	invokevirtual java/io/PrintStream.println(I)V
	return
IFE4:
	goto IFE1
IFS1:
IFE1:
	getstatic java/lang/System.out Ljava/io/PrintStream;
	ldc 0
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

