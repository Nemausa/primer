// AHUtil.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "AHFile.h"


void PrintfDay(int y, int m, int d); //声明PrintfDay函数  

void CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2) //把一月和二月换算成上一年的十三月和是四月  
    {
        m += 12;
        y--;
    }
    // 基姆拉尔森计算公式
    int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (Week)
    {
    case 0: PrintfDay(y, m, d); cout << "是星期一" << endl; break;
    case 1: PrintfDay(y, m, d); cout << "是星期二" << endl; break;
    case 2: PrintfDay(y, m, d); cout << "是星期三" << endl; break;
    case 3: PrintfDay(y, m, d); cout << "是星期四" << endl; break;
    case 4: PrintfDay(y, m, d); cout << "是星期五" << endl; break;
    case 5: PrintfDay(y, m, d); cout << "是星期六" << endl; break;
    case 6: PrintfDay(y, m, d); cout << "是星期日" << endl; break;
    }
}


void PrintfDay(int y, int m, int d)
{
    cout << y << "年" << m << "月" << d << "日";
}


int _tmain(int argc, _TCHAR* argv[])
{
    //string path = "E:\\VincentWork\\Smart Pointers\\AHUtil\\open.txt";
    //std::deque<string> deq;
    //deq.push_front("E:\\CSMProgram\\VS2010\\12.15C\\Debug\\Project\\10");
    //AHFile::SaveDequeToFile(path, deq);
    CaculateWeekDay(1, 1, 1);

    string s = to_string(10);
    double d = stod(s);
    return 0;

}

