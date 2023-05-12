#include <assert.h>
#include <unordered_map>
#include <stdexcept>
#include "../common/visitor.hpp"
#include <iostream>

class Analyzer: public Visitor {
public:
    // context - variables types
    std::unordered_map<std::string, std::string> types;

    std::string expectedType;
    std::string actualType;

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
        if(!expectedType.empty() && typecheck(expectedType, type)){
            throw std::runtime_error("Expected " + expectedType + " type but got " + type + " type");
        }
        actualType = type;
    }

    bool typecheck(std::string type1, std::string type2)
    {
        if (type1 == "boolean" && type2 == "real")
        {
            return false;
        }
        if (type2 == "boolean" && type1 == "real")
        {
            return false;
        }

        return true;
    }

    void addVariable(std::string ident, std::string type)
    {
        if( types.find(ident) != types.end() ){
            throw std::runtime_error("Variable " + ident + " is already declared");
        }
        types[ident] = type;
    }

    std::string getVariableType(std::string ident)
    {
        if( types.find(ident) == types.end() ){
            throw std::runtime_error("Variable " + ident + " is not declared");
        }
        return types[ident];
    }
    
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> castingRules = {
        {"boolean", {{"integer", "integer"}}},
        {"integer", {{"real", "real"}, {"boolean", "integer"}}},
        {"real", {{"integer", "real"}}}
    };

    std::string upCast(const std::string& typeLhs, const std::string& typeRhs) {
        if (!typecheck(typeLhs, typeRhs)) {
            throw std::runtime_error("Invalid use of getCastable(" + typeLhs + ", " + typeRhs + ")");
        }

        if (typeLhs == typeRhs) {
            return typeLhs;  // No casting needed, return the same type
        } else {
            return castingRules[typeLhs][typeRhs];  // Casting rule found, return the casted type
        } 
    }

    void visitVariableDeclaration(Node* node)
    {
        auto ident = node->children[0]->value;
        auto type = node->children[1]->children[0]->value;
        if (node->size == 3) {
            typecheckNode(node->children[2], type);
        }

        setActualType(node, type);
        addVariable(ident, type);
    }
    
    void visitVariableDeclarationAuto(Node* node)
    {
        auto ident = node->children[0]->value;
        auto type = typecheckNode(node->children[1], "");

        setActualType(node, type);
        addVariable(ident, type);
    }

    void visitExpression(Node* node) 
    {
        if (node->size == 3) {
            typecheckNode(node->children[0], "boolean");
            typecheckNode(node->children[2], "boolean");
        
            setActualType(node, "boolean");
        } else if (node->size == 1) {
            typecheckNode(node->children[0], expectedType);
        } else {
            throw std::runtime_error("Something unexpected in visitExpression");
        }
    }

    void visitRelation(Node* node) 
    {
        if (node->size == 3) {
            auto typeLhs = typecheckNode(node->children[0], "");
            auto typeRhs = typecheckNode(node->children[2], "");

            if (!typecheck(typeLhs, typeRhs)) {
                throw std::runtime_error("Comparison of " + typeLhs + " and " + typeRhs + " is not supported");
            }

            setActualType(node, "boolean");
        } else if (node->size == 1) {
            typecheckNode(node->children[0], expectedType);
        } else {
            throw std::runtime_error("Something unexpected in visitRelation");
        }
    }

    void visitSimple(Node* node) 
    {
        if (node->size == 3) {
            auto typeLhs = typecheckNode(node->children[0], "");
            auto typeRhs = typecheckNode(node->children[2], "");

            if (!typecheck(typeLhs, typeRhs)) {
                throw std::runtime_error("\"" + node->children[1]->value + "\" operation of " + typeLhs + " and " + typeRhs + " is not supported");
            }

            setActualType(node, upCast(typeLhs, typeRhs));
        } else if (node->size == 1) {
            typecheckNode(node->children[0], expectedType);
        } else {
            throw std::runtime_error("Something unexpected in visitRelation");
        }
    }

    void visitFactor(Node* node)
    {
        if (node->type == "factor") {
            if (node->size == 3) {
                auto typeLhs = typecheckNode(node->children[0], "");
                auto typeRhs = typecheckNode(node->children[2], "");

                if (!typecheck(typeLhs, typeRhs)) {
                    throw std::runtime_error("\"" + node->children[1]->value + "\" operation of " + typeLhs + " and " + typeRhs + " is not supported");
                }

                setActualType(node, upCast(typeLhs, typeRhs));
            } else if (node->size == 1) {
                typecheckNode(node->children[0], expectedType);
            }
        } else if (node->type == "unary_factor") {
                auto type = typecheckNode(node->children[1], "");
                setActualType(node, upCast(type, "integer"));
        } else if (node->type == "not_factor") {
                typecheckNode(node->children[1], "");
                setActualType(node, "boolean");
        } else {
            throw std::runtime_error("Something unexpected in visitFactor");
        }
    }
    
};