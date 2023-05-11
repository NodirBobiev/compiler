.class public temp/Test
.super java/lang/Object

; standard initializer
.method public <init>()V
   aload_0
   invokenonvirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
   .limit locals 19
   .limit stack 20
   sipush 0
  istore 1
   sipush 0
   istore 2
   FOR1:
   iload 2
   sipush 1001
   if_icmpge EXIT1
   iload 2
   sipush 400
   irem
   sipush 0
if_icmpne LSART2
 iconst_1  
  goto LEND2
LSART2:
 iconst_0
LEND2:
   ifeq IF_EXIT3
   iload 1
   sipush 1
   iadd
  istore 1
   goto IF_END3
   IF_EXIT3:
   iload 2
   sipush 4
   irem
   sipush 0
if_icmpne LSART4
 iconst_1  
  goto LEND4
LSART4:
 iconst_0
LEND4:
   ifeq IF_EXIT5
   iload 2
   sipush 100
   irem
   sipush 0
if_icmple LSART6
 iconst_1  
  goto LEND6
LSART6:
 iconst_0
LEND6:
   ifeq IF_EXIT7
   iload 1
   sipush 1
   iadd
  istore 1
   goto IF_END7
   IF_EXIT7:
   IF_END7:
   goto IF_END5
   IF_EXIT5:
   IF_END5:
   IF_END3:
   iinc 2 1
   goto FOR1
   EXIT1:
   iload 1
  istore 3
  getstatic java/lang/System.out Ljava/io/PrintStream;
  iload 3
  invokevirtual java/io/PrintStream.println(I)V
return
.end method

