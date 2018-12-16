//////////////////////////////////////////////////////////////////////////
// 
// FileName     :  StrBlob.h
// Author       :  VincentLee
// CreateTime   :  2017-11-17
// Mail         :  vincentlee@usa.com
//
// Description  :  
//
//////////////////////////////////////////////////////////////////////////

#ifndef   STRBLOB_H_
#define   STRBLOB_H_
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace  std;

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); }
    // ��Ӻ�ɾ��Ԫ��
    void push_back(const std::string &t) { data->push_back(t); };
    void pop_back();
    // Ԫ�ط���
    string& front();
    string& back();
private:
    std::shared_ptr<std::vector<string>> data;
    // ���data[i]���Ϸ��� �׳�һ���쳣
    void check(size_type i, const string &msg) const;
    ~StrBlob();
};



#endif  // STRBLOB_H_
