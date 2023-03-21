#include<stdio.h>
void Select_the_base_wine ();
void Add_two_wines ();
void Add_juice ();
void Add_CO2 ();
void shake();
void Pull_into_a_glass ();

int f=0;//current flavor level

int main(){
    printf("Let's make our first cocktail!\n");
    Select_the_base_wine ();
    Add_two_wines ();
    Add_two_wines ();
    shake();
    Add_juice ();
    Add_CO2 ();
    Pull_into_a_glass ();

    f=0;
    printf("Let's make our second cocktail!\n");
    Select_the_base_wine ();
    Add_two_wines ();
    shake();
    Add_juice ();
    shake();
    Add_CO2 ();
    Add_two_wines ();
    Add_CO2 ();
    Add_juice ();
    shake();//10
    Add_two_wines ();
    shake();
    Add_two_wines ();
    Add_juice ();
    Add_CO2 ();
    shake();
    Add_CO2 ();
    Add_two_wines ();
    shake();
    Add_juice ();//20
    Add_juice ();
    Add_two_wines ();
    Add_two_wines ();
    Add_CO2 ();
    shake();
    Add_two_wines ();
    shake();
    Add_two_wines ();
    shake();
    Pull_into_a_glass ();
    return 0;
}

void Select_the_base_wine (){
    int b=0;
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
    scanf("%d", &b);
    f+=b;
    printf("The flavor level is %d!\n", f);
}
void Add_two_wines (){
    int common_factor;
    int w1=0, w2=0;
    printf("Now add two kinds of wines.\nPlease Enter two types representing each wine: ");
    scanf("%d %d", &w1, &w2);
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

    f+=common_factor;
    printf("The flavor level increased %d!\n", common_factor);
}
void Add_juice (){
    int j=0;
    printf("Now add some juice.\nPlease Enter flavor level of the juice: ");
    scanf("%d", &j);
    f+=j;
    printf("The flavor level increased %d!\n", j);
}
void Add_CO2 (){
    int c=0;
    printf("Now add some CO2.\nThe current flavor level is %d.\nPlease Enter power of CO2: ",f);
    scanf("%d", &c);
    if(c <= f/2)
        c=c*2;
    else if((f/2) < c && c <= f)
        c=c*3;
    f+=c;
    printf("The flavor level increased %d!\n", c);
}
void shake(){
    int s=0, sum=0;
    printf("Now shake.\n");
    do{
        printf("Please enter the power of a shake(0 to stop): ");
        scanf("%d", &s);
        sum+=s;
    }while(s != 0);
    f+=sum;
    printf("The flavor level increased %d!\n", sum);
}
void Pull_into_a_glass (){
    int t=0;
    printf("Finally, select a wine glass to pull your cocktail in.\n");
    printf("Please enter the number of wine glass(1 to 5): ");
    scanf("%d", &t);
    switch(t){
        case 1:
            t=10;
            break;
        case 2:
            t=15;
            break;
        case 3:
            t=17;
            break;
        case 4:
            t=23;
            break;
        case 5:
            t=40;
            break;
        default:
            break;
    }
    printf("The price increased %d!\n", t);
    f+=t;
    printf("Well done! The Price of this cocktail is %d!\n", f);
}
