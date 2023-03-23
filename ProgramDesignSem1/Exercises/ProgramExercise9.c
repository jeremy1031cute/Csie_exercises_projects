#include<stdio.h>

void query_1();
int fact(int n);

void query_2();

void query_3();
int binomial_coefficients(int n, int k);

void query_4();
long long int caculate_xPOWERy(long long int x, int y, int m);

int main(){
    //請使用者輸入進行計算的次數
    int query_nums;
    printf("How many queries do you want: ");
    scanf("%d", &query_nums);

    //持續進行演算
    int type_choose=0;
    for(int i=0;i < query_nums;i++){
        retry:
        printf("Which type of query do you want: ");
        scanf("%d", &type_choose);

        if(type_choose == 1)
            query_1();
        else if(type_choose == 2)
            query_2();
        else if(type_choose == 3)
            query_3();
        else if(type_choose == 4)
            query_4();
        else
            goto retry;
    }
    return 0;
}
void query_1(){
    int N;
    printf("Please enter N: ");
    scanf("%d", &N);
    N = fact(N);
    printf("%d\n", N);
}
int fact(int n){
	  if (n == 0)
	    return 1;
	  else
	    return n*fact(n - 1);
}

void query_2(){
    int i;
    printf("Please enter i: ");
    scanf("%d", &i);
    if(i == 0)
        printf("0\n");
    else if(i == 1)
        printf("1\n");
    else if(2 <= i && i <= 15){
        int Fibonaccimal[15];
        Fibonaccimal[0]=1;
        Fibonaccimal[1]=1;
        for(int j=2; j<15; j++){
            //先計算題目有限制的15位數
            Fibonaccimal[j]=Fibonaccimal[j-1]+Fibonaccimal[j-2];
        }
        printf("%d\n",Fibonaccimal[i-1]);//減1是因為結果印出的序列並不包含0 ==> (0),1,1,2,3,5,8...
    }
}

void query_3(){
    int n, k;
    printf("Please enter n and k: ");
    scanf("%d %d", &n, &k);
    n=binomial_coefficients(n, k);
    printf("%d\n", n);
}
int binomial_coefficients(int n, int k){
    if (n == k || k == 0)
        return 1;
    else
        return binomial_coefficients(n-1, k)+binomial_coefficients(n-1, k-1);
}

void query_4(){
    long long int x;
    int y, m;
    printf("Please enter x, y and m: ");
    scanf("%lld %d %d", &x, &y, &m);
    x = caculate_xPOWERy(x, y, m);
    printf("%lld\n",x%m);
}
//(訂正)結果過大所以需要long long int!，然後%d改成%lld!
long long int caculate_xPOWERy(long long int x, int y, int m){
    if(y == 1){
        //y is 1
        return x;
    }
    else if(y%2 == 0){
        //y is even
        return (caculate_xPOWERy(x, y/2, m)%m) * (caculate_xPOWERy(x, y/2, m)%m)%m;
    }
    else if(y%2 != 0){
        //y is odd
        return caculate_xPOWERy(x, y-1, m) * caculate_xPOWERy(x, 1, m);
    }
}
