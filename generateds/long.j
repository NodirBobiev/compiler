.class public outs/ForLoop
.super java/lang/Object

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 3
	ldc 15
	istore 2
	ldc 1
	istore 1
FORS1:
	iload 1
	ldc 11
if_icmpge FORE1
	iload 1
	i2f
	ldc 5
	i2f
	fcmpg
ifle CS3
	iconst_1
	goto CE3
CS3:
	iconst_0
CE3:
ifeq CS4
	iconst_1
	goto CE4
CS4:
	iconst_0
CE4:
	ifeq IFS2
	iload 2
	i2f
	iload 1
	i2f
	fadd
	f2i
	istore 2
	goto IFE2
IFS2:
	iload 2
	i2f
	iload 1
	i2f
	fsub
	f2i
	istore 2
IFE2:
	iinc 1 1
	goto FORS1
FORE1:
	getstatic java/lang/System.out Ljava/io/PrintStream;
	iload 2
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

