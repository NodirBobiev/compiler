#include <assert.h>
#include <unordered_map>
#include "../common/visitor.hpp"

class Generator: public Visitor{
public:
    // context - variables types
    std::unordered_map<std::string, std::string> types;

    // context - variables indexes
    std::unordered_map<std::string, int> indexes;

    int indexCounter = 0;

    std::string expectedType;
    std::string actualType;

    std::string generateResult;

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
        if( types.find(ident) != types.end() ){
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
        if( type == "integer" || type == "boolean" )
            generateResult += "\tistore " + getVariableIndex(ident);
        else if( type == "real" )
            generateResult += "\tfstore " + getVariableIndex(ident);
    }

    void generate(Node* node){
        visit(node);
    }

    void visitVariableDeclaration(Node* node)
    {
        assert(node->size == 2 || node->size == 3 && "VariableDeclaration must have 2-3 children");
        assert(node->children[0]->type == "identifier" && "1st child must be identifier");
        assert(node->children[1]->type == "type" && "2nd child must be type");
        auto ident = node->children[0]->value;
        auto type = node->children[1]->value;
        addVariable(ident, type);
        if( node->size == 3 ){
            assert(node->children[2]->type == "expression" && "3rd child must be expression");
            typecheckNode(node->children[2], type);
            storeToVariable(ident);
        }
    }

    void visitExpression(Node *node)
    {

    }

};
