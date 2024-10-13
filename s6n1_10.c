#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

struct library {
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void print_book(Book* book) {
    printf("Title: %s, Pages: %d, Price: %.2f\n", book->title, book->pages, book->price);
}

void library_create(Library* lib, int number_of_books) {
    lib->number_of_books = number_of_books;
    lib->books = (Book*)malloc(number_of_books * sizeof(Book));
    if (lib->books == NULL) {
        exit(1);
    }
    for (int i = 0; i < number_of_books; ++i) {
        lib->books[i].title = NULL;
    }
}

void library_set(Library lib, int index, const char* title, int pages, float price) {
    if (index < 0 || index >= lib.number_of_books) {
        return;
    }
    if (lib.books[index].title != NULL) {
        free(lib.books[index].title);
    }
    lib.books[index].title = strdup(title);
    lib.books[index].pages = pages;
    lib.books[index].price = price;
}

Book* library_get(Library lib, int index) {
    if (index < 0 || index >= lib.number_of_books) {
        return NULL;
    }
    return &lib.books[index];
}

void library_print(Library lib) {
    for (int i = 0; i < lib.number_of_books; ++i) {
        print_book(&lib.books[i]);
    }
}

void library_destroy(Library* lib) {
    for (int i = 0; i < lib->number_of_books; ++i) {
        if (lib->books[i].title != NULL) {
            free(lib->books[i].title);
        }
    }
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main() {
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
    return 0;
}
