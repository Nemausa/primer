#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "AHExercise.h"
#define NDEBUG
#include <assert.h>
string::size_type(*pf)(const string &s, char c, string::size_type &occurs);

void change(const int* &v)
{
    cout << *v << endl;
}


string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i=0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}




int main()
{
    //int n(1);
    //int *p = &n;
    //const int* v = p;
    //change(v);
    //cout << *p << endl;
    //const int &r = 43;
    //string::size_type ctr;
    //find_char("", 'o', ctr);
    int ia[10] = { 1,2,3,4,5,6,7,8,9 };
    //fun_24(ia);
    cout << factorial(3);
    //vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
    //fun_33(vec.cbegin(), vec.cend());
    //int condition(0);
    //assert(condition>1);
    //interactive_fact();
    //fun_54();
   
    

    return 0;
}