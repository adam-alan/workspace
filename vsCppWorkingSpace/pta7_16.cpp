# include <iostream>
# include <vector>
# include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void getNumberVector(vector<int> nums, vector<int> result);
vector<vector<int>> resultSet;

int main(int argc, char const *argv[])
{
    int number = 0;
    cin >> number;
    vector<int> nums;
    for (int i = 0; i < 4;i++)
    {
        nums.push_back(number + i);
    }
    getNumberVector(nums, {});
    int counter = 0;
    for (auto var : resultSet)
    {
        for (auto iter:var) {
            cout << iter;
        }
        counter += 1;
        if (counter % 6 == 0) {
            cout << endl;
        } else{
            cout << " ";
        }
    } 
    return 0;
}


void getNumberVector(vector<int> nums,vector<int> result) {
    if (nums.size() == 1) {
        resultSet.push_back(result);
        return;
    }

    for (auto var:nums) {
        vector<int> newResult = result;
        newResult.push_back(var);
        vector<int> restNums = nums;
        auto iter = std::find(restNums.begin(), restNums.end(), var);
        restNums.erase(iter);
        getNumberVector(restNums, newResult);
    }
}