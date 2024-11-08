#include <iostream>

namespace mipt {
    namespace fefm {
        struct Point {
            int x, y;
        };
    }

    namespace frtk {
        void print(fefm::Point p) {
            std::cout << p.x << " " << p.y << std::endl;
        }
    }
}

int main() {
    using mipt::fefm::Point;
    using mipt::frtk::print;

    Point p;
    p.x = 10;
    p.y = 20;

    print(p);

    return 0;
}