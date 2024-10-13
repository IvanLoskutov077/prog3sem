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
    Book stack_book;
    strcpy(stack_book.title, "Don Quixote");
    stack_book.pages = 1000;
    stack_book.price = 750.0;

    Book** book_ptr = (Book**)malloc(sizeof(Book*));
    if (book_ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *book_ptr = &stack_book;
    print_book(*book_ptr);
    free(book_ptr);
    return 0;
}
