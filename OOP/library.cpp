#include <iostream>

using namespace std;

class Book {
    private:
        string title;
        string author;
        int year;
        int pages;
        bool isAvailable;

    public:
    Book() {
        title = "Unknown";
        author = "Unknown";
        year = 0;
        pages = 0;
        isAvailable = true;
    }

    Book(string t, string au) {
        title = t;
        author = au;
        year = 0;
        pages = 0;
        isAvailable = true;
    }

    Book(string t, string au, int y, int p, bool av) {
        title = t;
        author = au;
        year = y;
        pages = p;
        isAvailable = av;
    }

    string getTitle(){
        return title;
    }
    
    string getAuthor(){
        return author;
    }

    int getYear(){
        return year;
    }

    int getPages(){
        return pages;
    }

    bool getIsAvailable(){
        return isAvailable;
    }

    void setYear(int y){
        if(y > 0){
            year = y;
        } else {
            cout << "Invalid year" << endl;
        }
    }

    void setPages(int p){
        if(p > 0){
            pages = p;
        } else {
            cout << "Invalid pages" << endl;
        }
    }

    Book(const Book &b){
        title = b.title;
        author = b.author;
        year = b.year;
        pages = b.pages;
        isAvailable = b.isAvailable;
    }
    
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Pages: " << pages << endl;
        cout << "Available: " << isAvailable << endl;
    }

};

    int main() {
        Book book2("To Kill a Mockingbird", "Harper Lee", 1960, 281, true);
        book2.display();
        Book book2Copy = book2;
        book2Copy.display();
        book2.setYear(1969);
        book2.setPages(283);
        book2.display();
        book2Copy.display();

        return 0;
    }
    

