#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <deque>
#include <fstream>
using namespace std;
bool contains(vector<int>::const_iterator first, vector<int>::const_iterator last, int value)
{
    for (; first != last; ++first)
        if (*first == value) return true;
    return false;
}

// six ways to create and initialize a vector.
void init()
{
    vector<int> vec;
    vector<int> vec2(10);
    vector<int> vec3(10, 1);
    vector<int> vec4{ 1,2,3,4,5 };
    vector<int> vec5(vec);
    vector<int> vec6(vec.begin(), vec.end());

   

}

// 13
void func_13()
{
    array<int, 10> a1;
    a1 = { 1,2,3,4,5,6,7,8,9 };
    a1 = { 0};
    list<int> ilst(5, 4);
    vector<int> ivc(5, 5);

    // from list to vector
    vector<double> dvc(ilst.begin(), ilst.end());
    for (auto i : ilst) cout << i << " ";
    cout << endl;
    for (auto i : dvc) cout << i << " ";
    cout << endl;

    // from vector<int> to  vector<double>
    vector<double> dvc2(ivc.begin(), ivc.end());
    for (auto i : ivc) cout << i << " ";
    cout << endl;
    for (auto i : dvc2) cout << i << " ";
    cout << endl;

}

// swap
void ahswap()
{
    vector<int> ivc1{ 1, 2, 3, 4, 5 };
    vector<int> ivc2{ 7,8,9,10,11,12 };
    auto iter1 = ivc1.begin();
    auto iter2 = ivc2.begin();
    cout << "iter1  iter2 " << *iter1 << " " << *iter2 << endl;
    swap(iter1, iter2);
    cout << "iter1  iter2 " << *iter1 << " " << *iter2 << endl;
    
}

void func_14()
{
    list<const char*> l{ "Monday", "Thuesday", "Wednesday" };
    vector<string> vec;
    vec.assign(l.begin(), l.end());
    for (auto i : vec)
        cout << i << endl;
}

// @Brief Write a program to determine whether two vector<int>s are equal.
void func_15()
{
    std::vector<int> vec1 = { 1,2,3,4,5 };
    std::vector<int> vec2 = { 1,2,3,4 };
    std::vector<int> vec3 = { 1,2,3,4,5 };

    std::cout << (vec1 == vec2 ? "true" : "false") << endl;
    std::cout << (vec1 == vec3 ? "ture" : "false") << endl;

}


