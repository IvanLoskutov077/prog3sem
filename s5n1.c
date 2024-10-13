#include <stdio.h>
#include <math.h>

struct point {
    double x;
    double y;
};
typedef struct point Point;

struct triangle {
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

void print_point(Point p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}

void print_triangle(const Triangle *t) {
    printf("{");
    print_point(t->a);
    printf(", ");
    print_point(t->b);
    printf(", ");
    print_point(t->c);
    printf("}\n");
}

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double get_triangle_perimeter(const Triangle *t) {
    double ab = distance(t->a, t->b);
    double bc = distance(t->b, t->c);
    double ca = distance(t->c, t->a);
    return ab + bc + ca;
}

Triangle moved_triangle(const Triangle *t, Point vector) {
    Triangle new_t;
    new_t.a.x = t->a.x + vector.x;
    new_t.a.y = t->a.y + vector.y;
    new_t.b.x = t->b.x + vector.x;
    new_t.b.y = t->b.y + vector.y;
    new_t.c.x = t->c.x + vector.x;
    new_t.c.y = t->c.y + vector.y;
    return new_t;
}

void move_triangle(Triangle *t, Point vector) {
    t->a.x += vector.x;
    t->a.y += vector.y;
    t->b.x += vector.x;
    t->b.y += vector.y;
    t->c.x += vector.x;
    t->c.y += vector.y;
}

int main() {
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2\n", get_triangle_perimeter(&t));

    Point d = {1.00, 1.00};
    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);

    return 0;
}
