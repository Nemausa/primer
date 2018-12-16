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

#ifndef  AHFILE_H_
#define  AHFILE_H_
#include <string>
#include <deque>

class AHFile
{
public:
	AHFile(void);
	~AHFile(void);
	static void ReadFileToDeque(const std::string filename, std::deque<std::string> &deq);
	static void SaveDequeToFile(const std::string &filename, std::deque<std::string> &deq);
};


#endif  // AHFILE_H_

