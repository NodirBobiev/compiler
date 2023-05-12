#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include "../common/visitor.hpp"

class Analyzer : public Visitor {
public:
    // context - variables types
    std::unordered_map<std::string, std::string> types;
    std::unordered_map<std::string, std::string> synonyms;

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

    // void visit(Node* node);
    // void visitProgram(Node* node);
    // void visitSimpleDeclaration(Node* node);
    void visitVariableDeclaration(Node* node);
    void visitVariableDeclarationAuto(Node* node);
    // void visitTypeDeclaration(Node* node);
    // void visitRoutineDeclaration(Node* node);
    // void visitParameters(Node* node);
    // void visitParameterDeclaration(Node* node);
    // void visitType(Node* node);
    // void visitPrimitiveType(Node* node);
    // void visitRecordType(Node* node);
    // void visitArrayType(Node* node);
    // void visitBody(Node* node);
    // void visitStatement(Node* node);
    // void visitReturn(Node* node);
    // void visitAssignment(Node* node);
    // void visitRoutineCall(Node* node);
    // void visitArguments(Node* node);
    void visitWhileLoop(Node* node);
    void visitForLoop(Node* node);
    void visitRange(Node* node);
    void visitIfStatement(Node* node);
    void visitExpression(Node* node);
    // void visitLogicOperation(Node* node);
    void visitRelation(Node* node);
    // void visitCompareSign(Node* node);
    void visitSimple(Node* node);
    // void visitMultSign(Node* node);
    void visitFactor(Node* node);
    void visitUnaryFactor(Node* node);
    void visitNotFactor(Node* node);
    // void visitSumSign(Node* node);
    void visitSummand(Node* node);
    void visitBoolean(Node* node);
    void visitInteger(Node* node);
    void visitReal(Node* node);
    void visitModifiablePrimary(Node* node);
    // void visitModifiablePrimaryArray(Node* node);
    // void visitModifiablePrimaryField(Node* node);
    // void visitIdentifier(Node* node);
    void analyze(Node* node);
};

#endif /* ANALYZER_HPP */