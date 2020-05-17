# include <vector>
# include <iostream>
# include <algorithm>
std::vector<std::vector<int>> result;

void print(const std::vector<int> & nums){
    std::cout << "[";
    for (int i = 0; i < nums.size();i++) {
        std::cout << nums[i];
        if (i != nums.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

void backtrack(const std::vector<int> & nums,std::vector<int> track){
    if (nums.size() == track.size()){
        result.push_back(track);
        return ;
    }
    for (auto item:nums){
        if (std::find(track.begin(),track.end(),item) == track.end()) {
            track.push_back(item);
            backtrack(nums, track);
            track.pop_back();
        }
        
    }
}


int main(int argc, const char** argv) {
    backtrack({1, 2, 3, 4}, {});
    for (auto item : result)
    {
        print(item);
    }
    return 0;
}