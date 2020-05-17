# include <iostream>
# include <vector>

std::string longestPalindrome(std::string s) {
    std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
    int begin = 0, end = 1;

    for (int i = 0; i < s.length();i++) {
        dp[i][i] = true;
        if (i < s.length() - 1 and s[i] == s[i+1]) {
            dp[i][i + 1] = true;
            begin = i;
            end = 2;
        }
    }
    for (int step = 3; step < s.length(); step++){
        for (int i = 0; i + step - 1< s.length();i++){
            int j = i + step - 1;
            if (s[i] == s[j] and dp[i + 1][j - 1]){
                dp[i][j] = true;
                begin = i;
                end = step;
            }
        }
    }

    return s.substr(begin, end);
}

void func(int n){
    std::cout << "抱着" << std::endl;
    if (n == 1) {
        std::cout << "我的小鲤鱼" << std::endl;
        return;
    }
    func(n - 1);
    std::cout << "的我" << std::endl;
}

int main(int argc, const char** argv) {
    //std::cout << longestPalindrome("a") << std::endl;
    func(3);
    return 0;
}