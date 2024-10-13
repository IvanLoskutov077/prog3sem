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
    Book* books = (Book*)malloc(3 * sizeof(Book));
    if (books == NULL) {
        return 1;
    }

    books[0].title = (char*)malloc(13 * sizeof(char));
    if (books[0].title == NULL) {
        free(books);
        return 1;
    }
    strcpy(books[0].title, "Don Quixote");
    books[0].pages = 1000;
    books[0].price = 750.0;

    books[1].title = (char*)malloc(8 * sizeof(char));
    if (books[1].title == NULL) {
        free(books[0].title);
        free(books);
        return 1;
    }
    strcpy(books[1].title, "Oblomov");
    books[1].pages = 400;
    books[1].price = 250.0;

    books[2].title = (char*)malloc(12 * sizeof(char));
    if (books[2].title == NULL) {
        free(books[0].title);
        free(books[1].title);
        free(books);
        return 1;
    }
    strcpy(books[2].title, "The Odyssey");
    books[2].pages = 500;
    books[2].price = 500.0;

    for (int i = 0; i < 3; ++i) {
        print_book(&books[i]);
    }

    free(books[0].title);
    free(books[1].title);
    free(books[2].title);
    free(books);
    return 0;
}
