#include "bms.h"

Book::Book(string t, string a, int ac, int tc){
    title = t;
    author = a;
    availableCopies = ac;
    totalCopies = tc;

}

void Book::setTitle(string t){
    title = t;
}
void Book::setAuthor(string a){
    author = a;
}
void Book::setAvailableCopies(int a){
    availableCopies = a;
}
void Book::setTotalCopies(int t){
    totalCopies = t;
}
string Book::getTitle(){
    return title;
}
string Book::getAuthor(){
    return author;
}
int Book::getAvailableCopies(){
    return availableCopies;
}
int Book::getTotalCopies(){
    return totalCopies;
}
int returnBookIndex(string t, vector<Book>& b){

    int index = -1;
    string lowT, lowB;
    lowT = "";
    //construct string of lowercase letters from user input string
    for (unsigned int i = 0; i < t.size(); i++){
        lowT += tolower(t[i]);
    }

    for (unsigned int i = 0; i < b.size(); i++){
        lowB = "";
        //builds string of lowercase characters from vector
        for (unsigned int k = 0; k < b[i].getTitle().size(); k++){
            lowB += tolower(b[i].getTitle()[k]);
        }
        //MATCH FOUND
        if (lowT == lowB){
            index = i;
        }

    }
    return index;


}

void addBook(vector<Book>& b){
    string t, a;
    int tc;
    cout << "\n\nTitle: ";
    getline(cin, t);
    cout << endl;
    cout << "Author: ";
    getline(cin , a);
    cout << endl;
    cout << "Total Copies: ";
    cin >> tc;
    cout << endl;
    Book bo(t, a, tc, tc);
    b.push_back(bo);

    cout << t << " has been added." << endl << endl;

}
void removeBook(string t, vector<Book>& b){

    int index = returnBookIndex(t, b);
    if (index != -1){
        b.erase(b.begin() + index);
        cout << t << " was removed from the system." << endl;

    }else {
        cout << t << " was not found in the system." << endl;
    }

}


void sortBooks(vector<Book>& b){
    //SORTS ALPHABETICALLY BY TITLE
    for (unsigned int i = 0; i < b.size() - 1; i++){
        for (unsigned int j = 0; j < b.size() - 1; j++){
            if (b[j].getTitle() > b[j + 1].getTitle()){
                swap(b[j], b[j + 1]);
            }
        }
    }

}
void bookAvailibility(string t, vector<Book>& b){

    int index;
    index = returnBookIndex(t, b);
    int ac, tc;
    ac = b[index].getAvailableCopies();
    tc = b[index].getTotalCopies();
    if (index != -1){
        cout << "\n";
        cout << "There are " << ac << " copies available of " << t
             << " out of " << tc << " total copies.";
        cout << endl;
    }else {
        cout << t << " was not found in the system." << endl;
    }
    cout << endl;

}


