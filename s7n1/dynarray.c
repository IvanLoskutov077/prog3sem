#include "dynarray.h"

Dynarray init(size_t capacity) {
    Dynarray dynarray = {(int*)malloc(capacity * sizeof(int)), 0, capacity};
    return dynarray;
}

void push_back(Dynarray* pd, int value) {
    if (pd->size == pd->capacity) {
        pd->capacity = (pd->capacity == 0) ? 1 : pd->capacity * 2;
        pd->data = (int*)realloc(pd->data, pd->capacity * sizeof(int));
    }
    pd->data[pd->size++] = value;
}

int pop_back(Dynarray* pd) {
    if (pd->size == 0) {
        return -1; // Пустой массив
    }
    return pd->data[--pd->size];
}

void resize(Dynarray* pd, size_t new_size) {
    if (new_size > pd->capacity) {
        pd->capacity = new_size;
        pd->data = (int*)realloc(pd->data, pd->capacity * sizeof(int));
    }
    if (new_size > pd->size) {
        for (size_t i = pd->size; i < new_size; ++i) {
            pd->data[i] = 0;
        }
    }
    pd->size = new_size;
}

void shrink_to_fit(Dynarray* pd) {
    if (pd->size < pd->capacity) {
        pd->capacity = pd->size;
        pd->data = (int*)realloc(pd->data, pd->capacity * sizeof(int));
    }
}

Dynarray shallow_copy(Dynarray* pd) {
    Dynarray copy = {pd->data, pd->size, pd->capacity};
    return copy;
}

Dynarray deep_copy(const Dynarray* pd) {
    Dynarray copy = {(int*)malloc(pd->capacity * sizeof(int)), pd->size, pd->capacity};
    for (size_t i = 0; i < pd->size; ++i) {
        copy.data[i] = pd->data[i];
    }
    return copy;
}

void print(const Dynarray* pd) {
    for (size_t i = 0; i < pd->size; ++i) {
        printf("%d ", pd->data[i]);
    }
    printf("\n");
}

void destroy(Dynarray* pd) {
    free(pd->data);
    pd->size = 0;
    pd->capacity = 0;
}