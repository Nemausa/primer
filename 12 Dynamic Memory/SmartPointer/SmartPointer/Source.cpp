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
    // make_shared 函数
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>();

    auto p6 = make_shared<vector<string>>();

    // shared_ptr 的拷贝与赋值
    auto p = make_shared<int>(42);  // p指向的对象只有p一个 引用者
    auto q(p);  // p和q指向相同的对象， 对象有两个引用者
     
    //ex12_06();
    //ex12_07();
    //ex12_10();
   //ex12_11();
    //myfunc();
}