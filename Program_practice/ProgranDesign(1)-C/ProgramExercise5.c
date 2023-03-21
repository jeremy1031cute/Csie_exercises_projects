#include<stdio.h>
int main(){

int money_u_own=100, speed=15, hotdog_price=30, each_area_min=3*60, choose_which_action;
int money_need_speed_LEVELUP=50, money_need_taste_LEVELUP=100, choose;
printf("Welcome, young boss!\n");
while(choose!=2){
    int Area_num=1, sum=0;
    printf("Chop chop, It's dawn.\n");
    while(Area_num<5){
        printf("You are at Area %d.\n",Area_num++);
        printf("You have %d dollars.\n",money_u_own);
        printf("You need %d minutes to make a hotdog.\n",speed);
        printf("The price of a hotdog is $%d.\n",hotdog_price);

        start:
        printf("Please choose which action you want to take:\n");
        printf("    [1] Sell the hotdogs (+ $%d)\n",(each_area_min/speed)*hotdog_price);
        printf("    [2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n",money_need_speed_LEVELUP);
        printf("    [3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\n",money_need_taste_LEVELUP);

        printf("Enter the number: ");
        scanf("%d",&choose_which_action);
        switch(choose_which_action){
            case 1:
                printf("You make %d hotdogs here!\n",each_area_min/speed);
                money_u_own=money_u_own+(each_area_min/speed)*hotdog_price;
                printf("You earn $%d!\n",(each_area_min/speed)*hotdog_price);
                sum=sum+(each_area_min/speed)*hotdog_price;
            continue;
            case 2:
                if(money_u_own>=money_need_speed_LEVELUP){
                    if(speed!=1){
                        speed--;
                        printf("You glimpse the secret of wind.\n");
                        printf("Your hands can move faster now.\n");
                        money_u_own=money_u_own-money_need_speed_LEVELUP;
                        money_need_speed_LEVELUP=money_need_speed_LEVELUP*2;
                    }
                    else{
                        printf("Do you want to travel through time?\nGO WORK!!\n");
                        printf("You make %d hotdogs here!\n",each_area_min/speed);
                        money_u_own=money_u_own+(each_area_min/speed)*hotdog_price;
                        printf("You earn $%d!\n",(each_area_min/speed)*hotdog_price);
                        sum=sum+(each_area_min/speed)*hotdog_price;
                    }
                }
                else{
                    printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about self-improvement!\n");
                    printf("You make %d hotdogs here!\n",each_area_min/speed);
                    money_u_own=money_u_own+(each_area_min/speed)*hotdog_price;
                    printf("You earn $%d!\n",(each_area_min/speed)*hotdog_price);
                    sum=sum+(each_area_min/speed)*hotdog_price;
                }
            break;
            case 3:
                if(money_u_own>=money_need_taste_LEVELUP){
                    printf("You feel the soul of the ingredients.\n");
                    printf("Your hotdogs are more appetizing now.\n");
                    hotdog_price=hotdog_price+10;
                    money_u_own=money_u_own-money_need_taste_LEVELUP;
                    money_need_taste_LEVELUP=money_need_taste_LEVELUP*2;
                }
                else{
                    printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about self-improvement!\n");
                    printf("You make %d hotdogs here!\n",each_area_min/speed);
                    money_u_own=money_u_own+(each_area_min/speed)*hotdog_price;
                    printf("You earn $%d!\n",(each_area_min/speed)*hotdog_price);
                    sum=sum+(each_area_min/speed)*hotdog_price;
                }
            break;
            default:
                printf("Invalid input!!!!\n");
                goto start;
            break;
        }
    }
            printf("Well done, you earn $%d today.\n",sum);
            con:
            printf("Do you want to continue or exit?\n");
            printf("    [1] Continue\n");
            printf("    [2] Exit\n");
            printf("Enter the number: ");
            scanf("%d",&choose);
            switch(choose){
                case 2:
                    printf("We will miss you. Bye!");
                    return 0;
                    break;
                case 1:
                    continue;
                default:
                    printf("Invalid input!!!!\n");
                    goto con;
                    break;
            }
}

return 0;
}
