#include <assert.h>
#include <unordered_map>
#include <stdexcept>
#include "../common/visitor.hpp"
#include <iostream>
#include "../common/type.cpp"



std::string toJasminType(Type *type)
{
    if( type == nullptr )
        return "TYPENULL";
    if( auto t = dynamic_cast<TypeBoolean*>(type))
        return "I";
    if( auto t = dynamic_cast<TypeInteger*>(type))
        return "I";
    if( auto t = dynamic_cast<TypeReal*>(type))
        return "F";
    throw std::runtime_error("toJasminType: type is not implemeneted");
}

class VarInfo{
public:
    Type *type;
    int index;
    VarInfo(Type *type, int index): type(type), index(index){}
};


class Generator: public Visitor{
public:
    std::string className = "Test";
    std::string currentRoutine = "";
    Generator(std::string className)
    {
        this->className = className;
    }

    // context 
    std::unordered_map<std::string, VarInfo*> context;



    int indexCounter = 0;
    int labelCounter = 0;

    Type* expectedType = nullptr;
    Type* actualType = nullptr; 
    std::vector<Type*> parametersType;

    std::string generateResult;

    std::pair<std::string, std::string> getLabels(std::string prefix = "")
    {
        if( prefix.size() == 0 ) prefix = "Label";
        return {prefix + "S" + std::to_string(++labelCounter), 
                prefix + "E" + std::to_string(labelCounter)}; 
    }

    /*
    checks the type of the expression (node) against the given type
    */
    Type* typecheckNode(Node *node, Type *type)
    {
        auto oldExpectedType = expectedType;
        expectedType = type;
        visit(node);
        expectedType = oldExpectedType;
        return actualType;
    }

    /*
    Checks the expected type against the given type. If they match
    sets the actual type to the given type.
    */
    void setActualType(Node *node, Type* type)
    {
        if( type != nullptr)
            actualType = type;
    }

    std::unordered_map<std::string, VarInfo *> contextCopy(){
        std::unordered_map<std::string, VarInfo *> old_context(context.begin(), context.end());
        return old_context;
    }    

    std::unordered_map<std::string, VarInfo *> addVariable(std::string ident, Type *type)
    {
        std::cout << "addVariable: ident: " + ident + " type: " + toString(type) << std::endl;
        std::unordered_map<std::string, VarInfo *> old_context(context.begin(), context.end());
        if( context.find(ident) != context.end() ){
            throw std::runtime_error("Variable " + ident + " is already declared");
        }
        context[ident] = new VarInfo(type, indexCounter++);
        return old_context;
    }

    Type *getVariableType(std::string ident)
    {
        if( context.find(ident) == context.end() ){
            throw std::runtime_error("getVariableType: Variable " + ident + " is not declared");
        }
        return context[ident]->type;
    }

    int getVariableIndex(std::string ident)
    {
        if( context.find(ident) == context.end() ){
            throw std::runtime_error("getVariableIndex: Variable " + ident + " is not declared");
        }
        return context[ident]->index;
    }

    void storeToVariable(std::string ident)
    {
        auto type = getVariableType(ident);
        auto index = getVariableIndex(ident);

        if( auto t = dynamic_cast<TypeBoolean*>(type) ) {
            generateResult += "\tistore " + std::to_string(index) + "\n";
        }else if( auto t = dynamic_cast<TypeInteger*>(type) ) {
            generateResult += "\tistore " + std::to_string(index) + "\n";
        }else if( auto t = dynamic_cast<TypeReal*>(type) ) {
            generateResult += "\tfstore " + std::to_string(index) + "\n";
        }else{
            throw std::runtime_error("storeToVariable: " + ident + " having " + toString(type) + " type is not supported");
        }
    }

