#ifndef SET_H
#define SET_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class  Set {
public:
    virtual void mult(const  Set*, const Set*) = 0;
    virtual void add(const  Set*, const  Set*) = 0;
    virtual void sim_sub(const Set*, const Set*) = 0;
    virtual void print() = 0;
};
class Set_int : public Set {
public:
    vector<int> set;
    vector <int> res;
    Set_int(vector<int> v = {});
    void print();
    void add(const Set* x1, const Set* x2);
    void mult(const Set* x1, const Set* x2);
    void sim_sub(const Set* x1, const Set* x2);
    int getSize();
    bool IsEmpty();
    int operator[](size_t i) const;
};
class Set_string : public Set {
public:
    vector<string> set;
    vector <string> res;
    Set_string(vector<string> v = {});
    void print();
    void add(const Set* x1, const Set* x2);
    void mult(const Set* x1, const Set* x2);
    void sim_sub(const Set* x1, const Set* x2);
    bool IsEmpty();
    int getSize();
    string operator[](size_t i) const;
};
#endif // SET_H
