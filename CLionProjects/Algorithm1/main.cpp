#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
template <typename ForwardIter,typename T>
ForwardIter Parition(ForwardIter begin,ForwardIter end, T pivot) {
    ForwardIter iter = begin++;

    while (begin != end) {

        if (*begin < pivot) {
            //std::cout << *begin << '\t' << *iter << std::endl;
            std::swap(*begin,*iter);
            ++iter;
        }
        ++begin;
    }
    std::swap(*iter,pivot);
    return iter;
}
template <typename ForwardIter>
void QuickSort(ForwardIter begin,ForwardIter end) {
    if (begin != end) {
        auto iter = Parition(begin,end,*begin);
        std::copy(begin,end,std::ostream_iterator<typename ForwardIter::value_type>(std::cout," "));
        std::cout << std::endl;
        QuickSort(begin,iter);
        QuickSort(std::next(iter),end);
    }
}


int main() {
    std::vector<int> ints{5,6,7,8,9,2,45,3,6};
    //Parition(ints.begin(),ints.end(),1);
    QuickSort(ints.begin(),ints.end());
    std::cout << "Hello, World!" << std::endl;
    return 0;
}