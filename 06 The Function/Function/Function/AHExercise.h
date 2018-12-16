//////////////////////////////////////////////////////////////////////////
// CopyRight(C) 
// 
// File Name    : AHExercise.h
// Author       : VincentLee
// Date         : 2017-12-02
// Mail         : vincentlee@usa.com
//
// Description  :  
//
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Iter = vector<int>::const_iterator;
//inline int f(const int, const int); 
//typedef decltype(f) fp;
using fp = int (const int, const int);

inline int NumAdd(const int n1, const int n2) { return n1 + n2; }
inline int NumSub(const int n1, const int n2) { return n1 - n2; }
inline int NumMul(const int n1, const int n2) { return n1 * n2; }
inline int NumDiv(const int n1, const int n2) { return n1 / n2; }

vector<fp*> v{ NumAdd, NumSub, NumMul, NumDiv };

// 6.3
int fact(int i)
{
    if (i < 0)
    {
        runtime_error err("Input cannot be a negative number");
        cout << err.what() << endl;
    }
    return i > 1 ? i*fact(i - 1) : 1;
}

// 6.4
void interactive_fact()
{
    const string prompt = "Enter a number within [1, 13] :\n";
    const string out_of_range = "Out of range, please try again.\n";
    for (int i; cout << prompt, cin >> i;)
    {
        if (i < 1 || i>12)
        {
            cout << out_of_range << endl;
            continue;
        }
        cout << fact(i) << endl;
    }
}


int fun_21(const int val, const int* p)
{
    return (val > *p) ? val : *p;
}

void fun_22(int* lft, int* rft)
{
    auto temp = lft;
    lft = rft;
    rft = temp;
}

void fun_24(const int (&ia)[10])
{
    cout << __func__ << endl;
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
// 34
int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
    return 1;
}

void fun_33(Iter first, Iter last)
{
   
    if (first != last)
    {
        cout << *first << endl;
        fun_33(++first, last);
    }
}

void fun_54()
{
    //
    // @brief Exercise 6.56
    // @note  Call each element in the vector and print their result.
    //
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        cout << (*it)(2, 2) << std::endl;
}

