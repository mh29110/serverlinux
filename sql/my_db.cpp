#include <iostream>
#include <cstdlib>
#include "my_db.h"
using namespace std;

MyDB::MyDB()
{
    mysql_init(&m_connection);
}

MyDB::~MyDB()
{
    if(&m_connection != NULL)
    {
        mysql_close(&m_connection);
    }
}

bool MyDB::initDB(string host ,string user , string pwd ,string db_name)
{
    //mysql_real_connect(&m_connection , "localhost","root","515115q","mysql",0,NULL,0);
    mysql_real_connect(&m_connection,
            host.c_str(),user.c_str() , pwd.c_str(),db_name.c_str(),
            0,NULL,0);
    if(&m_connection == NULL)
    {
        cout << "error2\n";
    }
    else
    {
        cout<< "success!\n";
   }
    return true;
}

bool MyDB::exeSQL(string sql)
{
    if(mysql_query(&m_connection,sql.c_str()) == 0)
    {
        cout<< "success query !\n";
        MYSQL_RES *result = mysql_use_result(&m_connection);
        MYSQL_ROW row;
        int i;
        for (i = 0; i < mysql_field_count(&m_connection); i++) {
            row = mysql_fetch_row(result);
            if(row <= 0 )
            {
                cout << "row <= 0";
                break;
            }
            for (int j = 0; j < mysql_num_fields(result); j++) {
                cout << row[j] << endl;
            }
        }
        mysql_free_result(result);
        cout << "row endl\n" ;
    }
    else
    {
        cout << "query error : " << mysql_error(&m_connection);
    }
    return true;
}
