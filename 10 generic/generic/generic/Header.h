#include <iostream>
using namespace std;
#include <numeric>
#include <functional>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std::placeholders;
void func_1()
{
    vector<int> vec = { 1,2,3,4,5,6,6,6,0 };
    cout << "10.1: " << count(vec.cbegin(), vec.cend(), 6) << endl;

    list<string> ls = { "abc", "aaa", "aaa", "ccc" };
    cout << "10.2: " << count(ls.cbegin(), ls.cend(), "aaa") << endl;

}

void func_3()
{
    vector<int> vec = { 1,2,3,4,5,6,7 };
    cout << "accumulate: " << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
    
}

void func_4()
{
    vector<double> vec = { 1,2,3,4,5,6,7.5 };
    cout << "accumulate double: " << accumulate(vec.cbegin(), vec.cend(), 0.0) << endl;

}

void func_6()
{
    vector<int> vec;
    fill_n(back_inserter(vec), 10, 0);
    for_each(vec.cbegin(), vec.cend(), [](int i) {cout << i << " "; });
}

// print containers like vector, deque, list, etc.
template<typename Sequence>
auto println(Sequence const& seq) -> std::ostream&
{
    for (auto const& elem : seq)
        std::cout << elem << " ";
    return std::cout << std::endl;
}

auto eliminate_duplicates(std::vector<std::string> &vs) -> std::vector<std::string>&
{
    std::sort(vs.begin(), vs.end());
    println(vs);

    auto new_end = std::unique(vs.begin(), vs.end());
    println(vs);

    vs.erase(new_end, vs.end());
    return vs;
}

void func_9()
{
    std::vector<std::string> vs{ "a", "v", "a", "s", "v", "a", "a" };
    println(vs);
    println(eliminate_duplicates(vs));
}

void func_14()
{
    auto add =  [] (int a, int b)  mutable->int { return a + b; };
}

void func_16()
{

}

// Exercise 10.20
std::size_t bigerThan6(vector<string> const& v)
{
    return count_if(v.cbegin(), v.cend(), [](string const& s) {
        return s.size() > 6;
    });
}

void SampleUse()
{
    // ex10.20
    vector<string> v{
        "alan","moophy","1234567","1234567","1234567","1234567"
    };
    std::cout << "ex10.20: " << bigerThan6(v) << std::endl;


    // ex10.21
    int i = 7;
    auto check_and_decrement = [&i]() { return --i ? false : true; };
    std::cout << "ex10.21: ";
    while (!check_and_decrement())
        std::cout << i << " ";
    std::cout << i << std::endl;

    
}

bool isLesserThanOrEqualTo6(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

void func_22()
{
    std::vector<string> authors{ "Mooophy", "pezy", "Queequeg90", "shbling", "evan617" };
    std::cout << count_if(authors.cbegin(), authors.cend(), bind(isLesserThanOrEqualTo6, _1, 6));

}

auto check_size(string const& str, size_t sz)
{
    return str.size() < sz;
}
void func_24()
{
    vector<int> vec{ 0,1,2,3,4,5,6,7 };
    string str("123456");
    auto result = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));
}

void func_29()
{
    std::ifstream in("");
    istream_iterator<string> in_inter(in), eof;
    vector<string> vec(in_inter, eof); 
}

void func_34()
{
    std::vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };

    // 10.34
    for (auto rit = vec.crbegin(); rit != vec.crend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // 10.35
    for (auto it = std::prev(vec.crend()); true; --it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // 10.36
    std::list<int> lst = { 1,2,3,4,0,5,6 };
    auto found_0 = std::find(lst.crbegin(), lst.crend(), 0);
    std::cout << std::distance(found_0, lst.crend()) << std::endl;

    // 10.37
    std::list<int> ret_lst(8 - 3);
    std::copy(vec.crbegin() + 3, vec.crbegin() + 8, ret_lst.rbegin());
    for (auto i : ret_lst) std::cout << i << " ";
    std::cout << std::endl;

}

void elimDups(list<string> &words)
{
    words.sort();
    words.unique;
}

void func_42()
{
    list<string> l = { "aa", "aa", "aa", "aass", "aa" };
    elimDups(l);
    for (const auto& e : l)
        std::cout << e << " ";
    std::cout << std::endl;
}