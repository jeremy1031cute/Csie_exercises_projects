#include <stdio.h>

unsigned int getRangeBits(unsigned int A, int i, int j){
    unsigned int temp = 0;
    int range = j- i;
    for(int k = 0; k <= range; k++){
        temp |= 1 << k;
    }
    A = A >> (i - 1);
    return A & temp;
}

unsigned int concatenate(unsigned int A,int i,int j,unsigned int B,int x,int y){
    unsigned int RA = getRangeBits(A, i, j);
    unsigned int RB = getRangeBits(B, x, y);
    return (RA << (y - x + 1)) | RB;
}

int main(){
    unsigned int V=520 ,M, C, U;
    int run_times;
    scanf("%d", &run_times);

    for(int i = 0; i < run_times; i++){ //keep encoding
        scanf("%d", &M);
        U = V ^ 3610409;
        C = M ^ getRangeBits(U, 1, 8);
        V = concatenate(V, 9, 32, C, 1, 8);
        printf("%d ", C);
    }

    return 0;
}
