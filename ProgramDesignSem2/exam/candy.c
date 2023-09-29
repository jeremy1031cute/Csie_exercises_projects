#include <stdio.h>

int Distribute(int a, int b){
    if((a + b) % 3 != 0){
        return 0;
    }

    if(a < (b / 2) || b < (a / 2)){
        return 0;
    }
    return 1;
}

int main(){
    int t;
    scanf("%d ", &t);

    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);

        int result = Distribute(a, b);

        if(result){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}

