//////////////////////////////////////////////////////////////////////////
// CopyRight (C)   VincentLee
//
// File Name	 : AHFile.h
// Author		 : VincentLee
// CreateTime	 : 2017-12-22
// Mail			 : vincentlee@usa.com
//
// Description   : record
//
//////////////////////////////////////////////////////////////////////////

#ifndef  AHDIR_H_
#define  AHDIR_H_

#include <string>


class AHDir
{
public:
	AHDir(void);
	~AHDir(void);
	static bool IsDirExist(const std::string dirname);
	static bool IsFileExist(const std::string filename);
};

#endif  // AHDIR_H_ 