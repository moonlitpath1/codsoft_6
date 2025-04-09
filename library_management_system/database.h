#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class Database
{
    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *conn;

    public:
        Database()
        {
            try
            {
                driver = sql::mysql::get_mysql_driver_instance();
                conn = driver->connect("tcp://127.0.0.1:3306", "root", "anu@roxx321");

                conn->setSchema("library");

                cout<<"Database connected successfully"<<endl;            
            }
            catch(sql::SQLException &e)
            {   
                cout<<"Failed tod Connect. Error: "<<e.what()<<endl;
            }
        }

        sql::Connection * getConnection()
        {
            return conn;
        }

        ~Database()
        {
            delete conn;
        }

};


#endif //DATABASE_H