#include <iostream>
#include "database.h"
#include "book.h"
#include "borrower.h"

using namespace std;

int main() {
    Database db;
    db.getConnection();

    int choice;
    while (true) {
        cout << "\n======= LIBRARY MANAGEMENT SYSTEM =======\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. List All Books\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(db); break;
            case 2: searchBook(db); break;
            case 3: showAllBooks(db); break;
            case 4: checkoutBook(db); break;
            case 5: returnBook(db); break;
            case 6: 
                cout << "\nThank you for using the Library Management System. Bye!\n";
                return 0;
            default: cout << " Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
