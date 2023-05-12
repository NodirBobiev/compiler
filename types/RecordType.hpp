#ifndef RECORDTYPE_HPP
#define RECORDTYPE_HPP

#include "Type.hpp"
#include "ListType.hpp"

class RecordType : public Type
{
    std::string name_ = "record";

public:
    ListType *listtype_;
    std::vector<std::string> names;

    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " (";
        for (int i = 0; i < this->listtype_->types_.size(); ++i)
        {
            returnString += names[i] + " : ";
            returnString += (this->listtype_->types_[i]->toString() + " ");
        }
        returnString += ")]";
        return returnString;
    }

    std::string getName()
    {
        return this->name_;
    }
    RecordType(const RecordType &);
    RecordType &operator=(const RecordType &);
    RecordType(ListType *p1, std::vector<std::string> p2);
    ~RecordType();
    void swap(RecordType &);
    virtual RecordType *clone() const;
};

RecordType::RecordType(ListType *p1, std::vector<std::string> p2)
{
  listtype_ = p1;
  names = p2;
}

RecordType::RecordType(const RecordType &other)
{
  listtype_ = other.listtype_->clone();
}

RecordType &RecordType::operator=(const RecordType &other)
{
  RecordType tmp(other);
  swap(tmp);
  return *this;
}

void RecordType::swap(RecordType &other)
{
  std::swap(listtype_, other.listtype_);
}

RecordType::~RecordType()
{
  delete (listtype_);
}

RecordType *RecordType::clone() const
{
  return new RecordType(*this);
}


#endif //RECORDTYPE_HPP