#ifndef LISTTYPE_HPP
#define LISTTYPE_HPP

#include "Type.hpp"

class ListType : public Type
{
    std::string name_ = "list";

public:
    std::vector<Type *> types_;

    std::string getName()
    {
        return this->name_;
    }
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " (";
        for (int i = 0; i < this->types_.size(); ++i)
        {
            returnString += (this->types_[i]->toString() + " ");
        }
        returnString += ")]";
        return returnString;
    }
    ListType(const ListType &);
    ListType &operator=(const ListType &);
    ListType(std::vector<Type *> p1);
    ~ListType();
    void swap(ListType &);
    virtual ListType *clone() const { return nullptr; };
};


ListType::ListType(std::vector<Type *> p1)
{
  types_ = p1;
}

ListType::ListType(const ListType &other)
{
  types_ = other.types_;
}

ListType &ListType::operator=(const ListType &other)
{
  ListType tmp(other);
  swap(tmp);
  return *this;
}

ListType *consListType(Type *x, ListType *xs)
{
  xs->types_.push_back(x);
  return xs;
}
void ListType::swap(ListType &other)
{
  std::swap(types_, other.types_);
}

ListType::~ListType()
{
  types_.clear();
}

#endif //LISTTYPE_HPP