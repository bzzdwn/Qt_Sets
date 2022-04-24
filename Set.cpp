#include <iostream>
#include <vector>
#include <algorithm>
#include "Set.h"
using namespace std;

    Set_int::Set_int(vector<int> v) :set(v) {};
    void Set_int::print(){
        for (auto i : res)
            std::cout << i << ' ';
        std::cout << '\n';
    }
    void Set_int::add(const Set* x1, const Set* x2){
        res.clear();
        Set_int* a = (Set_int*)x1;
        Set_int* b = (Set_int*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j]) res.push_back(a->set[i++]);
            else if (b->set[j] < a->set[i]) res.push_back(b->set[j++]);
            else {
                res.push_back(b->set[j++]);
                i++;
            }
        }
        while (i < a->set.size())
            res.push_back(a->set[i++]);
        while (j < b->set.size())
            res.push_back(b->set[j++]);
    }
    void Set_int::mult(const Set* x1, const Set* x2) {
        res.clear();
        Set_int* a = (Set_int*)x1;
        Set_int* b = (Set_int*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j])
                i++;
            else if (b->set[j] < a->set[i])
                j++;
            else {
                res.push_back(b->set[j]);
                i++;
                j++;
            }
        }
    }
    void Set_int::sim_sub(const Set* x1, const Set* x2) {
        res.clear();
        Set_int* a = (Set_int*)x1;
        Set_int* b = (Set_int*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j]) {
                res.push_back(a->set[i++]);
            }
            else if (b->set[j] < a->set[i]) {
                res.push_back(b->set[j++]);
            }
            else {
                i++;
                j++;
            }
        }
        while (i < a->set.size()) {
            res.push_back(a->set[i++]);
        }
        while (j < b->set.size()) {
            res.push_back(b->set[j++]);
        }
    }
    int Set_int::getSize(){
        return res.size();
    }
    bool Set_int::IsEmpty(){
        return (res.size()==0);
    }
    int Set_int::operator[](size_t i) const {
        return res[i];
    }
    Set_string::Set_string(vector<string> v) :set(v) {};
    void Set_string::print(){
        for (auto i : res)
            std::cout << i << ' ';
        cout << '\n';
    }
    void Set_string::add(const Set* x1, const Set* x2) {
        res.clear();
        Set_string* a = (Set_string*)x1;
        Set_string* b = (Set_string*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j]) res.push_back(a->set[i++]);
            else if (b->set[j] < a->set[i]) res.push_back(b->set[j++]);
            else {
                res.push_back(b->set[j++]);
                i++;
            }
        }
        while (i < a->set.size())
            res.push_back(a->set[i++]);
        while (j < b->set.size())
            res.push_back(b->set[j++]);
    }
    void Set_string::mult(const Set* x1, const Set* x2) {
        res.clear();
        Set_string* a = (Set_string*)x1;
        Set_string* b = (Set_string*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
            if (a->set[i] < b->set[j])
                i++;
            else if (b->set[j] < a->set[i])
                j++;
            else {
                res.push_back(b->set[j]);
                i++;
                j++;
            }
        }
    }
    void Set_string::sim_sub(const Set* x1, const Set* x2) {
        res.clear();
        Set_string* a = (Set_string*)x1;
        Set_string* b = (Set_string*)x2;
        int i = 0, j = 0;
        std::sort(a->set.begin(), a->set.end());
        std::sort(b->set.begin(), b->set.end());
        while (i < a->set.size() && j < b->set.size()) {
if (a->set[i] < b->set[j]) {
    res.push_back(a->set[i++]);
}
else if (b->set[j] < a->set[i]) {
    res.push_back(b->set[j++]);
}
else {
    i++;
    j++;
}
    }
    while (i < a->set.size()) {
        res.push_back(a->set[i++]);
    }
    while (j < b->set.size()) {
        res.push_back(b->set[j++]);
    }
  }
    int Set_string::getSize(){
        return res.size();
    }
    string Set_string::operator[](size_t i) const {
        return res[i];
    }
    bool Set_string::IsEmpty(){
        return (res.size()==0);
    }
