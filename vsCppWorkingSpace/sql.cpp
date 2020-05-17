# include <mysql++/mysql++.h>

int main(int argc, const char** argv) {
    mysqlpp::Connection conn(0, "localhost:3306", "root", "990126");
    mysqlpp::Query query = conn.query();
    query << "select User,Host from user";
    return 0;
}
