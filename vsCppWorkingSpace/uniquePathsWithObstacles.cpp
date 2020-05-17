# include <iostream>
# include <vector>


int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    std::vector<std::vector<long>> dp(obstacleGrid.size(), std::vector<long>(obstacleGrid[0].size(), 0));

    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < dp.size();i++) {
        dp[i][0] = (obstacleGrid[i][0] == 0 and dp[i - 1][0] == 1) ? 1 : 0;
    }

    for (int i = 1; i < dp[0].size();i++) {
        dp[0][i] = (obstacleGrid[0][i] == 0 and dp[0][i - 1] == 1) ? 1 : 0;
    }

    for (int i = 1; i < dp.size();i++) {
        for (int j = 1; j < dp[i].size();j++){
            dp[i][j] = (obstacleGrid[i][j] == 0) ? dp[i - 1][j] + dp[i][j - 1] : 0 ;
        }
    }
    return dp.back().back();
}

int main(int argc, const char** argv) {
    //std::vector<std::vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    std::vector<std::vector<int>> obstacleGrid{{0, 0}};
    std::cout << uniquePathsWithObstacles(obstacleGrid) << std::endl;

    return 0;
}