#ifndef RETURNTYPE_HPP
#define RETURNTYPE_HPP

#include "Type.hpp"

class ReturnType : public Type
{
    std::string name_ = "return_type";

public:
    Type *type_;

    std::string getName()
    {
        return this->name_;
    }
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " ";
        if (type_ == nullptr)
            returnString += this->type_->toString() + "]";
        else
            returnString += "]";
        return returnString;
    }

    ReturnType(const ReturnType &);
    ReturnType &operator=(const ReturnType &);
    ReturnType(Type *p1);
    ~ReturnType();
    void swap(ReturnType &);
    virtual ReturnType *clone() const;
};

ReturnType::ReturnType(Type *p1)
{
  type_ = p1;
}

ReturnType::ReturnType(const ReturnType &other)
{
  type_ = other.type_->clone();
}

ReturnType &ReturnType::operator=(const ReturnType &other)
{
  ReturnType tmp(other);
  swap(tmp);
  return *this;
}

void ReturnType::swap(ReturnType &other)
{
  std::swap(type_, other.type_);
}

ReturnType::~ReturnType()
{
  delete (type_);
}

ReturnType *ReturnType::clone() const
{
  return new ReturnType(*this);
}


#endif //RETURNTYPE_HPP