#include <stdio.h>
// будем запоминмать уже вычисленные значения для улучшения скорости работы программы и проигрыша в затраченной памяти
unsigned long long trib_cache[39] = {0};

unsigned long long trib(int n) {

    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (trib_cache[n] != 0) {
        return trib_cache[n];
    }

    trib_cache[n] = trib(n - 1) + trib(n - 2) + trib(n - 3);
    
    return trib_cache[n];
}

int main() {

    printf("%llu\n", trib(1));   
    printf("%llu\n", trib(5));  
    printf("%llu\n", trib(20)); 
    printf("%llu\n", trib(35)); 
    printf("%llu\n", trib(38));
    
    return 0;
}