    void putLogicOperation(std::string operation)
    {
        if( operation == "and" ){
            generateResult += "\tiand\n";
        }else if( operation == "or" ){
            generateResult += "\tior\n";
        }else if( operation == "xor" ){
            generateResult += "\tixor\n";
        }else{
            throw std::runtime_error("logical operation " + operation + " is not supported");
        }   
    }

    void putConversion(Type *fromType, Type *toType)
    {
        std::cout << "putConversion: " + toString(fromType) + " " + toString(toType) << std::endl;
        if( toType == nullptr);
        else if( auto f = dynamic_cast<TypeInteger *>(fromType) ){
            if( auto t = dynamic_cast<TypeInteger *>(toType) ){}
            else if( auto t = dynamic_cast<TypeBoolean *>(toType) ){
                generateResult += makeBinary("ifeq");
            }else if( auto t = dynamic_cast<TypeReal *>(toType) ){
                generateResult += "\ti2f\n";
            }else{
                throw std::runtime_error("putConversion: .1.");
            }
        }else if( auto f = dynamic_cast<TypeBoolean *>(fromType) ){
            if( auto t = dynamic_cast<TypeInteger *>(toType) ){}
            else if( auto t = dynamic_cast<TypeBoolean *>(toType) ){}
            else if( auto t = dynamic_cast<TypeReal *>(toType) ){
                generateResult += "\ti2f\n";
            }else{
                throw std::runtime_error("putConversion: .2.");
            }
        }else if( auto f = dynamic_cast<TypeReal *>(fromType) ){
            if( auto t = dynamic_cast<TypeReal *>(toType) ){}
            else if( auto t = dynamic_cast<TypeInteger *>(toType) ){
                generateResult += "\tf2i\n";
            }else if( auto t = dynamic_cast<TypeBoolean *>(toType) ){
                putConversion(new TypeReal(), new TypeInteger());
                putConversion(new TypeInteger(), new TypeBoolean());
            }else{
                throw std::runtime_error("putConversion: .3.");
            }
        }
    }

    std::string makeBinary(std::string instruction)
    {
        auto pair = getLabels("C");
        auto start = pair.first, end = pair.second;
        std::string temp;
        temp += instruction + " " + start + "\n";
        temp += "\ticonst_1\n";
        temp += "\tgoto " + end + "\n";
        temp += start + ":\n";
        temp += "\ticonst_0\n";
        temp += end + ":\n";
        return temp;
    }

    void putComparison(std::string compareSign)
    {
        generateResult += "\tfcmpg\n";
        if( compareSign == "<" ){
            generateResult += makeBinary("ifge");
        }else if( compareSign == "<=" ){
            generateResult += makeBinary("ifgt");
        }else if( compareSign == ">" ){
            generateResult += makeBinary("ifle");
        }else if( compareSign == ">=" ){
            generateResult += makeBinary("iflt");
        }else if( compareSign == "=" ){
            generateResult += makeBinary("ifne");
        }else if( compareSign == "/=" ){
            generateResult += makeBinary("ifeq");
        }else{
            throw std::runtime_error("Compare sign " + compareSign + " is not supported");
        }
    }   

    void putMultSign(std::string multSign)
    {
        if( multSign == "*" ){
            generateResult += "\tfmul";
        }else if( multSign == "/"){
            generateResult += "\tfdiv";
        }else if( multSign == "% "){
            generateResult += "\tfrem";
        }else{
            throw std::runtime_error("Mult sign " + multSign + " is not supported");
        }
    }

    void putSumSign(std::string sumSign)
    {
        if( sumSign == "+" ){
            generateResult += "\tfadd\n";
        }else if( sumSign == "-" ){
            generateResult += "\tfsub\n";
        }else{
            throw std::runtime_error("Sum sign " + sumSign + " is not supported");
        }
    }

    std::string generate(Node* node){
        visit(node);
        std::string header = "";
        header = ".class public " + className + "\n";
        header += ".super java/lang/Object\n";
        generateResult = header + generateResult;
        return generateResult;
    }

