.class public outs/Complex
.super java/lang/Object

.method public static main([Ljava/lang/String;)V
	.limit stack 20
	.limit locals 3
	ldc 0
	istore 1
	ldc 1
	istore 2
FORS1:
	iload 2
	ldc 1001
if_icmpge FORE1
	iload 2
	i2f
	ldc 400
	i2f
	frem
	ldc 0
	i2f
	fcmpg
ifne CS3
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
	iload 1
	i2f
	ldc 1
	i2f
	fadd
	f2i
	istore 1
	goto IFE2
IFS2:
	iload 2
	i2f
	ldc 4
	i2f
	frem
	ldc 0
	i2f
	fcmpg
ifne CS6
	iconst_1
	goto CE6
CS6:
	iconst_0
CE6:
ifeq CS7
	iconst_1
	goto CE7
CS7:
	iconst_0
CE7:
	ifeq IFS5
	iload 2
	i2f
	ldc 100
	i2f
	frem
	ldc 0
	i2f
	fcmpg
ifle CS9
	iconst_1
	goto CE9
CS9:
	iconst_0
CE9:
ifeq CS10
	iconst_1
	goto CE10
CS10:
	iconst_0
CE10:
	ifeq IFS8
	iload 1
	i2f
	ldc 1
	i2f
	fadd
	f2i
	istore 1
	goto IFE8
IFS8:
IFE8:
	goto IFE5
IFS5:
IFE5:
IFE2:
	iinc 2 1
	goto FORS1
FORE1:
	getstatic java/lang/System.out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream.println(I)V
	return
.end method

