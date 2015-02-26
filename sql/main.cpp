#include <iostream>
#include "my_db.h"
using namespace std;

int main(int argc, const char *argv[])
{
    bool debug = true;
    if(debug)
    {
        MyDB db;
        db.initDB("localhost","root","515115q","student");
        db.exeSQL("select * from student_info");
    }
    else
    {
        MYSQL mysql;
        mysql_init(&mysql);
        if( mysql_real_connect(&mysql , "localhost","root","515115q","student",0,NULL,0))
        {
            if(&mysql == NULL)
            {
                cout << " mysql == null !\n";
            }
            if(mysql_query(&mysql,"select * from student_info") == 0)
            {
                MYSQL_RES *result = mysql_use_result(&mysql);
                MYSQL_ROW row;
                int i;
                for (i = 0; i < mysql_field_count(&mysql); i++) {
                    row = mysql_fetch_row(result);
                    cout << "row " ;
                }
                cout <<i << "endl\n";
                mysql_free_result(result);
            }
            cout<< "success! ";
            cout <<mysql_error(&mysql);
        }
        else
        {
            cout <<mysql_error(&mysql);
        }

    }
      return 0;
}
