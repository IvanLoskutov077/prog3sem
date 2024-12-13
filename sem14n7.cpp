#include <iostream>
#include <cstdlib>
#include <new>

template<typename T>
class Manager {
private:
    T* ptr;

public:
    Manager() : ptr(nullptr) {}

    void allocate() {
        ptr = static_cast<T*>(std::malloc(sizeof(T)));
        if (!ptr) {
            throw std::bad_alloc();
        }
    }

    void construct(const T& t) {
        if (!ptr) {
            puts("Memory not allocated");
        }
        new (ptr) T(t);
    }

    void destruct() {
        if (ptr) {
            ptr->~T();
        }
    }

    void deallocate() {
        if (ptr) {
            std::free(ptr);
            ptr = nullptr;
        }
    }

    T& get() {
        if (!ptr) {
            puts("Object not constructed");
        }
        return *ptr;
    }
};

int main() {
    Manager<std::string> a;
    a.allocate();

    a.construct("Cats and dogs");
    a.get() += " and elephant";
    std::cout << a.get() << std::endl;  // Должен напечатать Cats and dogs and elephant
    a.destruct();

    a.construct("Sapere Aude");
    std::cout << a.get() << std::endl;  // Должен напечатать Sapere Aude
    a.destruct();

    a.deallocate();

    return 0;
}