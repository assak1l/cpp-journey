#include <iostream>
#include <string>

using namespace std;

class Book {
    public:
    string title;
    string author;
    int year;
    int pages;

    void display(){
        cout << "The title of the book is: " << title << endl;
        cout << "The author of the book is: " << author << endl;
        cout << "The year of the book is: " << year << endl;
        cout << "The pages of the book is: " << pages << endl;
    }
};

int main() {

    Book book1;

cout << "Enter the title of the book: ";
cin >> book1.title;
cout << "Enter the author of the book: ";
cin >> book1.author;
cout << "Enter the year of the book: ";
cin >> book1.year;
cout << "Enter the pages of the book: ";
cin >> book1.pages;



    return 0;
}