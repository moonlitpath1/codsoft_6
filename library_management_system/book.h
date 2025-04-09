#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include "database.h"
using namespace std;

void addBook( Database &db)
{
    string title, author, isbn;
    cout<<"Enter title of book: ";
    cin.ignore();
    getline(cin, title);
    cout<<"Enter author of book: ";
    getline(cin, author);
    cout<<"Enter isbn:";
    getline(cin, isbn);


    try
    {
        //connect, then create statement, then add values, then execute it
        //else -- catch error.

        sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO books(title, author, isbn) VALUES(?,?,?)"
        );
        pstmt->setString(1,title);
        pstmt->setString(2,author);
        pstmt->setString(3,isbn);

        pstmt->execute();
        delete pstmt;
        cout<<"Inserted successfully";
    }
    catch(sql::SQLException &e)
    {
        cout<<"Error. Could not insert."<<e.what()<<endl;
    }
}

void searchBook(Database &db)
{
    //keyword
    //pstmt
    //add %around keyword
    //set string
    //execute, store in resultset

    //display. -- 
    //delete

    string keyword;
    cin.ignore();
    getline(cin, keyword);

    try{
        sql::PreparedStatement *pstmt = db.getConnection()->prepareStatement("SELECT * FROM books WHERE title is LIKE ? OR author LIKE ? OR isbn lIKE ? ");

        pstmt->setString(1,keyword);
        pstmt->setString(2,keyword);
        pstmt->setString(3,keyword);
        sql::ResultSet *res = pstmt->executeQuery();

        while(res->next())
        {
            cout<<"|ID: "<<res->getInt("id");
            cout<<"|Title: "<<res->getInt("title");
            cout<<"|Author: "<<res->getInt("author");
            cout<<"|ISBN: "<<res->getInt("isbn");
        }

        delete res;
        delete pstmt;

    }
    catch(sql::SQLException &e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }
}

void showAllBooks(Database &db)
{
    //statement
    //resultset, exevute

    //display
    //del
     try
     {
        sql::Statement *stmt = db.getConnection()->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM books");

        while(res->next())
        {
            cout<<"|ID: "<<res->getInt("id");
            cout<<"|Title: "<<res->getString("title");
            cout<<"|Author: "<<res->getString("author");
            cout<<"|ISBN: "<<res->getString("isbn");
           cout << " | Available: " << (res->getBoolean("available") ? "Yes" : "No") << endl;
        }
        
        delete res;
        delete stmt;
     }
     catch(sql::SQLException& e)
     {
        cout<<"Error: " << e.what() << '\n';
     }
     
}


#endif