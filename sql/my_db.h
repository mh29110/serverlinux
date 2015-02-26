#ifndef __my_db_h__
#include <iostream>
#include <string>
#include <mysql/mysql.h>
using namespace std;

class MyDB
{
public:
    MyDB();
    ~MyDB();
    bool initDB(string host, string user,string pwd,string db_name);
    bool exeSQL(string sql);
private:
    MYSQL m_connection;
    MYSQL_RES *m_result;
    MYSQL_ROW m_row;
};

#endif