void func_16()
{
    std::list<int>      li{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec2{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec3{ 1, 2, 3, 4 };

    cout << (vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << endl;
    cout << (vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << endl;

}

//  @Brief  Write a program to read a sequence of strings from the standard input into
//          a deque. Use iterators to write a loop to print the elements in the deque.
int func_18()
{
    deque<string> input;
    for (string str; cin >> str; input.push_back(str));
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;
    
    return 0;
}

int func_19()
{
    list<string> input;
    for (string str; cin >> str; input.push_back(str));
    for (auto iter = input.cbegin(); iter != input.cend(); ++iter)
        cout << *iter << endl;

    return 0;
}

int func_20()
{
    list<int> li = { 1,2,3,4,5,6,7 };
    deque<int> odd, even;
    for (auto i : li)
        ((i & 0x1) ? odd : even).push_back(i);

    for (auto i : odd) cout << i << " ";
    cout << endl;
    for (auto i : even) cout << i << " ";
    cout << endl;

    return 0;
}

int func_24()
{
    vector<int> vec;
    auto iter1 = vec[0];
    auto iter2 = vec.at(0);
    auto iter3 = vec.begin();
    auto iter4 = vec.front();
    cout << iter1 << " " << iter2 << " " << *iter3 << " " << iter4 << endl;

    return 0;
}

void func_34()
{
    vector<int> vi = { 1,2,3,4,5,6,7 };
    for (auto cur = vi.begin(); cur!=vi.end(); ++cur)
        if (*cur & 0x01)
            cur = vi.insert(cur, *cur), ++cur;

    for (auto cur : vi)
        cout << cur << " ";
     
    cout << endl;

}

void func_38()
{
    vector<int> vi = { 1,2,3,4 };
    while (vi.size() != vi.capacity())
        vi.push_back(0);
    cout << "vi size:" << vi.size()
        << "capacity" << vi.capacity();

    vi.push_back(42);
    cout << "vi size:" << vi.size()
        << "capacity" << vi.capacity();

}

void func_41()
{
    vector<char> v{ 'p', 'e', 'z', 'y' };
    string str(v.cbegin(), v.cend());
    cout << str << endl;
}

void func_47()
{
    string numbers{ "123456789" };
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    string str{ "ab2c3d7R4E6" };

    cout << "numeric characters: ";
    for (int pos = 0; (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << "\nalphabetic characters: ";
    for (int pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)
        cout << str[pos] << " ";
    cout << endl;
}

void func_49()
{
    ifstream ifs("../../data/letter.txt");
    if (!ifs) return ;

    string longest;
    auto update_with = [&longest](string const& curr)
    {
        if (string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
            longest = longest.size() < curr.size() ? curr : longest;
    };
    for (string curr; ifs >> curr; update_with(curr));
    cout << longest << endl;
}
auto sum_for_int(std::vector<std::string> const& v)
{
    int sum = 0;
    for (auto const& s : v)
        sum += std::stoi(s);
    return sum;
}

auto sum_for_float(std::vector<std::string> const& v)
{
    float sum = 0.0;
    for (auto const& s : v)
        sum += std::stof(s);
    return sum;
}
auto add_pre_and_suffix(string name, string const& pre, string const& su)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    return name.append(su);
}

void ahstring()
{
    // 初始化
    const char *cp = "hello world!!!";
    char noNull[] = { 'h', 'i' };
    string s1(cp);              // 拷贝cp中的字符直到遇到空字符； s1 == "hello world"
    string s2(noNull, 2);       // 从noNUll拷贝两个字符； s2 == "hi"
    string s3(noNull);          // 未定义，noNull不是以空字符结束
    string s4(cp + 6, 5);       // 从cp[6]开始拷贝5个字符   s4 == "world"
    string s5(s1, 6, 5);        // 从s1[6]开始拷贝5个字符； s5 == "world"
    string s6(s1, 6);           // 从s1[6]开始拷贝，直至s1结尾； s6 == "world!!!"
    string s7(s1, 6, 20);       // 正确，只拷贝到s1结尾； s7 = "world!!!"
    //string s8(s1, 16);          // 抛出一个out_of_range异常

    // 改变string
    s1.insert(s1.size(), 5, '!');   // 在s1的末尾插入5个感叹号
    s1.erase(s1.size() - 5, 5);     // 从s1删除最后5个字符

    s1.assign(cp, 7);
    s1.insert(s1.size(), cp + 6);

}

void ahsubstring()
{
    string s("hello world");
    string s2 = s.substr(0, 5);     // s2 = "hello"
    string s3 = s.substr(6);        // s3 = "world"
    string s4 = s.substr(6, 11);    // s4 = "world"
    string s5 = s.substr(12);       // 抛出一个异常out_of_range
}

void AppendAndReplace()
{
    string s("C++ Primer"), s2 = s;
    s.insert(s.size(), " 5th Ed.");  // s == "C++ Primer 5th Ed."
    s2.append(" 5th Ed.");          // 等价方法
    s2 += " 5th Ed.";

    s.replace(11, 3, "Fifth");
}

void sampleuse()
{
    func_49();
    //string name("Wang");
    //cout << add_pre_and_suffix(name, "Mr.", ", Jr.");

    //auto pos1 = name.find("ang");
    //auto pos2 = name.find("w");

    // 数值转换
    int i = 42;
    string s = to_string(i);  // 将整数i转换为字符表示形式
    double d = stod(s);

    string s2 = "pi = +3.14";
    d = stod(s2.substr(s2.find_first_of("+-.1234567890")));

}