#ifndef ARRAYTYPE_HPP
#define ARRAYTYPE_HPP

#include "Type.hpp"

class ArrayType : public Type
{
    std::string name_ = "array";

public:
    Type *type_;

    std::string toString()
    {
        std::string returnString = "[" + this->name_ +
                                   " " + this->type_->toString() + "]";
        return returnString;
    }

    std::string getName()
    {
        return this->name_;
    }
    ArrayType(const ArrayType &);
    ArrayType &operator=(const ArrayType &);
    ArrayType(Type *p1);
    ~ArrayType();
    void swap(ArrayType &);
    virtual ArrayType *clone() const;
};

ArrayType::ArrayType(Type *p1)
{
  type_ = p1;
}

ArrayType::ArrayType(const ArrayType &other)
{
  type_ = other.type_->clone();
}

ArrayType &ArrayType::operator=(const ArrayType &other)
{
  ArrayType tmp(other);
  swap(tmp);
  return *this;
}

void ArrayType::swap(ArrayType &other)
{
  std::swap(type_, other.type_);
}

ArrayType::~ArrayType()
{
  delete (type_);
}

ArrayType *ArrayType::clone() const
{
  return new ArrayType(*this);
}


#endif //ARRAYTYPE_HPP