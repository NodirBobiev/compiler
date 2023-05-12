#include "analyzer.hpp"
#include <iostream>

void Analyzer::analyze(Node* node)
{
    try {
        visit(node);
    } catch (const std::runtime_error& e) {
        std::cout << "Semantical analyzer found mistake: " << e.what() << std::endl;
        exit(1); 
    }

    std::cout << "\nSemantical analyzis finished without error" << std::endl;
}

std::string Analyzer::typecheckNode(Node *node, std::string type)
{
    auto oldExpectedType = expectedType;
    expectedType = type;
    visit(node);
    expectedType = oldExpectedType;
    return actualType;
}

void Analyzer::setActualType(Node *node, std::string type)
{
    if(!expectedType.empty() && !typecheck(expectedType, type)){
        throw std::runtime_error("Expected " + expectedType + " type but got " + type + " type");
    }
    actualType = type;
}

bool Analyzer::typecheck(std::string type1, std::string type2)
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

void Analyzer::addVariable(std::string ident, std::string type)
{
    if( types.find(ident) != types.end() ){
        throw std::runtime_error("Variable " + ident + " is already declared");
    }
    types[ident] = type;
}

std::string Analyzer::getVariableType(std::string ident)
{
    if( types.find(ident) == types.end() ){
        throw std::runtime_error("Variable " + ident + " is not declared");
    }
    return types[ident];
}

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> castingRules = 
{
    {"boolean", {{"integer", "integer"}}},
    {"integer", {{"real", "real"}, {"boolean", "integer"}}},
    {"real", {{"integer", "real"}}}
};

std::string Analyzer::upCast(const std::string& typeLhs, const std::string& typeRhs) 
{
    if (!typecheck(typeLhs, typeRhs)) {
        throw std::runtime_error("Invalid use of getCastable(" + typeLhs + ", " + typeRhs + ")");
    }

    if (typeLhs == typeRhs) {
        return typeLhs;  // No casting needed, return the same type
    } else {
        return castingRules[typeLhs][typeRhs];  // Casting rule found, return the casted type
    } 
}

void Analyzer::visitVariableDeclaration(Node* node)
{
    auto ident = node->children[0]->value;
    auto type = node->children[1]->children[0]->value;
    if (node->size == 3) {
        typecheckNode(node->children[2], type);
    }

    setActualType(node, type);
    addVariable(ident, type);
}

void Analyzer::visitVariableDeclarationAuto(Node* node)
{
    auto ident = node->children[0]->value;
    auto type = typecheckNode(node->children[1], "");

    setActualType(node, type);
    addVariable(ident, type);
}

void Analyzer::visitWhileLoop(Node* node)
{
    typecheckNode(node->children[1], "");
    typecheckNode(node->children[0], "boolean");
}

void Analyzer::visitForLoop(Node* node)
{
    auto iNode = node->children[0];
    auto iType = getVariableType(iNode->value);
    if (iType != "integer") {
        throw std::runtime_error("In for loop identifier " + iNode->value + " is " + iType + " insetead of integer");
    }

    typecheckNode(node->children[1], "");
    typecheckNode(node->children[2], "");
}

void Analyzer::visitRange(Node* node)
{
    typecheckNode(node->children[0], "integer");
    typecheckNode(node->children[1], "integer");
}

void Analyzer::visitIfStatement(Node* node)
{
    typecheckNode(node->children[0], "boolean");
    typecheckNode(node->children[1], "");
    if (node->size == 3) {
        typecheckNode(node->children[2], "");
    }
}

void Analyzer::visitExpression(Node* node) 
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

void Analyzer::visitRelation(Node* node) 
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

void Analyzer::visitSimple(Node* node) 
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

void Analyzer::visitFactor(Node* node)
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
    }
}

void Analyzer::visitUnaryFactor(Node* node)
{
    auto type = typecheckNode(node->children[1], "");
    setActualType(node, upCast(type, "integer"));
}

void Analyzer::visitNotFactor(Node* node)
{
    typecheckNode(node->children[1], "");
    setActualType(node, "boolean");
}

void Analyzer::visitSummand(Node* node)
{
    typecheckNode(node->children[0], expectedType);
}

void Analyzer::visitBoolean(Node* node) 
{
    setActualType(node, "boolean");
}

void Analyzer::visitInteger(Node* node) 
{
    setActualType(node, "integer");
}

void Analyzer::visitReal(Node* node) 
{
    setActualType(node, "real");
}

void Analyzer::visitModifiablePrimary(Node* node)
{
    if (node->children[0]->type == "identifier") {
        auto ident = node->children[0]->value;
        auto type = getVariableType(ident);

        setActualType(node, type);
    } else {
        typecheckNode(node->children[0], expectedType);
    }
}