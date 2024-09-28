#include <stdio.h>
#include <string.h>

int main() {
    int x = 0, y = 0;
    char direction[10];
    int distance, n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", direction);
        scanf("%d", &distance);

        if (strcmp(direction, "North") == 0) {
            y += distance;
        } else if (strcmp(direction, "South") == 0) {
            y -= distance;
        } else if (strcmp(direction, "East") == 0) {
            x += distance;
        } else if (strcmp(direction, "West") == 0) {
            x -= distance;
        } else {
            printf("Invalid direction.\n");
            continue;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}