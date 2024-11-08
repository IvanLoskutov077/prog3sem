#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book) {
    return book.price > 1000.0;
}

int main() {
    Book book1;
    book1.title = "1984";
    book1.pages = 328;
    book1.price = 999.99;

    Book book2;
    book2.title = "War and Peace";
    book2.pages = 1225;
    book2.price = 1200.0;

    std::cout << "Is the book '" << book1.title << "' expensive? " << (isExpensive(book1) ? "Yes" : "No") << std::endl;
    std::cout << "Is the book '" << book2.title << "' expensive? " << (isExpensive(book2) ? "Yes" : "No") << std::endl;

    return 0;
}