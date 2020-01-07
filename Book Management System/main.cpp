#include "bms.h"


int main()
{

    vector<Book> books;
    int ui;
    string bookName;
    do{
        //read from the text file and create vector
        updateVector(books);
        //sort the vector of books alphabetically by title
        sortBooks(books);
        ui = menu();
        cin.ignore();

        switch (ui){
        case 1:
            listBooks(books);
            break;
        case 2:
            addBook(books);
            break;
        case 3:
            cout << "Book to Remove (Title): ";
            getline(cin, bookName);
            cout << endl;
            removeBook(bookName, books);
            break;
        case 4:
            cout << "Book Title: ";
            getline(cin, bookName);
            modifyBbookRecords(bookName, books);
            break;
        case 5:
            cout << "Book Title: ";
            getline(cin, bookName);
            bookAvailibility(bookName, books);
            break;
        case 6:
            //EXIT SYSTEM
            exit(0);
            break;
        default:
            cout << "Please Enter a Valid Expression" << endl;

        }

        //overwrite the vector of books in the file with the vector of books
        updateFile(books);

    }while(ui != 6);

    return 0;
}
