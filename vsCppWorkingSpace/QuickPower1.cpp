# include <iostream>
# include <vector>
# include <initializer_list>

int64_t quickPower(int64_t a,int64_t b){
    int64_t ans = 1;
    while(b != 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

class SquareMatrix
{
private:
    std::vector<std::vector<int64_t>> matrix;
public:
    SquareMatrix(int num):
    matrix(num,std::vector<int64_t>(num,0))
    {

    }
    SquareMatrix(const SquareMatrix & other):
    matrix(other.matrix)
    {
    }
    
    SquareMatrix(std::initializer_list<std::initializer_list<int64_t>> list)
    {
        for (const auto & iter:list){
            matrix.push_back(iter);
        }
    }

    ~SquareMatrix(){

    }
    void printMatrix(){
        for(auto rowIter:matrix) {
            for (auto columnIter:rowIter){
                std::cout << columnIter << "\t";
            }
            std::cout << std::endl;
        }
    }
    
    std::size_t size() {
        return matrix.size();
    }
    
    SquareMatrix operator*(const SquareMatrix & other){
        SquareMatrix result(this->size());
        for (int i = 0; i < this->matrix.size(); i++)
        {
            for (int j = 0; j < this->matrix.size();j++) {
                for (int k = 0; k < this->matrix.size();k++){
                    result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
    int64_t getNumFromIndex(int i,int j){
        return this->matrix[i][j];
    }
    SquareMatrix quickPower(int64_t num){
        SquareMatrix result{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        SquareMatrix tmpResult(*this);
        while (num != 0){
            if (num & 1) {
                result = result * tmpResult;
            }
            tmpResult = tmpResult * tmpResult;
            num >>= 1;
        }
        return result;
    }

    friend std::ostream & operator<< (std::ostream &os,const SquareMatrix & squareMatrix);
};

std::ostream & operator<< (std::ostream &os,const SquareMatrix & squareMatrix){
    for(auto rowIter:squareMatrix.matrix) {
        for (auto columnIter:rowIter){
            os << columnIter << "\t";
        }
        os << std::endl;
    }
    return os;
}

int main(int argc, const char** argv) {
    int64_t num = 0;
    std::cin >> num;
    switch (num)
    {
    case 0:
        std::cout << 0 << std::endl;
        break;

    case 1:
        std::cout << 1 << std::endl;
        break;

    case 2:
        std::cout << 1 << std::endl;
        break;
    default:
        SquareMatrix matrix{{1,1,1},{1,0,0},{0,1,0}};
        SquareMatrix result = matrix.quickPower(num - 2);
        std::cout << result.getNumFromIndex(0, 0) + result.getNumFromIndex(0, 1) << std::endl;
        break;
    }
    return 0;
}