#include<stdio.h>
     //booster setting
    int SPA_num[3]={5, 5, 5};
    int SPA_open[3]={0, 0, 0};

    //basic setting
    int money_u_own=100, speed=15, hotdog_price=30, each_area_min=180;
    //想法:把money與當天的收入合為陣列，sum後面相加就好 money{(0),1,2,3,4,5}sum=1+2+3+4+5;
    int speed_LEVELUP=50, taste_LEVELUP=100;
    int sum;

    enum Consequence_check{
        lack_of_money_to_upgrade, cannot_reduce_any_time, speed_upgrade, taste_upgrade, sell_hotdogs,
    };

    int each_area_consequence[4];
    int each_area_hotdog_num[4], each_area_money[4];


    void action_of_sell_hotdogs(void);
    int i;//迴圈個別區域用:


int main(){
    //用陣列、函式使程式更簡潔，用if.else來進行booster的加成
    int sell_impro_action[4]={0, 0};
    int choose=1;
    printf("Welcome, young boss!\n");

while(choose != 2){
    sum=0;//sum:算一天的營業額
    int area_five_money=0, area_five_hotdog_num=0, booster_action=0;
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n", money_u_own);
    printf("You need %d minutes to make a hotdog.\n", speed);
    printf("The price of a hotdog is $%d.\n", hotdog_price);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", SPA_num[0], SPA_num[1], SPA_num[2]);

    // choose booster
    while(booster_action!=4){
        printf("Open/Close boosters:\n");
        if (SPA_open[0] == 1)
            printf("  [1] Speed booster (now open)\n");
        else
            printf("  [1] Speed booster (now close)\n");
        if (SPA_open[1] == 1)
            printf("  [2] Price booster (now open)\n");
        else
            printf("  [2] Price booster (now close)\n");
        if (SPA_open[2] == 1)
            printf("  [3] Area  booster (now open)\n");
        else
            printf("  [3] Area  booster (now close)\n");
        printf("  [4] Finish\n");
        printf("Enter the number(s): ");
        scanf("%d",&booster_action);

        switch(booster_action){
            case 1:
                if (SPA_open[0] == 1)
                    SPA_open[0]=0;
                else
                    SPA_open[0]=1;
                break;
            case 2:
                if (SPA_open[1] == 1)
                    SPA_open[1]=0;
                else
                    SPA_open[1]=1;
                break;
            case 3:
                if (SPA_open[2] == 1)
                    SPA_open[2]=0;
                else
                    SPA_open[2]=1;
                break;
            case 4:
                break;
            default:
                printf("Invalid input!!!!\n");
                break;
        }
    }

        if (SPA_num[0]>0){
            if (SPA_open[0] == 1){
                SPA_num[0]--;
            }
        }
        else
            SPA_open[0] = 0;

        if (SPA_num[1]>0){
            if (SPA_open[1] == 1){
                SPA_num[1]--;
            }
        }
        else
            SPA_open[1] = 0;

        if (SPA_num[2]>0){
            if (SPA_open[2] == 1){
                SPA_num[2]--;
            }
        }
        else
            SPA_open[2] = 0;


    // choose action
    printf("Actions you can take for each area:\n");
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");//記得限制分鐘數不能小於1
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", speed_LEVELUP, speed_LEVELUP*2, speed_LEVELUP*4, speed_LEVELUP*8);
    printf("  [3] Improve your hotdog flavor\n");
    printf("      (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", taste_LEVELUP, taste_LEVELUP*2, taste_LEVELUP*4, taste_LEVELUP*8);
    printf("Enter the number(s): ");
    scanf("%d %d %d %d", &sell_impro_action[0], &sell_impro_action[1], &sell_impro_action[2], &sell_impro_action[3]);


    for(i=0; i<4; i++){
        retry:
        switch(sell_impro_action[i]){
            case 1:
                action_of_sell_hotdogs();
                break;
            case 2:
                if(money_u_own >= speed_LEVELUP){
                    if(speed > 1){
                        speed--;
                        money_u_own -= speed_LEVELUP;
                        speed_LEVELUP *= 2;
                        each_area_consequence[i]=speed_upgrade;
                    }
                    else{
                        //printf("Do you want to travel through time?\n");
                        //printf("GO WORK!!\n");
                        action_of_sell_hotdogs();
                        each_area_consequence[i]=cannot_reduce_any_time;
                    }
                }
                else{
                    //printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about self-improvement!\n");
                    action_of_sell_hotdogs();
                    each_area_consequence[i]=lack_of_money_to_upgrade;
                }
                break;
            case 3:
                if(money_u_own >= taste_LEVELUP){
                    hotdog_price += 10;
                    money_u_own -= taste_LEVELUP;
                    taste_LEVELUP *= 2;
                    each_area_consequence[i]=taste_upgrade;
                }
                else{
                    //printf("Can't you tell how poor you are?\nGo vending your hotdogs instead of thinking about self-improvement!\n");
                    action_of_sell_hotdogs();
                    each_area_consequence[i]=lack_of_money_to_upgrade;
                }
                break;
            default:
                printf("Invalid input!!!!\n");
                printf("Actions you can take at Area %d:\n", i+1);
                printf("  [1] Sell the hotdogs\n");
                printf("  [2] Improve your cooking speed\n");
                printf("  [3] Improve your hotdog flavor\n");
                printf("Enter the number(s): ");
                scanf("%d", &sell_impro_action[i]);
                goto retry;

        }
    }
    //區域5分開計算-只賣熱狗
        if (SPA_open[2] == 1){
            if(SPA_open[0] == 1 && SPA_open[1] == 1){
                money_u_own += (each_area_min/speed*2)*hotdog_price*2;
                sum += (each_area_min/speed*2)*hotdog_price*2;
                area_five_money=(each_area_min/speed*2)*hotdog_price*2;
                area_five_hotdog_num=each_area_min/speed*2;
            }
            else if(SPA_open[0] != 1 && SPA_open[1] == 1){
                money_u_own += (each_area_min/speed)*hotdog_price*2;
                sum += (each_area_min/speed)*hotdog_price*2;
                area_five_money=(each_area_min/speed)*hotdog_price*2;
                area_five_hotdog_num=each_area_min/speed;
            }
            else if(SPA_open[0] == 1 && SPA_open[1] != 1){
                money_u_own += (each_area_min/speed*2)*hotdog_price;
                sum += (each_area_min/speed*2)*hotdog_price;
                area_five_money=(each_area_min/speed*2)*hotdog_price;
                area_five_hotdog_num=each_area_min/speed*2;
            }
            else{
                money_u_own += (each_area_min/speed)*hotdog_price;
                sum += (each_area_min/speed)*hotdog_price;
                area_five_money=(each_area_min/speed)*hotdog_price;
                area_five_hotdog_num=each_area_min/speed;
            }
        }


    // end of actions a day
    int result;
    printf("Well done, you earn $%d today.\n", sum);
    while(1){
        printf("Which result of the area you want to check?\n");//設一個儲存結果的陣列
        printf("  [1] Area 1\n");
        printf("  [2] Area 2\n");
        printf("  [3] Area 3\n");
        printf("  [4] Area 4\n");
        if(SPA_open[2] == 1){
            printf("  [5] Area 5\n");
            printf("  [6] Done\n");
        }
        else{
            printf("  [5] Done\n");
        }
        printf("Enter the number(s): ");
        scanf("%d", &result);
        if (result == 5 && SPA_open[2] == 1){
            printf("You make %d hotdogs here!\n", area_five_hotdog_num);//第五區，陣列增加，初始直為0
            printf("You earn $%d!\n", area_five_money);
        }
        else if (SPA_open[2] == 1 && result == 6){
            goto end;
        }
        else if (SPA_open[2] == 0 && result == 5){
            goto end;
        }
        else if (1 <= result && result <= 4){
            switch(each_area_consequence[--result]){
                case lack_of_money_to_upgrade:
                    printf("Can't you tell how poor you are?\n");
                    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    printf("You make %d hotdogs here!\n", each_area_hotdog_num[result]);
                    printf("You earn $%d!\n", each_area_money[result]);
                    break;
                case cannot_reduce_any_time:
                    printf("Do you want to travel through time?\n");
                    printf("GO WORK!!\n");
                    printf("You make %d hotdogs here!\n", each_area_hotdog_num[result]);
                    printf("You earn $%d!\n", each_area_money[result]);
                    break;
                case speed_upgrade:
                    printf("You glimpse the secret of wind.\n");
                    printf("Your hands can move faster now.\n");
                    break;
                case taste_upgrade:
                    printf("You feel the soul of the ingredients.\n");
                    printf("Your hotdogs are more appetizing now.\n");
                    break;
                case sell_hotdogs:
                    printf("You make %d hotdogs here!\n", each_area_hotdog_num[result]);
                    printf("You earn $%d!\n", each_area_money[result]);
                    break;
                default:
                    printf("Invalid input!!!!\n");
                    break;
            }
        }
        else{
            printf("Invalid input!!!!\n");
        }
    }
    end:


    do{
        printf("Do you want to continue or exit?\n");
        printf("  [1] Continue\n");
        printf("  [2] Exit\n");
        printf("Enter the number(s): ");
        scanf("%d", &choose);
        switch(choose){
            case 2:
                printf("We will miss you. Bye!");
                return 0;
            case 1:
                break;
            default:
                printf("Invalid input!!!!\n");
        }
    }while(choose != 2 && choose != 1);
}

return 0;
}

