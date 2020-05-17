# include <cassert>
# include <iostream>
# include <vector>
# include <iomanip>

using std::max;
using std::vector;

template <typename T = uint64_t,T m = 1000000000ULL,unsigned places = 9>
class BigInt
{
private:
    vector<T> data_;

public:
    BigInt() = default;
    BigInt(T x) {
        assert(x < m);
        data_.push_back(x);
    }
    BigInt operator+(const BigInt & r) const {
        BigInt sum;
        T carry = 0;
        auto &e = r.data_;
        auto n = max(data_.size(), e.size());
        sum.data_.reserve(n + 1);
        for (auto i = 0; i < n;i++){
            T a = (i < data_.size()) ? data_[i] : 0;
            T b = (i < e.size()) ? e[i] : 0;
            sum.data_.push_back((a + b + carry) % m);
            carry = (a + b + carry) / m;
        }
        if (carry > 0) {
            sum.data_.push_back(carry);
        }
        return sum;
    }

    friend std::ostream & operator<<(std::ostream & os,const BigInt & num){
        auto iter = num.data_.rbegin();
        os << *iter++;
        while (iter != num.data_.rend()) {
            os << std::setfill('0') << std::setw(places) << *iter++;
        }
        return os;
    }
    ~BigInt(){

    };
};

int main(int argc, const char** argv) {
    BigInt<> num1(10000000);
    BigInt<> num2(11010000);
    auto num = num1 + num2;
    std::cout << num << std::endl;
    return 0;
}