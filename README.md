# Imperative Language compiler
Give a look at Description.pdf

## Description
Task was write a compiler for an imperative language and convert to java bytecode.

The implementation is composed of the following parts:

- Lexical Analyzer: implemented using Flex
- Syntax Analyzer: implemented using Bison
- Semantic Analyzer: implemented using the Visitor pattern
- Code Generation: implemented using the Visitor pattern


## How to run:
```
bash commands.sh <source_file_name> <dest_file_name> <java_class_name> 
```

### Example:

```
bash commmands.sh age.txt age.j Age
```


or


```
bash commands.sh fib.txt fib.j Fib
```


## Contribution

- Nodir Bobiev and Shohjahon Khamrakulov: implemented the Syntax Analyzer and Code Generation stages.
- Davlat Magzumov and Aibek Bakirov: implemented the Lexical Analyzer and Semantic Analyzer stages.


