# include <iostream>
# include <vector>
# include <string>

template<typename T>
std::ostream & operator << (std::ostream & s,const std::vector<T> v){
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    std::cout << comma << std::endl;
    return s << ']';
}

int main(int argc, const char** argv) {
    //std::vector<std::vector<std::string>> s(10, std::vector<std::string>(10, "aa"));
    std::vector<std::string> s(10, "aa");
    std::cout << s << std::endl;
    return 0;
}