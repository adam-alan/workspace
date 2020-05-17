#include <algorithm>
#include <atomic>
#include <iostream>
#include <iterator>
#include <list>
using list = std::list<size_t>;

void printVector(const list &result)
{
    std::cout << "[";
    std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(std::cout, ","));
    std::cout << "]" << std::endl;
}

list getFactor(const std::size_t &num)
{
    list result;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            result.push_back(i);
        }
    }
    return result;
}
bool notMistake(size_t num, list result)
{
    size_t resultNum = 1;
    for (auto iter : result)
    {
        resultNum *= iter;
    }
    if (resultNum == num)
    {
        return true;
    }
    return false;
}
void breakDown(const std::size_t &num, const std::size_t total, list result, const list factor)
{

    if (num == 1 and notMistake(total, result))
    {
        printVector(result);
        return;
    }
    if (num < 1 or num == 1)
    {
        return;
    }

    for (std::size_t iter : factor)
    {
        if (iter == 1 and std::find(result.begin(), result.end(), 1) != result.end())
        {
            continue;
        }

        list newResult = result;
        newResult.push_back(iter);
        breakDown(num / iter, total, newResult, factor);
    }
}

int main(int argc, char const *argv[])
{
    breakDown(10, 10, list(), getFactor(10));
    return 0;
}
