#ifndef ANALYZER_H
#define ANALYZER_H

#include "../common/visitor.hpp"

class Analyzer : public Visitor {
public:
    // context - variables types
    std::unordered_map<std::string, std::string> types;

    std::string expectedType;
    std::string actualType;

    /*
    checks the type of the expression (node) against the given type
    */
    std::string typecheckNode(Node* node, std::string type);

    /*
    Checks the expected type against the given type. If they match
    sets the actual type to the given type.
    */
    void setActualType(Node* node, std::string type);

    bool typecheck(std::string type1, std::string type2);

    void addVariable(std::string ident, std::string type);

    std::string getVariableType(std::string ident);

    std::string upCast(const std::string& typeLhs, const std::string& typeRhs);

    void visitVariableDeclaration(Node* node);

    void visitVariableDeclarationAuto(Node* node);

    void visitExpression(Node* node);

    void visitRelation(Node* node);

    void visitSimple(Node* node);

    void visitFactor(Node* node);

    void visitUnaryFactor(Node* node);

    void visitNotFactor(Node* node);

    void visitSummand(Node* node);

    void visitBoolean(Node* node);

    void visitInteger(Node* node);

    void visitReal(Node* node);

    void visitModifiablePrimary(Node* node);

    void analyze(Node* node);
};

#endif /* ANALYZER_H */