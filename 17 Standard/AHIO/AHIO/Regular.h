//////////////////////////////////////////////////////////////////////////
//
// @file	 : Regular.h
// @author 	 : AHVincent
// @date	 : 2018-02-06
// @mail	 : vincentlee@usa.com
//
// @brief	 : 
//
//////////////////////////////////////////////////////////////////////////

#ifndef  REGULAR_H
#define  REGULAR_H

#include <iostream>
#include <regex>
#include <string>

namespace ahregular
{ 
    void sampleuse()
    {
        std::string pattern("[^c]ei");
        pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
        std::regex r(pattern);
        std::smatch results;
        std::string test_str = "receipt freind theif receive";
        if (std::regex_search(test_str, results, r))
            std::cout << results.str() << std::endl;


    }
}



#endif  // REGULAR_H
