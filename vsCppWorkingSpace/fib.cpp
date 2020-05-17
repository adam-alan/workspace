# include <iostream>
# include <vector>

int fib(int n);

int helper(std::vector<int> &memory, int n);

int main(int argc, const char** argv) {
    
    for (int i = 0; i < 10 ;i++) {
        std::cout << fib(i) << std::endl;
    }

    return 0;
}


int fib(int n) {
    if (n < 1) {
        return 0;
    }
    std::vector<int> memory(n + 1, 0);
    return helper(memory, n);
}

int helper(std::vector<int> & memory,int n) {
    if (n == 1 or n == 2) {
        return 1;
    }
    if (memory[n] != 0) {
        return memory[n];
    }
    memory[n] = helper(memory, n - 1) + helper(memory, n - 2);
    return memory[n];
}
