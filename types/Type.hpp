#ifndef TYPE_HPP
#define TYPE_HPP
#include <vector>
#include <string>
#include <algorithm>

class Type;

class Type
{
    std::string name_ = "type";

public:
    virtual std::string getName() = 0;
    virtual Type *clone() const = 0;
    int line_number, char_number;
    void swap(Type &);
    virtual std::string toString() = 0;
};

#endif // TYPE_HPP