#ifndef SET_H
#define SET_H
#include <vector>
#include <algorithm>
class String_Set;
class Int_Set;
template <class T>
class Set {
protected:
    std::vector <T> set;
    Set() : set() {}
    Set(std::vector <T> set_) : set(set_) {
        std::sort(set.begin(), set.end());
        std::unique(set.begin(), set.end());
    }
public:
    friend class String_Set;
    friend class Int_Set;
    virtual std::vector <T> add(const Set& rhs) = 0;
    virtual std::vector <T> mult(const Set& rhs) = 0;
    virtual std::vector <T> sim_sub(const Set& rhs) = 0;
};

#endif // SET_H
