#include "StdAfx.h"
#include "AHDir.h"
#include <iostream>
#include <fstream>
#include <io.h>  
using namespace std;

AHDir::AHDir(void)
{
}


AHDir::~AHDir(void)
{
}

bool AHDir::IsDirExist(const std::string dirname)
{
	int ftyp = _access(dirname.c_str(), 0);  
  
    if (0 == ftyp)  
        return true;	 // this is a directory!  
    else   
        return false;    // this is not a directory!  
}

bool AHDir::IsFileExist(const std::string filename)
{
	std::fstream _file;
    _file.open(filename,ios::in);
    if(!_file)
		return false;
	else 
		return true;
}