    void visitRoutineDeclaration(Node *node)
    {
        auto oldContext = contextCopy();
        auto oldIndexCounter = indexCounter;
        parametersType.clear();
        indexCounter = 0;
        auto ident = node->children[0]->value;
        currentRoutine = ident;
        if( node->children[1]->type == "parameters" )
            visit(node->children[1]);
        
        Type *type = nullptr;
        if( node->children[1]->type == "type" )
            type = mapType(node->children[1]);
        else if( node->size >= 3 && node->children[2]->type == "type" )
            type = mapType(node->children[2]);

        if( node->children.back()->type != "body" )
            throw std::runtime_error("RoutineDeclaration: the last child must be body");    
        typecheckNode(node->children.back(), type);

        std::string params = "";
        for (auto t: parametersType){
            params += toJasminType(t);
        }

        std::string header = "";

        if( ident == "main"){


            if( !parametersType.empty() ){
                throw std::runtime_error("RoutineDeclaration: main routine must not have parameters");
            }else if( type != nullptr){
                throw std::runtime_error("RoutineDeclaration: main routine must not have return type");
            }else{
                header += "\n.method public static " + ident + "([Ljava/lang/String;)V\n";
            }
        }else{
            header += "\n.method public static " + ident + "(" + params + ")";
            if( type != nullptr)
                header += toJasminType(type);
            else
                header += "V";
            header += "\n";
        }

        header += "\t.limit stack 20\n";
        header += "\t.limit locals " + std::to_string(indexCounter) + "\n";


        generateResult = header + generateResult + ".end method\n";
        
        context = oldContext;
        indexCounter = oldIndexCounter;
        currentRoutine = "";
    }

    void visitForLoop(Node * node)
    {
        auto ident = node->children[0]->value;
        auto index = getVariableIndex(ident);
        auto range = node->children[1];
        bool reversed = range->size == 3;

        if(!reversed)
            typecheckNode(range->children[0], new TypeInteger());
        else
            typecheckNode(range->children[2], new TypeInteger());
        
        storeToVariable(ident);

        auto labels = getLabels("FOR");
        auto start = labels.first;
        auto end = labels.second;
        generateResult += start + ":\n";
        typecheckNode(node->children[0], new TypeInteger());
        if(!reversed){
            typecheckNode(range->children[1], new TypeInteger());
            generateResult += "if_icmpge " + end + "\n"; 
        }else{
            typecheckNode(range->children[1], new TypeInteger());
            generateResult += "if_icmple " + end + "\n";
        }
        typecheckNode(node->children[2], nullptr);

        if( !reversed)
            generateResult += "\tiinc " + std::to_string(index) + " 1\n";
        else
            generateResult += "\tiinc " + std::to_string(index) + " -1\n";
        
        generateResult += "\tgoto " + start + "\n";
        generateResult += end + ":\n";
    }


    void visitParameterDeclaration(Node *node)
    {
        auto ident = node->children[0]->value;
        auto type = mapType(node->children[1]);
        addVariable(ident, type);
    }

    void visitVariableDeclaration(Node* node)
    {
        assert(node->size == 2 || node->size == 3 && "VariableDeclaration must have 2-3 children");
        assert(node->children[0]->type == "identifier" && "VariableDeclaration: 1st child must be identifier");
        assert(node->children[1]->type == "type" && "2nd child must be type");
        auto ident = node->children[0]->value;
        auto type = mapType(node->children[1]);

        std::cout << "visitVariableDeclaration: " + ident + ": " + toString(type) << std::endl;
        addVariable(ident, type);
        if( node->size == 3 ){
            assert(node->children[2]->type == "expression" && "3rd child must be expression");
            typecheckNode(node->children[2], type);
            storeToVariable(ident);
        }
    }

