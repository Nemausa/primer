// bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
//
void sample()
{
    int val = 100;
    if (0 == val & 1)
        std::cout << "ÆæÊý" << std::endl;
    else
        std::cout << "Å¼Êý" << std::endl;

    int n = 33;
    int n1 = (n >> 0) & 1;
    system("pause");
}

int main()
{
    sample();
    return 0;
}

