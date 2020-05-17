# include <iostream>
# include <vector>





int coinChange(const std::vector<int> & coins,int amount){
    std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= amount;i++) {
        for (auto coin:coins) {
            if (coin <= i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    for (auto item:dp) {
        std::cout << item << "\t";
    }
    std::cout << std::endl;
    return dp[amount];
}

int main(int argc, const char** argv) {
    coinChange({1, 2, 5}, 11);
    return 0;
}