#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
using Map = std::map<std::string, std::size_t>;

//for ex11.3
auto count()
{
    Map counts;
    for (string w; cin >> w; ++counts[w]);
    return counts;
}


//for ex11.4
auto strip(string& str) -> string const&
{
    for (auto& ch : str) 
        ch = tolower(ch);
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

//for ex11.4
auto strip_and_count()
{
    Map counts;
    for (string w; cin >> w; ++counts[strip(w)]);
    return counts;
}

auto print(Map const& m)
{
    for (auto const& kv : m)
        cout << kv.first << " : " << kv.second << "\n";
}

using Families = map<string, vector<string>>;
auto make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            families[ln].push_back(cn);
    return families;
}

auto print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << ":\n";
        for (auto const& child : family.second)
            cout << child << " ";
        cout << "\n";
    }
}

void func_8()
{
    std::vector<std::string> exclude = { "aa", "bb", "cc", "dd", "ee", "ff" };
    for (std::string word; std::cout << "Enter plz:\n", std::cin >> word; )
    {
        auto is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
        auto reply = is_excluded ? "excluded" : "not excluded";
        std::cout << reply << std::endl;
    }
}

void func_12()
{
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int i;
    while (std::cin >> str >> i)
        vec.push_back(std::pair<std::string, int>(str, i));
    //vec.push_back(std::make_pair(str, i));
    //vec.push_back({ str, i });
    //vec.emplace_back(str, i); //!! easiest way.

    for (const auto &p : vec)
        std::cout << p.first << ":" << p.second << std::endl;

}

void func_20()
{
    map<string, size_t> counts;
    for (string word; cin >> word;)
    {
        auto result = counts.insert({ word, 1 });
        if (!result.second)
            ++result.first->second;
    }

    for (auto const& count : counts)
        cout << count.first << " " << count.second << ((count.second > 1) ? " times\n" : " time\n");
}

void SampleUse()
{
    //cout << "[ex11.3] Enter a few words please:\n";
    //print(count());
    //cin.clear();
    /*cout << "[ex11.4] Enter a few words please:\n";
    print(strip_and_count());*/
   // print(make_families());
    func_20();
}

