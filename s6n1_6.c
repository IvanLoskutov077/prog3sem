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
    Book* heap_book = (Book*)malloc(sizeof(Book));
    if (heap_book == NULL) {
        return 1;
    }
    strcpy(heap_book->title, "Don Quixote");
    heap_book->pages = 1000;
    heap_book->price = 750.0;

    Book** book_ptr = (Book**)malloc(sizeof(Book*));
    if (book_ptr == NULL) {
        free(heap_book);
        return 1;
    }
    *book_ptr = heap_book;
    print_book(*book_ptr);
    free(heap_book);
    free(book_ptr);
    return 0;
}
