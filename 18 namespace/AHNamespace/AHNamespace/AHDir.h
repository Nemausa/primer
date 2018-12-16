#include <iostream>
#include <fstream>
#include <io.h>  
#include <direct.h>    
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

namespace AHDir
{
    bool IsDirExist(const std::string dirname)
    {
        int ftyp = _access(dirname.c_str(), 0);

        if (0 == ftyp)
            return true;	 // this is a directory!  
        else
            return false;    // this is not a directory!  
    }

    bool IsFileExist(const std::string filename)
    {
        std::fstream file;
        file.open(filename, ios::in);
        if (!file)
            return false;
        else
            return true;
    }

    bool AHCreateFile(const std::string filename)
    {
        std::vector<std::string> sz;
        string str(filename);
        const char* split = "\\";
        //char* chr = strdup(str.c_str());
        char* buf;
        char* cstr = &str[0u];
        char* p = strtok_s(&str[0], split, &buf);
        while (p != NULL) {
            sz.push_back(p);
            p = strtok_s(NULL, split, &buf);
        }

        int ret(0);
        for (size_t i = 2; i <= sz.size(); ++i)
        {
            string s = accumulate(sz.begin(), sz.begin() + i, string(""),
                [](string &a, string &b) { return a + b + "\\"; });
            if (i != sz.size())
            {
                if (!IsDirExist(s))
                    ret = _mkdir(s.c_str());
                if (ret != 0)
                    return false;
            }
            if (i == sz.size())
            {
                s = s.substr(0, s.length() - 1);
                if (!IsFileExist(s))
                {
                    ofstream  file(s);
                    if (!file)
                        return false;
                }
                
            }

        }
        //free(chr);
        return true;
    }


    bool AHCreateDir(const std::string dirname)
    {
        std::vector<std::string> sz;
        string str(dirname);
        const char* split = "\\";
        char* buf;
        char* p = strtok_s(&str[0], split, &buf);
        while (p != NULL) {
            sz.push_back(p);
            p = strtok_s(NULL, split, &buf);
        }

        int ret(0);
        for (size_t i = 2; i <= sz.size(); ++i)
        {
            string s = accumulate(sz.begin(), sz.begin() + i, string(""),
                [](string &a, string &b) { return a + b + "\\"; });

                if (!IsDirExist(s))
                    ret = _mkdir(s.c_str());
                if (ret != 0)
                    return false;

        }
        return true;
    }
}

