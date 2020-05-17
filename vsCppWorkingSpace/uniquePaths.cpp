# include <iostream>
# include <vector>

int uniquePaths(int m,int n){
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    for (int i = 0; i < dp.size();i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < dp[0].size();i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < dp.size();i++) {
        for (int j = 1; j < dp[i].size();j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}

int main(int argc, const char** argv) {
    uniquePaths(7, 3);
    return 0;
}