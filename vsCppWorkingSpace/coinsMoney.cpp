# include <iostream>
# include <vector>
# include <limits>
int coinChange(const std::vector<int> &coins, int amount);

int main(int argc, const char **argv){

    int res = coinChange({1, 2, 5}, 100);
    std::cout << res << std::endl;
    return 0;
}

int coinChange(const std::vector<int> & coins,int amount){
    if (amount == 0) {
        return 0;
    }
    int ans = std::numeric_limits<int>::max();
    for (auto coin:coins) {
        if (amount - coin < 0) {
            continue;
        }
        int subProb = coinChange(coins, amount - coin);
        if (subProb == -1) {
            continue;
        }
        ans = std::min(subProb + 1, ans);
    }
    return ans == std::numeric_limits<int>::max() ? -1 : ans;
}

