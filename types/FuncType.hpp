#ifndef FUNCTYPE_HPP
#define FUNCTYPE_HPP

#include "Type.hpp"
#include "ListType.hpp"

class FuncType : public Type
{
    std::string name_ = "fun";

public:
    ListType *listtype_;
    Type *type_;

    std::string getName()
    {
        return this->name_;
    }
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " (";
        for (int i = 0; i < this->listtype_->types_.size(); ++i)
        {
            returnString += (this->listtype_->types_[i]->toString() + " ");
        }
        if (this->type_ != nullptr)
            returnString += (") -> " + this->type_->toString() + "]");
        else
            returnString += (")]");

        return returnString;
    }
    FuncType(const FuncType &);
    FuncType &operator=(const FuncType &);
    FuncType(ListType *p1, Type *p2);
    ~FuncType();
    void swap(FuncType &);
    virtual FuncType *clone() const;
};

FuncType::FuncType(const FuncType &other)
{
  listtype_ = other.listtype_->clone();
  type_ = other.type_->clone();
}

FuncType::FuncType(ListType *p1, Type *p2)
{
  listtype_ = p1;
  type_ = p2;
}


FuncType &FuncType::operator=(const FuncType &other)
{
  FuncType tmp(other);
  swap(tmp);
  return *this;
}

void FuncType::swap(FuncType &other)
{
  std::swap(listtype_, other.listtype_);
  std::swap(type_, other.type_);
}

FuncType::~FuncType()
{
  delete (listtype_);
  delete (type_);
}

FuncType *FuncType::clone() const
{
  return new FuncType(*this);
}

#endif //FUNCTYPE_HPP