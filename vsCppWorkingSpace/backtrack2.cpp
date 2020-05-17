# include <vector>
# include <iostream>
# include <algorithm>

using Board = std::vector<std::vector<char>>;

std::vector<Board> result;

bool isValid(const Board & board,int row,int column){
    for (int i = 0; i < board.size();i++){
        if (board[i][column] == 'Q') {
            return true;
        }
    }

    for (int i = row - 1,j = column + 1; i >= 0  and j < board.size();i--,j++){
        if (board[i][j] == 'Q') {
            return true;
        }
    }

    for (int i = row - 1,j = column - 1; i >= 0  and j >= 0;i--,j--){
        if (board[i][j] == 'Q') {
            return true;
        }
    }
    return false;
}

void backtrace(Board & board,int row){
    if (row == board.size()){
        result.push_back(board);
        return;
    }

    for (int column = 0; column < board[row].size();column++){
        if (!isValid(board,row,column)){
            board[row][column] = 'Q';
            backtrace(board, row + 1);
            board[row][column] = '.';
        }
    }
}
void print(const std::vector<char> & row){
    std::cout << "[";
    for (int i = 0; i < row.size();i++) {
        std::cout << row[i];
        if (i != row.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}
int main(int argc, const char** argv) {
    Board board(8, std::vector<char>(8, '.'));
    backtrace(board, 0);
    std::cout << result.size() << std::endl;
    for (auto item : result)
    {
        for (auto item1:item){
            print(item1);
        }
        std::cout << std::endl;
    }
    return 0;
}