#include <stdio.h>

void reverse(int array[], int size) {
    int temp;  
    int start = 0;   
    int end = size - 1; 

    while (start < end) {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {

    int array1[] = {10, 20, 30, 40, 50, 50, 40, 30, 20, 10};
    int size1 = 5;
    
    print_array(array1, size1);
    
    reverse(array1, size1);
    
    print_array(array1, size1);
 
    int array2[] = {60, 20, 80, 10, 10, 80, 20, 60};
    int size2 = 4;
  
    print_array(array2, size2);
    
    reverse(array2, size2);
    
    print_array(array2, size2);

    return 0;
}
