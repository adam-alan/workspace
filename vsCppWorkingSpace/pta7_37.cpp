# include <iostream>
# include <vector>
# include <algorithm>
# include <set>
# include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::vector;

set<vector<int>> resultSet;

void getNumberVector(int num,int begin, vector<int> result);


int main(int argc, char const *argv[])
{
    int number = 0;
    cin >> number;
    getNumberVector(number, 0, {});

    
    int counter = 0;
    for (auto var : resultSet)
    {
        counter += 1;
        cout << number << "=";
        for (auto iter = var.begin(); iter != var.end(); iter++)
        {
            cout << *iter;
            if (iter != prev(var.end(),1)) {
                cout << "+";
            }
        }
        if (var != *prev(resultSet.end()) and counter % 4 != 0) {
            cout << ";";
        }
        if (counter % 4 == 0){
            cout << endl;
        } 
    }
    return 0;
}

void getNumberVector(int num,int begin, vector<int> result) {
    if (num == 0) {
        sort(result.begin(), result.end());
        resultSet.insert(result);
        return;
    }
    if (num < 0) {
        return;
    }

    for (int i = 1; i <= num;i++) {
        if (i >= begin ) {
            vector<int> newResult = result;
            newResult.push_back(i);
            getNumberVector(num - i, std::max(begin, i), newResult);
        }
    }
}