#ifndef PRIMITIVETYPES_HPP
#define PRIMITIVETYPES_HPP

#include "Type.hpp"

class TypeInteger : public Type
{
    std::string name_ = "integer";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    std::string getName()
    {
        return this->name_;
    }
    TypeInteger(){};
    void swap(Type &){};
    virtual TypeInteger *clone() const;
};

class TypeReal : public Type
{
    std::string name_ = "real";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    std::string getName()
    {
        return this->name_;
    }
    TypeReal(){};
    void swap(Type &){};
    virtual TypeReal *clone() const;
};

class TypeBool : public Type
{
    std::string name_ = "bool";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    std::string getName()
    {
        return this->name_;
    }

    void swap(Type &){};
    TypeBool(){};
    virtual TypeBool *clone() const { return nullptr; };
};

class TypeChar : public Type
{
    std::string name_ = "char";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    TypeChar(){};
    std::string getName()
    {
        return this->name_;
    }
    void swap(Type &){};
    virtual TypeChar *clone() const { return nullptr; };
};

TypeInteger *TypeInteger::clone() const
{
  return new TypeInteger(*this);
}

TypeReal *TypeReal::clone() const
{
  return new TypeReal(*this);
}

#endif //PRIMITIVETYPES_HPP