void action_of_sell_hotdogs(void){
    if(SPA_open[0] == 1 && SPA_open[1] == 1){
        money_u_own+=(each_area_min/speed*2)*hotdog_price*2;
        sum+=(each_area_min/speed*2)*hotdog_price*2;
        each_area_consequence[i]=sell_hotdogs;
        each_area_money[i]=(each_area_min/speed*2)*hotdog_price*2;
        each_area_hotdog_num[i]=each_area_min/speed*2;
    }
    else if(SPA_open[0] != 1 && SPA_open[1] == 1){
        money_u_own+=(each_area_min/speed)*hotdog_price*2;
        sum+=(each_area_min/speed)*hotdog_price*2;
        each_area_consequence[i]=sell_hotdogs;
        each_area_money[i]=(each_area_min/speed)*hotdog_price*2;
        each_area_hotdog_num[i]=each_area_min/speed;
    }
    else if(SPA_open[0] == 1 && SPA_open[1] != 1){
        money_u_own+=(each_area_min/speed*2)*hotdog_price;
        sum+=(each_area_min/speed*2)*hotdog_price;
        each_area_consequence[i]=sell_hotdogs;
        each_area_money[i]=(each_area_min/speed*2)*hotdog_price;
        each_area_hotdog_num[i]=each_area_min/speed*2;
    }
    else{
        money_u_own+=(each_area_min/speed)*hotdog_price;
        sum+=(each_area_min/speed)*hotdog_price;
        each_area_consequence[i]=sell_hotdogs;
        each_area_money[i]=(each_area_min/speed)*hotdog_price;
        each_area_hotdog_num[i]=each_area_min/speed;
    }
}