    void visitVariableDeclarationAuto(Node *node)
    {
        std::cout << "VariableDeclarationAuto expectedType: " + toString(expectedType) << std::endl;
        assert(node->size == 2 && "VariableDeclarationAuto: must have 2 children");
        assert(node->children[0]->type == "identifier" && "VariableDeclarationAuto: 1st child must be identifier");
        assert(node->children[1]->type == "expression" && "VariableDeclarationAuto: 2nd child must be expression");
        auto ident = node->children[0]->value;
        auto expressionType = typecheckNode(node->children[1], nullptr);
        addVariable(ident, expressionType);
        storeToVariable(ident);
    }

    void visitExpression(Node *node)
    {
        assert(node->size == 1 || node->size == 3 && "Expression must have 1 or 3 children");
        if( node->size == 1 ){
            assert(node->children[0]->type == "relation" && "Expression has 1 child and it must be relation");
            visit(node->children[0]);
        }else{
            assert(node->children[0]->type == "expression" && "Expression: 1st child must be expression");
            assert(node->children[1]->type == "logic_operation" && "Expression: 2nd child must be logic operation");
            assert(node->children[2]->type == "relation" && "Expression: 3rd child must be relation");
            typecheckNode(node->children[0], new TypeBoolean());
            typecheckNode(node->children[2], new TypeBoolean());
            putLogicOperation(node->children[1]->value);
            putConversion(new TypeBoolean(), expectedType);

        }
    }

    void visitRelation(Node *node)
    {
        std::cout << "visitRelation expectedType: " + toString(expectedType) << std::endl;
        assert(node->size == 1 || node->size == 3 && "Relation: must have 1 or 3 children");
        if( node->size == 1 ){
            assert(node->children[0]->type == "simple" && "Relation has 1 child and it must be simple");
            visit(node->children[0]);
        }else{
            assert(node->children[0]->type == "relation" && "Relation: 1st child must be relation");
            assert(node->children[1]->type == "compare_sign" && "Relation: 2nd child must be compare sign");
            assert(node->children[2]->type == "simple" && "Relation: 3rd child must be simple");
            typecheckNode(node->children[0], new TypeReal());
            typecheckNode(node->children[2], new TypeReal());
            putComparison(node->children[1]->value);
            putConversion(new TypeInteger(), expectedType);
        }
    }

    void visitSimple(Node *node)
    {
        assert(node->size == 1 || node->size == 3 && "Simple: must have 1 or 3 children");
        if( node->size == 1 ){
            assert(node->children[0]->type == "factor" && "Simple has 1 child and it must be factor");
            visit(node->children[0]);
        }else{
            assert(node->children[0]->type == "simple" && "Simple: 1st child must be simple");
            assert(node->children[1]->type == "mult_sign" && "Simple: 2nd child must be mult sign");
            assert(node->children[2]->type == "factor" && "Simple: 3rd child must be factor");
            typecheckNode(node->children[0], new TypeReal());
            typecheckNode(node->children[2], new TypeReal());
            putMultSign(node->children[1]->value);
            putConversion(new TypeReal(), expectedType);
        }
    }



    void visitFactor(Node *node)
    {
        assert(node->size == 1 || node->size == 3 && "Factor: must have 1 or 3 children");
        if( node->size == 1 ){
            assert(node->children[0]->type == "summand" && "Factor has 1 child and it must be summand");
            visit(node->children[0]);
        }else{
            assert(node->children[0]->type == "factor" && "Factor: 1st child must be factor");
            assert(node->children[1]->type == "sum_sign" && "Factor: 2nd child must be sum sign");
            assert(node->children[2]->type == "summand" && "Factor: 3rd child must be summand");
            typecheckNode(node->children[0], new TypeReal());
            typecheckNode(node->children[2], new TypeReal());
            putSumSign(node->children[1]->value);
            putConversion(new TypeReal(), expectedType);
        }
    }

