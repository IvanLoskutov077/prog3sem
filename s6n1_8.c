#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char* title;
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
        return 1;
    }
    book->title = (char*)malloc(13 * sizeof(char));
    if (book->title == NULL) {
        free(book);
        return 1;
    }
    strcpy(book->title, "Don Quixote");
    book->pages = 1000;
    book->price = 750.0;
    print_book(book);
    free(book->title);
    free(book);
    return 0;
}
