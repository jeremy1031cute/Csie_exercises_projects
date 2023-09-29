#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while(num){
        if(num&1){
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int range(int lower, int upper) {
    int total_count = 0;
    for (int num = lower; num <= upper; num++) {
        total_count += countSetBits(num);
    }
    return total_count;
}

int main() {
    int lower, upper;
    scanf("%d %d", &lower, &upper);

    int total_bits = range(lower, upper);

    printf("%d", total_bits);

    return 0;
}