    void visitBoolean(Node *node)
    {
        assert(node->size == 0 && "Boolean must have 0 children");
        if( node->value == "true" ){
            generateResult += "\ticonst_1\n";
        }else if( node->value == "false" ){
            generateResult += "\ticonst_0\n";
        }else{
            throw std::runtime_error("Boolean value " + node->value + " is not supported");
        }
        setActualType(node, new TypeBoolean());
        setActualType(node, expectedType);
        putConversion(new TypeBoolean(), expectedType);
    }

    void visitReal(Node *node)
    {
        assert(node->size == 0 && "Real must have 0 children");
        generateResult += "\tfconst " + node->value + "\n";
        setActualType(node, new TypeReal());
        setActualType(node, expectedType);
        putConversion(new TypeReal(), expectedType);
    }

    void visitInteger(Node *node)
    {
        assert(node->size == 0 && "Integer must have 0 children");
        generateResult += "\tldc " + node->value + "\n";
        setActualType(node, new TypeInteger());
        setActualType(node, expectedType);
        putConversion(new TypeInteger(), expectedType);
    }

    void visitModifiablePrimary(Node *node)
    {
        std::cout << "ModifiablePrimary expected_type: " + toString(expectedType) << std::endl;
        assert(node->size == 1 && "ModifiablePrimary mush have 1 children");
        assert(node->children[0]->type == "identifier" && "ModifiablePrimary: 1st child must be identifier");
        visit(node->children[0]);
    }

    void visitIdentifier(Node *node)
    {
        auto ident = node->value;
        auto type = getVariableType(ident);
        auto index = getVariableIndex(ident);
        if( auto t = dynamic_cast<TypeBoolean*>(type) ){
            generateResult += "\tiload " + std::to_string(index) + "\n";
        }else if( auto t = dynamic_cast<TypeInteger*>(type) ){
            generateResult += "\tiload " + std::to_string(index) + "\n";
        }else if( auto t = dynamic_cast<TypeReal*>(type) ){
            generateResult += "\tfload " + std::to_string(index) + "\n";
        }
        setActualType(node, type);
        setActualType(node, expectedType);
        putConversion(type, expectedType);
    }

    void visitReturn(Node *node)
    {
        if(node->size == 0){
            generateResult += "\treturn\n";
        }
        else{
            if( currentRoutine == "main" ){
                generateResult += "\tgetstatic java/lang/System.out Ljava/io/PrintStream;\n";
                typecheckNode(node->children[0], nullptr);
                generateResult += "\tinvokevirtual java/io/PrintStream.println(I)V\n";
                generateResult += "\treturn\n";
            }else{
                auto type = typecheckNode(node->children[0], nullptr);
                if( type == nullptr ){

                }else if( auto t = dynamic_cast<TypeBoolean *>(type) ){
                    generateResult += "\tireturn\n";
                }else if( auto t = dynamic_cast<TypeInteger *>(type) ){
                    generateResult += "\tireturn\n";
                }else if( auto t = dynamic_cast<TypeReal *>(type) ){
                    generateResult += "\tfreturn\n";
                }else{
                    throw std::runtime_error("visitReturn: " + toString(type) + " is not implemented");
                }
            }
        }
    }


    void visitAssignment(Node *node)
    {
        auto ident = node->children[0]->children[0]->value;
        auto type = getVariableType(ident);
        typecheckNode(node->children[1], type);
        storeToVariable(ident);
    }

    void visitIfStatement(Node *node)
    {
        auto labels = getLabels("IF");
        auto elsebody = labels.first;
        auto ifexit = labels.second;

        typecheckNode(node->children[0], new TypeBoolean());

        generateResult += "\tifeq" + elsebody + "\n";
        typecheckNode(node->children[1], nullptr);
        generateResult += "\tgoto " + ifexit + "\n";
        generateResult += elsebody + ":\n";
        if( node->size == 3 ){
            typecheckNode(node->children[2], nullptr);
        }
        generateResult += ifexit + ":\n"; 
    }

};
