// AHUtil.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "AHFile.h"


void PrintfDay(int y, int m, int d); //����PrintfDay����  

void CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2) //��һ�ºͶ��»������һ���ʮ���º�������  
    {
        m += 12;
        y--;
    }
    // ��ķ����ɭ���㹫ʽ
    int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (Week)
    {
    case 0: PrintfDay(y, m, d); cout << "������һ" << endl; break;
    case 1: PrintfDay(y, m, d); cout << "�����ڶ�" << endl; break;
    case 2: PrintfDay(y, m, d); cout << "��������" << endl; break;
    case 3: PrintfDay(y, m, d); cout << "��������" << endl; break;
    case 4: PrintfDay(y, m, d); cout << "��������" << endl; break;
    case 5: PrintfDay(y, m, d); cout << "��������" << endl; break;
    case 6: PrintfDay(y, m, d); cout << "��������" << endl; break;
    }
}


void PrintfDay(int y, int m, int d)
{
    cout << y << "��" << m << "��" << d << "��";
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

