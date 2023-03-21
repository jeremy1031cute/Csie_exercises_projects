#include <stdio.h>
int gcd(int w1, int w2);
int main(){
    int a, b, c, RunHowManyTimes;

    scanf("%d", &RunHowManyTimes);
    for(int i=0; i<RunHowManyTimes; i++){
        scanf("%d %d", &a, &b);
        if(gcd(a,b) != 1){
            printf("Inverse doesn't exist\n");
        }
        else{
            c=0;
            while(a*c%b != 1){
                c++;
            }
            printf("multiplicative inverse is %d\n", c);
        }
    }

    return 0;
}
int gcd(int w1, int w2){
    int common_factor;
    if(w2>w1)
        common_factor=w1;
    else
        common_factor=w2;

    while(1 < common_factor && w2 != 0 && w1 != 0){
        if(w2%common_factor!=0 || w1%common_factor!=0)
            common_factor--;
        else
            break;
    }

    if(w2 == 0 && w1 == 0)
        common_factor=0;
    else if(w2 == 0 && w1 != 0)
        common_factor=w1;
    else if(w2 != 0 && w1 == 0)
        common_factor=w2;

    return common_factor;
}
