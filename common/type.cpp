#include <string>

class Type {
public:
    virtual ~Type() {}
};

class TypeInteger : public Type {
public:
    TypeInteger(){}
};

class TypeBoolean : public Type {
public:
    TypeBoolean(){}
};

class TypeReal : public Type {
public:
    TypeReal(){}
};

class TypeRoutine : public Type {
public:
    Type* type;
    std::vector<Type*>paramTypes;
    TypeRoutine(Type* type, std::vector<Type*>paramTypes):
    type(type), paramTypes(paramTypes){}
};


std::string toString(Type* type) 
{
    if( type == nullptr )
        return "TYPENULL";
    if( auto t = dynamic_cast<TypeBoolean*>(type))
        return "BOOLEAN";
    if( auto t = dynamic_cast<TypeInteger*>(type))
        return "INTEGER";
    if( auto t = dynamic_cast<TypeReal*>(type))
        return "REAL";
    if( auto t = dynamic_cast<TypeRoutine*>(type))
        return "ROUTINE";
    throw std::runtime_error("toString: type is not implemented");
}


Type *mapType(Node *node) 
{
    if( node->type == "type" && node->children[0]->type == "primitive_type" ) {
        auto value = node->children[0]->value;
        if( value == "integer" )
            return new TypeInteger();
        if( value == "boolean" )
            return new TypeBoolean();
        if( value == "real" )
            return new TypeReal();
        else
            throw std::runtime_error("mapType: Primitive type " + value + " is not supported");
    }
    else{
        throw std::runtime_error("mapType: Node with " + node->children[0]->value + " type is not implemented");
    }
}
