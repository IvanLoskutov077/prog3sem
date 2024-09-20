#include <stdio.h>

int count_even(int array[], int size) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) { 
            count++;
        }
    }
    
    return count;
}

int main() {

    int array1[] = {1, 2, 3, 4, 5, 2};
    int size1 = 5;
    printf("%d\n", count_even(array1, size1));  
    
    int array2[] = {10, 20, 30, 40, 4};
    int size2 = 4;
    printf("%d\n", count_even(array2, size2));  
    
    int array3[] = {10, 1, 1};
    int size3 = 2;
    printf("%d\n", count_even(array3, size3)); 
    
    return 0;
}
