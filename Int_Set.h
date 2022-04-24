#ifndef INT_SET_H
#define INT_SET_H
#include "Set.h"
class Int_Set : public Set <int> {
public:
    Int_Set();
    Int_Set(std::vector <int> set_);
    Int_Set(const Int_Set& s);
    const Int_Set& operator=(const Int_Set& s);
    std::vector <int> mult(const Set& rhs);
    std::vector <int> add(const Set& rhs);
    std::vector <int> sim_sub(const Set& rhs);
    int getSize();
    int operator[](size_t i) const;
    bool IsEmpty();
};
#endif // INT_SET_H
