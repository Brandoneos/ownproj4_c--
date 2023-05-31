#pragma once

#include <iostream>

#include <sstream>

#include <set>
#include <map>
#include <string>


using namespace std;


//class definition

//function definitions

class LibraryDatabase {
    private:
    
    int numberOfBooks;

    struct BOOK {
        string title;
        string author;
        string publicationYear;

        bool checkedOut;

        bool operator<(const BOOK& other) const {
            return key < other.key;
        }

        int key;  // Add a key field used for comparison
    };
    map<int,BOOK> library;
    

    public:

    void addBook(string title, string author, string publicationYear) {
        BOOK book1;
        book1.author = author;
        book1.title = title;
        book1.checkedOut = false;
        book1.publicationYear = publicationYear;
        library[numberOfBooks] = book1;
        numberOfBooks++;
        
    }

    set<BOOK> searchBook(string query) {
        //make a set for all the searches found, add to the set
        set<BOOK> s1;
        for(int i = 0; i < numberOfBooks; i++) {
            if(library.at(i).author == query) {
                s1.insert(library.at(i));
            }
            if(library.at(i).title == query) {
                s1.insert(library.at(i));
            }
        }
        return s1;
    }

    void displayBooks() {
        cout << "Displaying all books:" << endl;
        cout << endl;
        cout << "-------------------------------" << endl;

        for (int i = 0; i < numberOfBooks; i++) {
            cout << library.at(i).title << endl;
        }

        cout << endl;
        cout << "-------------------------------" << endl;
    }

    int checkOut(string bookname) {
        int ind = 0;
        
        for (int i = 0; i < numberOfBooks; i++) {
            if(library.at(i).title == bookname && !(library.at(i).checkedOut)) {
                ind = 1;
                library.at(i).checkedOut = true;
                return ind;
            }
        }
        return ind;
    }

    void returnBook(string bookname) {
        for (int i = 0; i < numberOfBooks; i++) {
            
            if(library.at(i).title == bookname) {
                library.at(i).checkedOut = false;
                return;
            }
        }
    }

    void clearLibrary() {
        library.clear();
    }

    void action(int& input) {
        if(input == 1) {
            string title;
            string author;
            string year;
            cout << "Enter the title of the book" << endl;
            std::getline(std::cin, title);
            cout << "Enter the author of the book" << endl;
            std::getline(std::cin, author);
            cout << "Enter the publication year of the book" << endl;
            std::getline(std::cin, year);

            addBook(title,author,year);
        } else if(input == 2) {
            string title;
            cout << "Enter the title of the book" << endl;
            std::getline(std::cin, title);
            cout << "Displaying search: " << endl;
            cout << endl;
            for(auto& k : searchBook(title)) {
                cout << k.title << " by " << k.author << endl;
            }

        } else if(input == 3) {
            displayBooks();
        } else if(input == 4) {
            string title;
            int ind = 0;
            cout << "Enter the title of the book" << endl;
            std::getline(std::cin, title);
            ind = checkOut(title);
            if(ind == 1) {
                cout << title << " has been successfully checked out." << endl;
            } else {
                cout << title << " is already checked out." << endl;
            }
            
        } else if(input == 5) {
            string title;
            cout << "Enter the title of the book" << endl;
            std::getline(std::cin, title);
            returnBook(title);
            cout << title << " has been successfully returned." << endl;
        } else {
            input = 6;
            return;
        }
    }



};


using namespace std;
void ending() {
    cout << "Thanks for using this library" << endl;
}

void prompt(int& input) {
    cout << "What would you like to do?" << endl;
    cout << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Search for a book" << endl;
    cout << "3. Display library" << endl;
    cout << "4. Check out a book" << endl;
    cout << "5. Return a book" << endl;
    cout << "6. Exit the program" << endl;
    string inp;
    getline(std::cin, inp);
    input = stoi(inp);
}