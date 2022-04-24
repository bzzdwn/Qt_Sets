#include "String_Set.h"

String_Set::String_Set() : Set() {}
String_Set::String_Set(std::vector <std::string> set_) : Set(set_) {}
String_Set::String_Set(const String_Set& s) {
    (*this) = s;
}
const String_Set& String_Set::operator=(const String_Set& s) {
    set.resize(s.set.size());
    for (size_t i = 0; i < s.set.size(); i++)
    {
        set[i] = s.set[i];
    }
    return *this;
}
std::vector <std::string> String_Set::mult(const Set& rhs) {
    std::vector <std::string> result;
    int max_size = set.size();
    int min_size = rhs.set.size();
    if (max_size < min_size) {
        std::swap(max_size, min_size);
    }
    for (int i = 0; i < max_size; i++)
    {
        for (int j = 0; j < min_size; j++)
        {
            if (max_size == min_size) {
                if (set[i] == rhs.set[j]) {
                    result.push_back(set[i]);
                    break;
                }

            }
            else
                if (max_size == (int)set.size()) {
                    if (set[i] == rhs.set[j]) {
                        result.push_back(set[i]);
                        break;
                    }
                }
                else
                    if (min_size == (int)set.size()) {
                        if (set[j] == rhs.set[i]) {
                            result.push_back(set[j]);
                            break;
                        }
                    }
        }
    }

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = i + 1; j < result.size(); j++)
        {
            if (result[j] == result[i]) {
                for (size_t k = j; k < result.size() - 1; k++)
                {
                    result[k] = result[k + 1];
                }
                result.resize(result.size() - 1);
            }
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = i + 1; j < result.size(); j++)
        {
            if (result[j] == result[i]) {
                for (size_t k = j; k < result.size() - 1; k++)
                {
                    result[k] = result[k + 1];
                }
                result.resize(result.size() - 1);
            }
        }
    }
    return result;
}
std::vector <std::string> String_Set::sim_sub(const Set& rhs) {
    std::vector <std::string> multed, result;
    if (this->set == rhs.set) {
        return result;
    }
    else {

        result = this->add(rhs);
        multed = this->mult(rhs);
        int max_size = result.size();
        int min_size = multed.size();
        if (max_size < min_size) {
            std::swap(max_size, min_size);
        }
        for (int i = 0; i < max_size; i++)
        {
            for (int j = 0; j < min_size; j++)
            {
                if (max_size == min_size) {
                    if (result[i] == multed[j]) {
                        result.erase(result.begin() + i);
                    }

                }
                else
                    if (max_size == (int)result.size()) {
                        if (result[i] == multed[j]) {
                            result.erase(result.begin() + i);
                            max_size--;
                        }
                    }
                    else
                        if (min_size == (int)result.size()) {
                            if (result[j] == multed[i]) {
                                result.erase(result.begin() + j);
                                min_size--;
                            }
                        }
            }
        }
        return result;
    }
}
std::vector <std::string> String_Set::add(const Set& rhs) {
    std::vector <std::string> result(set.size() + rhs.set.size());
    for (size_t i = 0, j = 0; i < set.size() || j < rhs.set.size();) {
        if (set[i] < rhs.set[j]) {
            result[i + j] = set[i];
            i++;
        }
        else {
            result[i + j] = rhs.set[j];
            j++;
        }
        if (i == set.size()) {
            while (j < rhs.set.size()) {
                result[i + j] = rhs.set[j];
                j++;
            }
        }
        if (j == rhs.set.size()) {
            while (i < set.size()) {
                result[i + j] = set[i];
                i++;
            }
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = i + 1; j < result.size(); j++)
        {
            if (result[j] == result[i]) {
                for (size_t k = j; k < result.size() - 1; k++)
                {
                    result[k] = result[k + 1];
                }
                result.resize(result.size() - 1);
            }
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = i + 1; j < result.size(); j++)
        {
            if (result[j] == result[i]) {
                for (size_t k = j; k < result.size() - 1; k++)
                {
                    result[k] = result[k + 1];
                }
                result.resize(result.size() - 1);
            }
        }
    }
    return result;
}
int String_Set::getSize() {
    return set.size();
}
std::string String_Set::operator[](size_t i) const {
    return set[i];
}
bool String_Set::IsEmpty(){
    if(set.size()==0) return true;
    return false;
}
