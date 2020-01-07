#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;


class Book{

private:
    string title, author;
    int availableCopies, totalCopies;
public:
    Book(string, string, int, int);

    void setTitle(string);
    void setAuthor(string);
    void setAvailableCopies(int);
    void setTotalCopies(int);
    string getTitle();
    string getAuthor();
    int getAvailableCopies();
    int getTotalCopies();
};
void updateFile(vector<Book>&);
void updateVector(vector<Book>&);
void addBook(vector<Book>&);
void removeBook(string, vector<Book>&);
void modifyBbookRecords(string, vector<Book>&);
void listBooks(vector<Book>&);
void sortBooks(vector<Book>&);
void bookAvailibility(string, vector<Book>&);
int returnBookIndex(string, vector<Book>&);
int menu();



#endif // BOOK_H_INCLUDED
