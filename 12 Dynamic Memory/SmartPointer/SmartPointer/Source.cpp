#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <new>
#include <new.h>
using namespace  std;

#include "ex12_06.h"
#include "ex12_07.h"
#include "ex12_10.h"
#include "ex12_11.h"
#include "ex12_27_30.h"
//#include "ex12_27_30_TEST.cpp"

void func()
{
    // make_shared ����
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>();

    auto p6 = make_shared<vector<string>>();

    // shared_ptr �Ŀ����븳ֵ
    auto p = make_shared<int>(42);  // pָ��Ķ���ֻ��pһ�� ������
    auto q(p);  // p��qָ����ͬ�Ķ��� ����������������
     
    //ex12_06();
    //ex12_07();
    //ex12_10();
   //ex12_11();
    //myfunc();
}