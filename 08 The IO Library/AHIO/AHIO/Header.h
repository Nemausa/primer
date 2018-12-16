#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>
using namespace  std;

istream& func(istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

// 2
void func_2()
{
    istream& is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
}

// 4
void ReadFileToVec(const string &filename, vector<string> &vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        //while (getline(ifs, buf))
        while (ifs >> buf)
            vec.push_back(buf);
    }
}

void func_4()
{
    vector<string> vec;
    ReadFileToVec("E:\\C++ Primer 5\\8 The IO Library\\book.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
}


struct PersonInfo {
    string name;
    vector<string> phones;
};

void myinfo()
{
    string line, word;
    vector<PersonInfo> people;
    while (getline(cin, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);

    }
}

// 13
bool valid(const string& str)
{
    return isdigit(str[0]);
}

string format(const string& str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int readphone()
{
    string filepath = "E:\\C++ Primer 5\\Cpp-Primer-master\\data\\phonenumbers.txt";
    ifstream ifs(filepath);
    if (!ifs)
    {
        cerr << "no phone number" << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info); 
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
            if (badNums.str().empty())
                cout << entry.name << " " << formatted.str() << endl;
            else
                cerr << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << endl;
    }
}