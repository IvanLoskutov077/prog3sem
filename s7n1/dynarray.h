#ifndef DYNARRAY_H
#define DYNARRAY_H

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Dynarray;

Dynarray init(size_t capacity);
void push_back(Dynarray* pd, int value);
int pop_back(Dynarray* pd);
void resize(Dynarray* pd, size_t new_size);
void shrink_to_fit(Dynarray* pd);
Dynarray shallow_copy(Dynarray* pd);
Dynarray deep_copy(const Dynarray* pd);
void print(const Dynarray* pd);
void destroy(Dynarray* pd);

#endif // DYNARRAY_H