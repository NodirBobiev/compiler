#include <iostream>
#include <stdarg.h>
#include "node.hpp"


Node::Node(const std::string &type, const std::string &value)
{
    this->type = type;
    this->value = value;
}

Node::Node(const std::string &type)
{
  this->type = type;
}

Node::~Node()
{
    for (int i = 0; i < this->size; i++) 
        delete(this->children[i]);
}

Node* Node::add(Node *node)
{
    if (node == nullptr)
        return this;
    size ++;
    children.push_back(node);
    return this;
}

std::string Node::print(int depth)
{
    std::string result = rep("  ", depth) + "<" + type;
    
    if (value.size() > 0)
        result += " value='" + value + "'";
    
    if (size > 0)
        result += " size=" + std::to_string(size);
    
    if (depth > 0)
        result += " depth=" + std::to_string(depth);

    result += ">\n";

    for(int i = 0; i < size; i ++)
        result += children[i]->print(depth + 1);
    
    return result;
}


std::string rep(std::string str, int cnt)
{
    std::string result = "";
    for(int i = 0; i < cnt; i ++)result += str;
    return result;
}

Node* mNode(std::string type, std::string value)
{
    return new Node(type=type, value=value);
}

Node* mNode(std::string type)
{
    return new Node(type=type);
}

Node* mpNode(std::string type, std::string value, int argc, ...)
{
    va_list valist;
    auto node = new Node(type=type, value=value);

    va_start(valist, argc);
    for(int i = 0; i < argc; i ++ )
        node->add(va_arg(valist, Node*));
    
    va_end(valist);
    return node;
}

Node* mpNode(std::string type, int argc, ...)
{
    va_list valist;
    auto node = new Node(type=type);

    va_start(valist, argc);
    for(int i = 0; i < argc; i ++ )
        node->add(va_arg(valist, Node*));
    
    va_end(valist);
    return node;
}

/*
int main(){
    
    auto version1 = 
    (new Node("for_loop"))->add(
        (new Node("ident", "i")))->add(
        (new Node("range"))->add(
            new Node("integer", "1"))->add(
            new Node("integer", "100")))->add(
        (new Node("body"))->add(
            (new Node("var", "myVar"))->add(
                new Node("type", "boolean"))->add(
                new Node("boolean", "true")))->add(
            (new Node("var", "yourVar"))->add(
                new Node("type", "integer"))));
    
    std::cout << "Version 1: \n";
    std::cout << version1->print();
    

   auto version2 = 
    mNode("for_loop")->add(
        mNode("ident", "i"))->add(
        mNode("range")->add(
            mNode("integer", "1"))->add(
            mNode("integer", "100")))->add(
        mNode("body")->add(
            mNode("var", "myVar")->add(
                mNode("type", "boolean"))->add(
                mNode("boolean", "true")))->add(
            mNode("var", "yourVar")->add(
                mNode("type", "integer"))));
    
    std::cout << "\nVersion 2:\n";
    std::cout << version2->print();


    auto version3 = 
    mpNode("for_loop", 3,
        mNode("ident", "i"),
        mpNode("range", 2, 
            mNode("integer", "1"),
            mNode("integer", "100")),
        mpNode("body", 2,
            mpNode("var", "myVar", 2,
                mNode("type", "boolean"),
                mNode("boolean", "true")),
            mpNode("var", "yourVar", 1,
                mNode("type", "integer"))));

    std::cout << "\nVersion3 :\n";
    std::cout << version3->print();

}
*/