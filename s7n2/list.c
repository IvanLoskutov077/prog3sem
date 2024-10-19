#include "list.h"

List init(size_t n) {
    List list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; ++i) {
        push_back(&list, 0);
    }
    return list;
}

void print(const List* pl) {
    Node* current = pl->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;

    if (pl->tail != NULL) {
        pl->tail->next = new_node;
    }
    pl->tail = new_node;

    if (pl->head == NULL) {
        pl->head = new_node;
    }

    pl->size++;
}

int pop_back(List* pl) {
    if (pl->tail == NULL) {
        return -1; // Пустой список
    }

    Node* tail_node = pl->tail;
    int value = tail_node->value;

    if (pl->head == pl->tail) {
        pl->head = pl->tail = NULL;
    } else {
        pl->tail = tail_node->prev;
        pl->tail->next = NULL;
    }

    free(tail_node);
    pl->size--;
    return value;
}

void push_front(List* pl, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = pl->head;
    new_node->prev = NULL;

    if (pl->head != NULL) {
        pl->head->prev = new_node;
    }
    pl->head = new_node;

    if (pl->tail == NULL) {
        pl->tail = new_node;
    }

    pl->size++;
}

int pop_front(List* pl) {
    if (pl->head == NULL) {
        return -1; // Пустой список
    }

    Node* head_node = pl->head;
    int value = head_node->value;

    if (pl->head == pl->tail) {
        pl->head = pl->tail = NULL;
    } else {
        pl->head = head_node->next;
        pl->head->prev = NULL;
    }

    free(head_node);
    pl->size--;
    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == NULL) {
        return NULL;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        pl->head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        pl->tail = p->prev;
    }

    Node* next_node = p->next;
    free(p);
    pl->size--;
    return next_node;
}

void splice(List* plist, Node* p, List* pother) {
    if (pother->head == NULL) {
        return;
    }

    if (p == NULL) {
        p = plist->head;
    }

    if (p == NULL) {
        plist->head = pother->head;
        plist->tail = pother->tail;
    } else {
        Node* prev_node = p->prev;
        pother->tail->next = p;
        p->prev = pother->tail;

        if (prev_node != NULL) {
            prev_node->next = pother->head;
            pother->head->prev = prev_node;
        } else {
            plist->head = pother->head;
            pother->head->prev = NULL;
        }
    }

    plist->size += pother->size;
    pother->head = pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) {
    while (pl->head != NULL) {
        Node* temp = pl->head;
        pl->head = pl->head->next;
        free(temp);
    }
    pl->head = pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) {
    Node* current = *pp;
    for (size_t i = 0; i < n && current != NULL; ++i) {
        current = current->next;
    }
    *pp = current;
}