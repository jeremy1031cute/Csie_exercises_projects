
#include <stdio.h>

long long int mini_num(long long int m){
    
    int digits[20];// 𝑚 ≤ 10^9 --> 10 digits
    int numDigits = 0;
    
    if(m == 1)
        return 1;
    for(int i = 9; i > 1; i--){
        while(m % i == 0){
            digits[numDigits++] = i;
            m /= i;
        }
    }

    if(m > 1)
        return -1;//22 11, 34 17, 125 5 5 5 0  

    long long int outcome = 0;
    for(int i = numDigits - 1; i >= 0; i--){ //from small to big
        outcome = outcome*10 + digits[i];
    }

    return outcome;
}

int main(){
    long long int m;
    scanf("%lld", &m);

    long long int q = mini_num(m);

    printf("%lld", q);

    return 0;
}