#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "node.hpp"
#include <assert.h>
#include <unordered_map>
#include <stdexcept>

class Visitor{
public:
    virtual void invokeChildren(Node *p);
    virtual void visit(Node *p);
    virtual void visitProgram(Node *p);
    virtual void visitSimpleDeclaration(Node *p);
    virtual void visitVariableDeclaration(Node *p);
    virtual void visitVariableDeclarationAuto(Node *p);
    virtual void visitTypeDeclaration(Node *p);
    virtual void visitRoutineDeclaration(Node *p);
    virtual void visitParameters(Node *p);
    virtual void visitParameterDeclaration(Node *p);
    virtual void visitType(Node *p);
    virtual void visitPrimitiveType(Node *p);
    virtual void visitRecordType(Node *p);
    virtual void visitArrayType(Node *p);
    virtual void visitBody(Node *p);
    virtual void visitStatement(Node *p);
    virtual void visitReturn(Node *p);
    virtual void visitAssignment(Node *p);
    virtual void visitRoutineCall(Node *p);
    virtual void visitArguments(Node *p);
    virtual void visitWhileLoop(Node *p);
    virtual void visitForLoop(Node *p);
    virtual void visitRange(Node *p);
    virtual void visitIfStatement(Node *p);
    virtual void visitExpression(Node *p);
    virtual void visitLogicOperation(Node *p);
    virtual void visitRelation(Node *p);
    virtual void visitCompareSign(Node *p);
    virtual void visitSimple(Node *p);
    virtual void visitMultSign(Node *p);
    virtual void visitFactor(Node *p);
    virtual void visitUnaryFactor(Node *p);
    virtual void visitSumSign(Node *p);
    virtual void visitSummand(Node *p);
    virtual void visitBoolean(Node *p);
    virtual void visitInteger(Node *p);
    virtual void visitReal(Node *p);
    virtual void visitModifiablePrimary(Node *p);
    virtual void visitModifiablePrimaryArray(Node *p);
    virtual void visitModifiablePrimaryField(Node *p);
    virtual void visitIdentifier(Node *p);
};




#endif // VISITOR_HPP