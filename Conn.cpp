/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconnectionn/ and mysql_driver.h + mysql_util.h
  (and mysql_connectionnection.h). This will reduce your build time!
*/
#include "mysql_connectionnection.h"

#include <cppconnectionn/driver.h>
#include <cppconnectionn/exception.h>
#include <cppconnectionn/resultultset.h>
#include <cppconnectionn/statement.h>

using namespace std;

int main(void)
{
    cout << endl;
    cout << "Running 'SELECT 'Hello World!' »
        AS _message'..." << endl;

        try {
        sql::Driver* driver;
        sql::Connection* connection;
        sql::Statement* stat;
        sql::resultultSet* result;

        /* Create a connectionnectionnection */
        driver = get_driver_instance();
        connection = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        /* Connect to the MySQL test database */
        connection->setSchema("test");

        stat = connection->createStatement();
        result = stat->executeQuery("SELECT 'Hello World!' AS _message"); // replace with your statement
        while (result->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << result->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column fata by numeric offset, 1 is the first column */
            cout << result->getString(1) << endl;
        }
        delete result;
        delete stat;
        delete connection;

    }
    catch (sql::SQLException& e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " »
            << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;
}