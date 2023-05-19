#include <stdio.h>

unsigned short swap_bytes(unsigned short i);

int main(){
    unsigned short num;
    scanf("%hx", &num);
    printf("%hx", swap_bytes(num));
}

unsigned short swap_bytes(unsigned short i){
    return (i << 8) | (i >> 8);
}
