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
    Book* book = (Book*)malloc(sizeof(Book));
    if (book == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    strcpy(book->title, "Don Quixote");
    book->pages = 1000;
    book->price = 750.0;
    print_book(book);
    free(book);
    return 0;
}
