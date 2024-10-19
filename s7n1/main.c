#include <stdio.h>
#include "dynarray.h"

int main() {
    Dynarray a = init(5);

    for (int i = 0; i < 5; ++i) {
        push_back(&a, 10 * (i + 1));
    }
    print(&a);

    printf("%i\n", pop_back(&a));
    print(&a);

    resize(&a, 7);
    print(&a);

    shrink_to_fit(&a);
    print(&a);

    Dynarray b = shallow_copy(&a);
    print(&b);

    Dynarray c = deep_copy(&a);
    print(&c);

    destroy(&a);
    destroy(&b);
    destroy(&c);

    return 0;
}