#ifndef STRING_SET_H
#define STRING_SET_H
#include "Set.h"
#include <string>
class String_Set : public Set <std::string> {
public:
    String_Set();
    String_Set(std::vector <std::string> set_);
    String_Set(const String_Set& s);
    const String_Set& operator=(const String_Set& s);
    std::vector <std::string> mult(const Set& rhs);
    std::vector <std::string> add(const Set& rhs);
    std::vector <std::string> sim_sub(const Set& rhs);
    int getSize();
    std::string operator[](size_t i) const;
    bool IsEmpty();
};
#endif // STRING_SET_H
