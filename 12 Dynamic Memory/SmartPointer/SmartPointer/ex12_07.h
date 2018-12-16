#include <iostream>
#include <vector>
#include <memory>

using SPtr = std::shared_ptr<std::vector<int>>;

auto make_with_shared_ptr()
{
    return std::make_shared<std::vector<int>>();
}

auto populate(SPtr vec)
{
    for (int i; std::cout << "Pls Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

auto print(SPtr vec) ->std::ostream&
{
    for (auto i : *vec) std::cout << i << " ";
    return std::cout;
}

int ex12_07()
{
    auto vec = populate(make_with_shared_ptr());
    print(vec) << std::endl;

    return 0;
}