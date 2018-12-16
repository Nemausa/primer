#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <list>

//////////////////////////////////////////////////////////////////////////
//  @file     Header.h
//  @author   AHVincent
//  @date     28 Dec 2017
//  @remark   This code is for the exercise from C++ Primer 5th Edition
//  @note
//////////////////////////////////////////////////////////////////////////


template <typename T>
int compare(const T& lhs, const T& rhs) {
    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
}

// array
template<unsigned N, class T>
void print(T(&arr)[N])
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 16.4
namespace ch16
{
    template<class iterator, class value>
    auto find(iterator first, iterator last, value const& value)
    {
        for (; first != last && *first != value; ++first);
        return first;
    }
}

void ch16_4()
{
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9 };
    auto is_in_vector = v.cend() != ch16::find(v.cbegin(), v.cend(), 5);
    cout << (is_in_vector ? "found\n" : "not found\n");

    list<string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
    auto is_in_list = l.cend() != ch16::find(l.cbegin(), l.cend(), "zz");
    cout << (is_in_list ? "found\n" : "not found\n");

}

// 16.19
template<typename container>
ostream& print(container const& container, ostream& os)
{
    for (typename container::size_type i = 0; i != container.size(); ++i)
        os << container[i] << " ";
    return os;
    
}

// 16.20
template<typename container>
ostream& print2(container const& container, ostream& os)
{
    for (auto curr = container.cbegin(); curr != container.cend(); ++curr)
        os << *curr << " ";
    return os;
}

void ch16_19()
{
    std::vector<int> v = { 1,23,6,4,5,7,4 };
    std::list<std::string> l = { "ss", "sszz", "saaas", "s333s", "ss2", "sss" };
    print2(v, std::cout) << std::endl;
    print2(l, std::cout) << std::endl;
    

}

int smapleuse() {
    
    // Test compare function
    cout << compare(1, 0) << endl;
    vector<int> vec1{ 1,2,3 },vec2{ 4,5,6 };
    cout << compare(vec1, vec2) << endl;

    int arr[5] = { 1,2,3,4,5 };
    print(arr);
    ch16_4();
    ch16_19();
    
    return 0;
}

