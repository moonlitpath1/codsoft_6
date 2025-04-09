#ifndef BORROWER_H
#define BORROWER_H

#include "database.h"
#include <ctime>

string getTodayDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[11];
    sprintf(buf, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    return string(buf);
}

void checkoutBook(Database& db) {
    string name;
    int bookId;

    cout << "\nEnter Borrower Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Book ID to Checkout: ";
    cin >> bookId;

    try {
        sql::PreparedStatement* check = db.getConnection()->prepareStatement(
            "SELECT available FROM books WHERE id = ?");
        check->setInt(1, bookId);
        sql::ResultSet* res = check->executeQuery();

        if (res->next() && !res->getBoolean("available")) {
            cout << "❌ Book is already checked out.\n";
            delete res;
            delete check;
            return;
        }

        delete res;
        delete check;

        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO borrowers (name, book_id, borrow_date) VALUES (?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setInt(2, bookId);
        pstmt->setString(3, getTodayDate());
        pstmt->executeUpdate();
        delete pstmt;

        sql::PreparedStatement* update = db.getConnection()->prepareStatement(
            "UPDATE books SET available = FALSE WHERE id = ?");
        update->setInt(1, bookId);
        update->executeUpdate();
        delete update;

        cout << "Book checked out successfully.\n";
    } catch (sql::SQLException& e) {
        cout << " Error: " << e.what() << endl;
    }
}

void returnBook(Database& db) {
    int bookId;
    cout << "\nEnter Book ID to Return: ";
    cin >> bookId;

    try {
        sql::PreparedStatement* pstmt = db.getConnection()->prepareStatement(
            "UPDATE borrowers SET returned = TRUE, return_date = ? WHERE book_id = ? AND returned = FALSE");
        pstmt->setString(1, getTodayDate());
        pstmt->setInt(2, bookId);
        int rows = pstmt->executeUpdate();
        delete pstmt;

        if (rows == 0) {
            cout << "No such borrowed book found or already returned.\n";
            return;
        }

        sql::PreparedStatement* update = db.getConnection()->prepareStatement(
            "UPDATE books SET available = TRUE WHERE id = ?");
        update->setInt(1, bookId);
        update->executeUpdate();
        delete update;

        cout << "Book returned successfully.\n";
    } catch (sql::SQLException& e) {
        cout << "Error: " << e.what() << endl;
    }
}

#endif
