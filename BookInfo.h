#include <string>
#include <iostream>


using namespace std;

class Book {
    public:
        //string name;
        string author;
        string category;
        unsigned int pages;
        bool status;

        Book() {};

        Book(/*string n, */string a, string c, unsigned int p, bool s) {
            //name = n;
            author = a;
            category = c;
            pages = p;
            status = s;
        }

        void borrow() {
            if(status) {
                status = false;
                cout<<"book borrowed"<<endl;
            }else {
                cout<<"book already taken"<<endl;
            }

        }

        void return_book() {
            if(!status) {
                status = true;
                cout<<"book returned"<<endl;
            }else {
                cout<<"book already returned"<<endl;
            }

        }
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    //os << "Name: " <<book.name<<endl;
    os << "Author: " <<book.author<<endl;
    os << "Category: " <<book.category<<endl;
    os << "pages: " <<book.pages<<endl;
    if(book.status) {
        os<< "status: avaiable" <<endl;
    }else {
        os<< "status: borrowed" <<endl;
    }

    return os;
}