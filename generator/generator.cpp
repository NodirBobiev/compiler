#include <assert.h>
#include <unordered_map>
#include <stdexcept>
#include "../common/visitor.hpp"
#include <iostream>

class Generator: public Visitor{
public:
    // context - variables types
    std::unordered_map<std::string, std::string> types;

    // context - variables indexes
    std::unordered_map<std::string, int> indexes;

    int indexCounter = 0;
    int labelCounter = 0;

    std::string expectedType;
    std::string actualType;

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
    std::string typecheckNode(Node *node, std::string type)
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
    void setActualType(Node *node, std::string type)
    {
        if(expectedType.size() > 0 && type.size() > 0 && expectedType != type){
            throw std::runtime_error("Expected " + expectedType + " type but got " + type + " type");
        }
        actualType = type;
    }

    void addVariable(std::string ident, std::string type)
    {
        if( types.find(ident) != types.end() ){
            throw std::runtime_error("Variable " + ident + " is already declared");
        }
        types[ident] = type;
        indexes[ident] = ++ indexCounter;
    }

    std::string getVariableType(std::string ident)
    {
        if( types.find(ident) == types.end() ){
            throw std::runtime_error("Variable " + ident + " is not declared");
        }
        return types[ident];
    }

    int getVariableIndex(std::string ident)
    {
        if( indexes.find(ident) == indexes.end() ){
            throw std::runtime_error("Variable " + ident + " is not declared");
        }
        return indexes[ident];
    }

    void storeToVariable(std::string ident)
    {
        auto type = getVariableType(ident);
        if( type == "integer" || type == "boolean" ){
            generateResult += "\tistore " + std::to_string(getVariableIndex(ident)) + "\n";
        }else if( type == "real" ){
            generateResult += "\tfstore " + std::to_string(getVariableIndex(ident)) + "\n";
        }else{
            throw std::runtime_error("Type of " + ident + " was not found");
        }
    }

    void putLogicOperation(std::string operation)
    {
        if( operation == "and" ){
            generateResult += "\tiand";
        }else if( operation == "or" ){
            generateResult += "\tior";
        }else if( operation == "xor" ){
            generateResult += "\tixor";
        }else{
            throw std::runtime_error("logical operation " + operation + " is not supported");
        }
        
    }

    void putConversion(std::string fromType, std::string toType)
    {
        if( toType == "" ){
            return;
        }else if( fromType == toType || 
            (fromType == "integer" && toType == "boolean" ) || 
            (fromType == "boolean" && toType == "integer") ){
            return;
        }else if( (fromType == "integer" || fromType == "boolean") && toType == "real" ){
            generateResult += "\ti2f\n";
        }else if( fromType == "real" and (toType == "integer" || toType == "boolean") ){
            generateResult += "\tf2i\n";
        }else{
            throw std::runtime_error("Conversion from " + fromType + " to " + toType + " is not supported");
        }
    }

    void putComparison(std::string compareSign)
    {
        generateResult += "\tfcmpg\n";
        auto pair = getLabels("C");
        auto start = pair.first, end = pair.second;
        std::string temp;
        temp += start + "\n";
        temp += "\ticonst_1\n";
        temp += "\tgoto " + end + "\n";
        temp += start + ":\n";
        temp += "\ticonst_0\n";
        temp += end + ":\n";
        if( compareSign == "<" ){
            temp = "ifge " + temp;
        }else if( compareSign == "<=" ){
            temp = "ifgt " + temp;
        }else if( compareSign == ">" ){
            temp = "ifle " + temp;
        }else if( compareSign == ">=" ){
            temp = "iflt " + temp;
        }else if( compareSign == "=" ){
            temp = "ifne " + temp;
        }else if( compareSign == "/=" ){
            temp = "ifeq " + temp;
        }else{
            throw std::runtime_error("Compare sign " + compareSign + " is not supported");
        }
        generateResult += temp;
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
            generateResult += "\tfadd";
        }else if( sumSign == "-" ){
            generateResult += "\tfsub";
        }else{
            throw std::runtime_error("Sum sign " + sumSign + " is not supported");
        }
    }

    std::string generate(Node* node){
        visit(node);
        return generateResult;
    }

    void visitVariableDeclaration(Node* node)
    {
        assert(node->size == 2 || node->size == 3 && "VariableDeclaration must have 2-3 children");
        assert(node->children[0]->type == "identifier" && "1st child must be identifier");
        assert(node->children[1]->type == "type" && "2nd child must be type");
        auto ident = node->children[0]->value;
        auto type = node->children[1]->children[0]->value;

        std::cout << "visitVariableDeclaration: " + ident + ": " + type << std::endl;
        addVariable(ident, type);
        if( node->size == 3 ){
            assert(node->children[2]->type == "expression" && "3rd child must be expression");
            typecheckNode(node->children[2], type);
            storeToVariable(ident);
        }
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
            typecheckNode(node->children[0], "boolean");
            typecheckNode(node->children[2], "boolean");
            putLogicOperation(node->children[1]->value);
            putConversion("boolean", expectedType);
        }
    }

    void visitRelation(Node *node)
    {
        std::cout << "visitRelation expectedType: " + expectedType << std::endl;
        assert(node->size == 1 || node->size == 3 && "Relation: must have 1 or 3 children");
        if( node->size == 1 ){
            assert(node->children[0]->type == "simple" && "Relation has 1 child and it must be simple");
            visit(node->children[0]);
        }else{
            assert(node->children[0]->type == "relation" && "Relation: 1st child must be relation");
            assert(node->children[1]->type == "compare_sign" && "Relation: 2nd child must be compare sign");
            assert(node->children[2]->type == "simple" && "Relation: 3rd child must be simple");
            typecheckNode(node->children[0], "real");
            typecheckNode(node->children[2], "real");
            putComparison(node->children[1]->value);
            putConversion("integer", expectedType);
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
            typecheckNode(node->children[0], "real");
            typecheckNode(node->children[2], "real");
            putMultSign(node->children[1]->value);
            putConversion("real", expectedType);
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
            typecheckNode(node->children[0], "real");
            typecheckNode(node->children[2], "real");
            putSumSign(node->children[1]->value);
            putConversion("real", expectedType);
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
        putConversion("boolean", expectedType);
    }

    void visitReal(Node *node)
    {
        assert(node->size == 0 && "Real must have 0 children");
        generateResult += "\tfconst " + node->value + "\n";
        putConversion("real", expectedType);
    }

    void visitInteger(Node *node)
    {
        assert(node->size == 0 && "Integer must have 0 children");
        generateResult += "\ticonst " + node->value + "\n";
        putConversion("integer", expectedType);
    }


};
