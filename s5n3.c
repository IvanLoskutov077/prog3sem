#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    double average_rating;
} Game;


int compare_games(const void *a, const void *b) {
    Game *game1 = (Game *)a;
    Game *game2 = (Game *)b;
    if (game1->average_rating > game2->average_rating) {
        return -1;
    } else if (game1->average_rating < game2->average_rating) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    Game *games = (Game *)malloc(n * sizeof(Game));

    for (int i = 0; i < n; i++) {
        char temp;
        scanf("%[^:]", games[i].title);
        scanf("%c", &temp);

        int k;
        scanf("%d", &k);

        int sum = 0;
        for (int j = 0; j < k; j++) {
            int rating;
            scanf("%d", &rating);
            sum += rating;
        }

        games[i].average_rating = (double)sum / (double)k;
        getchar();
    }

    qsort(games, n, sizeof(Game), compare_games);

    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].average_rating);
    }

    free(games);
    return 0;
}
