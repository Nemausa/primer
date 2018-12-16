#include "StrBlob.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

StrBlob::StrBlob()
{
    data = std::make_shared<std::vector<string>>();
}


StrBlob::~StrBlob()
{
}


StrBlob::StrBlob(std::initializer_list<std::string> il)
{
    data = make_shared<vector<string>>(il);
}
   

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    // ��� vectorΪ�գ� check ���׳�һ���쳣
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