void modifyBbookRecords(string s, vector<Book>& b){
    int bookIndex = returnBookIndex(s, b);
    int ui;
    string temp;

    if (bookIndex == -1){
        cout << s << " was not found in the system." << endl;
    }else {
        do{
            cout << "\n";
            cout << "Book: " << b[bookIndex].getTitle();
            cout << " " << b[bookIndex].getAuthor() << " ";
            cout << b[bookIndex].getAvailableCopies() << " ";
            cout << b[bookIndex].getTotalCopies() << endl << endl;
            cout << "What would you like to modify?" << endl;
            cout << "1) Title"            << endl;
            cout << "2) Author"           << endl;
            cout << "3) Available Copies" << endl;
            cout << "4) Total Copies"     << endl;
            cout << "5) Back"             << endl;

            cin >> ui;
            if (ui == 1){
                cout << "Set Title: " << endl;
                cin.ignore();
                getline(cin, temp);
                b[bookIndex].setTitle(temp);
                cout << "Done." << endl;
            }else if (ui == 2){
                cout << "Set Author: " << endl;
                cin.ignore();
                getline(cin, temp);
                b[bookIndex].setAuthor(temp);
                cout << "Done." << endl;
            }else if (ui == 3){
                cout << "Set Amount of Copies Available: " << endl;
                cin >> ui;
                b[bookIndex].setAvailableCopies(ui);
                cout << "Done." << endl;
            }else if (ui == 4){
                cout << "Set Total: " << endl;
                cin >> ui;
                b[bookIndex].setTotalCopies(ui);
                cout << "Done." << endl;
            }else if (ui == 5){
                //Do Nothing
            }else {
                cout << "Please enter a valid expression." << endl;
            }

        }while(ui != 5);
        cout << endl << endl;
    }


}
void listBooks(vector<Book>& b){
    cout << setw(52) << right << "BOOK LIST" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    cout << setfill(' ');
    cout << setw(35) << left << "Title";
    cout << setw(20) << left << "Author";
    cout << setw(20)  << left << "Copies Available";
    cout << setw(12)  << left << "Total Copies" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    cout << setfill(' ');
    for (unsigned int i = 0; i < b.size(); i++){
        cout << setw(35) << left << b[i].getTitle();
        cout << setw(20) << left << b[i].getAuthor();
        cout << setw(20) << left << b[i].getAvailableCopies();
        cout << setw(12) << left << b[i].getTotalCopies();
        cout << endl;
    }
    cout << endl << endl;

}

int menu(){
    string ui;
    int uiInt;
    bool valid;

    cout << "---------------------------" << endl;
    cout << "BOOK MANAGEMENT SYSTEM MENU" << endl;
    cout << "---------------------------" << endl;
    cout << "1) List Books"               << endl;
    cout << "2) Add Book"                 << endl;
    cout << "3) Remove Book"              << endl;
    cout << "4) Modify Book"              << endl;
    cout << "5) Check Book Availability"  << endl;
    cout << "6) Exit System"              << endl;
    cout << "---------------------------" << endl;
    cout << "=> ";
    do{
        valid = true;
        cin >> ui;
        for (unsigned int i = 0; i < ui.size(); i++){
            if (!isdigit(ui[i])){
                valid = false;
            }else {
                cin.clear();
            }
        }

        if (!valid){
            cout << "Please Enter a Valid Expression." << endl;
            cout << "=> ";
        }

    }while(!valid);

    uiInt = stoi(ui);

    return uiInt;

}
void updateFile(vector<Book>& b){
    ofstream file;
    file.open("book system.txt");
    if (!file){
        cout << "There was an error opening the file";
    }else{
        for (unsigned int i = 0; i < b.size(); i++){
            file << b[i].getTitle() << "%";
            file << b[i].getAuthor() << "%";
            file << b[i].getAvailableCopies() << "%";
            file << b[i].getTotalCopies() << endl;
        }
    }

    file.close();
}
void updateVector(vector<Book>& b){

    ifstream file;
    string line, title, author, tempAC, tempTC;
    int counter, bookCounter, availableCopies, totalCopies;

    bookCounter = 0;
    b.clear();

    file.open("book system.txt");
    if (!file){
        cout << "There was an error opening the file";
    }else {
        while (getline(file, line)){
            //empties string for next line
            tempAC = tempTC = title = author = "";

            //keeps track of if program reading title or author, ect
            counter = 1;
            for (unsigned int i = 0; i < line.size(); i++){
                //move to next section of line
                if (line[i] == '%'){
                    counter++;
                }
                else if (counter == 1){
                    title += line[i];

                }else if (counter == 2){
                    author += line[i];
                }else if (counter == 3){
                    if (isdigit(line[i])){
                        tempAC += line[i];
                    }
                }else if (counter == 4){
                    if (isdigit(line[i])){
                        tempTC += line[i];
                    }
                }
            }
            availableCopies = stoi(tempAC);
            totalCopies = stoi(tempTC);
            Book bo(title, author, availableCopies, totalCopies);
            b.push_back(bo);
            bookCounter++;
        }
    }


    file.close();

}
