#include "StdAfx.h"
#include "AHFile.h"
#include "AHDir.h"
#include <iostream>
#include <fstream>
//#include <hash_set>
#include <unordered_set>
AHFile::AHFile(void)
{
}


AHFile::~AHFile(void)
{
}

void AHFile::ReadFileToDeque(const std::string filename, std::deque<std::string> & deq)
{
	std::ifstream ifs((char*)filename.data());
	if (ifs)
	{
		std::string buf;
		while (ifs)
		{
			while (getline(ifs, buf))
			{
				// paht is exist, read to deque
				if (AHDir::IsDirExist(buf))
					deq.push_front(buf);
					
			}
		}
	
	}
}

void AHFile::SaveDequeToFile(const std::string &filename, std::deque<std::string> &deq)
{
	std::ofstream ofs((char*)filename.data());
	
	// remove duplicate data
	std::unordered_set<std::string> hs(deq.begin(), deq.end());
	for (auto rit = hs.begin(); rit!= hs.end(); ++rit)
		ofs << *rit << std::endl;
	
}