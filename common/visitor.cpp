#include "visitor.hpp"
#include <vector>
#include <stdexcept>
#include <string>

// /*
// This function strictly checks a list of nodes against a list of types to ensure
// that each of the node has their own corresponding types from the  type list.
// */
// bool checkNodesStrict(std::vector<Node*> nodes, std::vector<std::string>types)
// {
//     if( nodes.size() != types.size() )
//         return false;
//     for( int i = 0; i < nodes.size(); i ++ ){
//         if( nodes[i]->type != types[i] ){
//             return false;
//         }
//     }
//     return true;
// }

// /*
// Similary to checkNodesStrict but not strict
// */
// bool checkNodesLoose(std::vector<Node*> nodes, std::vector<std::string>types)
// {
//     for( int i = 0; i < nodes.size(); i ++ ){
//         bool found = false;
//         for( int j = 0; j < types.size(); j ++ ){
//             if( nodes[i]->type == types[j] ){
//                 found = true;
//             }
//         }
//         if( !found )
//             return false;
//     }
//     return true;
// }



/*
This function simply calls visit function for each of the node's children.
*/
void Visitor::invokeChildren(Node *node)
{
    for( auto child: node->children ){
        this->visit(child);
    }
}


/*
This function is kind of a controller. It basically checks the type 
of a node and passes that node to a corresponding visitor function.
*/
void Visitor::visit(Node *node)
{
    if( node == nullptr){
        throw std::runtime_error("Node is nullptr");
    }
    else if( node->type == "program" ){
        this->visitProgram(node);
    }
    else if( node->type == "simple_declaration" ){
        this->visitSimpleDeclaration(node);
    }
    else if( node->type == "variable_declaration" ){
        this->visitVariableDeclaration(node);
    }
    else if( node->type == "variable_declaration_auto" ){
        this->visitVariableDeclarationAuto(node);
    }
    else if( node->type == "type_declaration" ){
        this->visitTypeDeclaration(node);
    }
    else if( node->type == "routine_declaration" ){
        this->visitRoutineDeclaration(node);
    }
    else if( node->type == "parameters" ){
        this->visitParameters(node);
    }
    else if( node->type == "parameter_declaration" ){
        this->visitParameterDeclaration(node);
    }
    else if( node->type == "type" ){
        this->visitType(node);
    }
    else if( node->type == "primitive_type" ){
        this->visitPrimitiveType(node);
    }
    else if( node->type == "record_type" ){
        this->visitRecordType(node);
    }
    else if( node->type == "array_type" ){
        this->visitArrayType(node);
    }
    else if( node->type == "body" ){
        this->visitBody(node);
    }
    else if( node->type == "statement" ){
        this->visitStatement(node);
    }
    else if( node->type == "return" ){
        this->visitReturn(node);
    }
    else if( node->type == "assignment" ){
        this->visitAssignment(node);
    }
    else if( node->type == "routine_call" ){
        this->visitRoutineCall(node);
    }
    else if( node->type == "arguments" ){
        this->visitArguments(node);
    }
    else if( node->type == "while_loop" ){
        this->visitWhileLoop(node);
    }
    else if( node->type == "for_loop" ){
        this->visitForLoop(node);
    }
    else if( node->type == "range" ){
        this->visitRange(node);
    }
    else if( node->type == "reverse" ){
        this->visitRange(node);
    }
    else if( node->type == "if_statements" ){
        this->visitIfStatement(node);
    }
    else if( node->type == "expression" ){
        this->visitExpression(node);
    }
    else if( node->type == "logic_operation" ){
        this->visitLogicOperation(node);
    }
    else if( node->type == "relation" ){
        this->visitRelation(node);
    }
    else if( node->type == "compare_sign" ){
        this->visitCompareSign(node);
    }
    else if( node->type == "simple" ){
        this->visitSimple(node);
    }
    else if( node->type == "mult_sign" ){
        this->visitMultSign(node);
    }
    else if( node->type == "factor" ){
        this->visitFactor(node);
    }
    else if( node->type == "unary_factor" ){
        this->visitUnaryFactor(node);
    }
    else if( node->type == "sum_sign" ){
        this->visitSumSign(node);
    }
    else if( node->type == "summand" ){
        this->visitSummand(node);
    }
    else if( node->type == "boolean" ){
        this->visitBoolean(node);
    }
    else if( node->type == "integer" ){
        this->visitInteger(node);
    }
    else if( node->type == "real" ){
        this->visitReal(node);
    }
    else if( node->type == "modifiable_primary" ){
        this->visitModifiablePrimary(node);
    }
    else if( node->type == "modifiable_primary_array" ){
        this->visitModifiablePrimaryArray(node);
    }
    else if( node->type == "modifiable_primary_field" ){
        this->visitModifiablePrimaryField(node);
    }
    else if( node->type == "identifier" ){
        this->visitIdentifier(node);
    }
    else{
        throw std::runtime_error(node->type + " is not implemented");
    }
}


/*
Here starts visitor functions for their corresponding node types.
*/


void Visitor::visitProgram(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitSimpleDeclaration(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitVariableDeclaration(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitVariableDeclarationAuto(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitTypeDeclaration(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitRoutineDeclaration(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitParameters(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitParameterDeclaration(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitType(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitPrimitiveType(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitRecordType(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitArrayType(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitBody(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitStatement(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitReturn(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitAssignment(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitRoutineCall(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitArguments(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitWhileLoop(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitForLoop(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitRange(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitIfStatement(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitExpression(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitLogicOperation(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitRelation(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitCompareSign(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitSimple(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitMultSign(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitFactor(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitUnaryFactor(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitSumSign(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitSummand(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitBoolean(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitInteger(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitReal(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitModifiablePrimary(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitModifiablePrimaryArray(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitModifiablePrimaryField(Node *node)
{
    invokeChildren(node);
}


void Visitor::visitIdentifier(Node *node)
{
    invokeChildren(node);
}

