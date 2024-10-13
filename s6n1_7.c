#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book* book) {
    printf("Title: %s, Pages: %d, Price: %.2f\n", book->title, book->pages, book->price);
}

int main() {
    Book* books = (Book*)malloc(3 * sizeof(Book));
    if (books == NULL) {
        return 1;
    }
    strcpy(books[0].title, "Don Quixote");
    books[0].pages = 1000;
    books[0].price = 750.0;

    strcpy(books[1].title, "Oblomov");
    books[1].pages = 400;
    books[1].price = 250.0;

    strcpy(books[2].title, "The Odyssey");
    books[2].pages = 500;
    books[2].price = 500.0;

    for (int i = 0; i < 3; ++i) {
        print_book(&books[i]);
    }
    free(books);
    return 0;
}
