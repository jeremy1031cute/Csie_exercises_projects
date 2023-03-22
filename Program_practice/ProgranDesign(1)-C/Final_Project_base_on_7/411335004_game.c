#include<stdio.h>
#include <stdlib.h>
#include <time.h>
    void begining_of_actions_a_day();

    //booster setting
    int SPA_num[3]={0, 0, 0};
    int SPA_open[3]={0, 0, 0};
    int booster_distribution();
    void choose_booster();

    int Q=0, Q_x=0, replace_on=0;//設定booster是有週期性的
    int order[15];
    void incre_repla_booster(int x);

    //basic setting
    int money_u_own=100, speed=15, hotdog_price=30, each_area_min=180;
    int speed_LEVELUP=50, taste_LEVELUP=100;
    int sum;

    void area_action();
    enum Consequence_check{
        lack_of_money_to_upgrade, cannot_reduce_any_time, speed_upgrade, taste_upgrade, sell_hotdogs,
    };
    int each_area_consequence[4];
    int each_area_hotdog_num[4], each_area_money[4];
    int area_five_money, area_five_hotdog_num;
    void area_five_caculution();

    void action_of_sell_hotdogs(void);
    int i;//迴圈個別區域用:
    void end_of_actions_a_day();

    //map_system
    void The_map_system(void);

    //grid setting
    int lottery[100][100];
    int real_lottery[100][100];
    void declaration_of_lottery();
    int flag=0;//it will be refresh when all grids are chossen
    int n=3;
    int cost=500;
    int free_choice=0;
    void grid_part();

    //continue
    int choose=1;
    void contin_or_exit();

    //extra_part_little_game
    void SSSpecial_event();

int main(){

    booster_distribution();

    declaration_of_lottery();

    printf("Welcome, young boss!\n");

    while(choose != 2){

        begining_of_actions_a_day();

        choose_booster();

        area_action();

        area_five_caculution();

        end_of_actions_a_day();

        The_map_system();

        contin_or_exit();

        grid_part();

        SSSpecial_event();
    }

return 0;
}

int booster_distribution(){
   int x, y;//x:all booster nums，y: distrebute
   srand( time(NULL) );
   x = rand() % (15-5+1) + 5;
   for(int i=0; i<x; i++){
        y=rand() % (2-0+1) + 0;
        if(y == 0)
            incre_repla_booster(0);
        else if(y == 1)
            incre_repla_booster(1);
        else if(y == 2)
            incre_repla_booster(2);
   }
}

void begining_of_actions_a_day(){
    //check_things_you_own
    sum=0;//sum:sum of business in one day
    area_five_money=0;
    area_five_hotdog_num=0;

    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n", money_u_own);
    printf("You need %d minutes to make a hotdog.\n", speed);
    printf("The price of a hotdog is $%d.\n", hotdog_price);
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", SPA_num[0], SPA_num[1], SPA_num[2]);
}

void declaration_of_lottery(){
    //grid declaration
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            lottery[i][j] = i*n+j+1;//plus one
    }
    srand( time(NULL) );//random number will be different on different time
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            real_lottery[i][j] = rand() % 9 + 1;//set random number's arange 1 to 9
        }
    }
}

void choose_booster(){
    int booster_action=0;
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
}

void incre_repla_booster(int x){
    //Q:the index of order array
    //Q_x : prevent Q from passing the old booster
    if(replace_on == 1 && SPA_num[0]+SPA_num[1]+SPA_num[2] >= 15)
        SPA_num[order[Q_x++]]--;
    SPA_num[x]++;
    order[Q]=x;
    Q++;
    if(Q == 14){
        Q=0;
        replace_on=1;
    }
    if(Q_x == 14)
        Q_x=0;
}
void area_action(){
    int sell_impro_action[4]={0, 0};
    printf("Actions you can take for each area:\n");
    printf("  [1] Sell the hotdogs\n");
    printf("  [2] Improve your cooking speed\n");//min can't be 1
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
void area_five_caculution(){
    //area five only sell hotdogs
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
}
void end_of_actions_a_day(){
    int result;
    printf("Well done, you earn $%d today.\n", sum);
    while(1){
        printf("Which result of the area you want to check?\n");//set an enum array to check out result of each areas
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
            printf("You make %d hotdogs here!\n", area_five_hotdog_num);
            printf("You earn $%d!\n", area_five_money);
        }
        else if (SPA_open[2] == 1 && result == 6){
            break;
        }
        else if (SPA_open[2] == 0 && result == 5){
            break;
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
}
void The_map_system(void){
    char map[8][8];
    int p=0, pp=0;//for P
    srand( time(NULL) );
    int x=rand() % (7-0+1), y=rand() % (7-0+1);//for M
    int g=rand() % (7-0+1), gg=rand() % (7-0+1);//for B
    map[x][y]='M';
    map[g][gg]='B';
    int action=0;
    int b;//for rand()
    while(action != 5){
        map[p][pp]='P';
        for (int i = 0; i < 7; i++){
            for (int j = 0; j < 7; j++){
                if(map[i][j] == 'P')
                    printf("%c ", 'P');
                else if(map[i][j] == 'M')
                    printf("%c ", 'M');
                else if(map[i][j] == 'B')
                    printf("%c ", 'B');
                else
                    printf("%c ", '.');
            }
            printf("\n");
        }
        printf("Which direction you want to move?\n");
        printf("  [1] up\n");
        printf("  [2] down\n");
        printf("  [3] left\n");
        printf("  [4] right\n");
        printf("  [5] end\n");
        printf("Enter the number(s): ");
        scanf("%d", &action);
        if(action == 5){
            printf("You have finished your map exploration!!!\n");
            break;
        }
        else if(money_u_own < 25){
            printf("You have no money!\n");
            break;
        }
        else if(action == 1){
            if(p == 0){
                printf("Invalid input!!!!\n");
            }
            else{
                map[p][pp]='.';
                p-=1;
                money_u_own -= 25;
            }
        }
        else if(action == 2){
            if(p == 7){
                printf("Invalid input!!!!\n");
            }
            else{
                map[p][pp]='.';
                p+=1;
                money_u_own -= 25;
            }
        }
        else if(action == 3){
            if(pp == 0){
                printf("Invalid input!!!!\n");
            }
            else{
                map[p][pp]='.';
                pp-=1;
                money_u_own -= 25;
            }
        }
        else if(action == 4){
            if(pp == 7){
                printf("Invalid input!!!!\n");
            }
            else{
                map[p][pp]='.';
                pp+=1;
                money_u_own -= 25;
            }
        }
        else{
            printf("Invalid input!!!!\n");
        }

        if(p == x && pp ==y){
            printf("You get $%d!\n", x*y*10);
        }
        else if(p == g && pp == gg){
            printf("You get a booster!\n");
            b=rand() % (2-0+1) + 0;
            if(b == 0)
                incre_repla_booster(0);
            else if(b == 1)
                incre_repla_booster(1);
            else if(b == 2)
                incre_repla_booster(2);
        }
    }
}
void contin_or_exit(){
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
                printf("You get one free choice.\n");
                free_choice++;
                break;
            default:
                printf("Invalid input!!!!\n");
        }
    }while(choose != 2 && choose != 1);
}
void grid_part(){
    while(flag< n*n){
        flag=0;
        //print grids
        int max_digit=0;
        int tmp_n= n*n;
        while(tmp_n){
            max_digit++;
            tmp_n /= 10;
        }

        for (int i = 0; i < n; i++){
            printf("+");
            for (int j = 0; j < n; j++){
                for (int k = 0; k < max_digit + 2; k++)
                    printf("-");
                printf("+");
            }
            printf("\n|");
            for (int j = 0; j < n; j++){
                if (real_lottery[i][j] == -1)
                    printf(" %*c |", max_digit/*here is digit of maxima number*/, 'x');
                else
                    printf(" %*d |", max_digit/*here is digit of maxima number*/, lottery[i][j]);
            }
            printf("\n");
        }
        printf("+");
        for (int j = 0; j < n; j++){
            for (int k = 0; k < max_digit + 2; k++)
                printf("-");
            printf("+");
        }
        printf("\n");

        //selection_part
        int selection;
        printf("You can choose\n");
        if(free_choice >= 1)
            printf("  [number on cell] to open (- $0)\n");
        else{
            printf("  [number on cell] to open (- $%d)\n", cost);
        }
        printf("  [0] to continue the game\n");
        printf("Enter the number(s): ");
        scanf("%d", &selection);

        int row = (selection-1) / n ;
        int colum = (selection-1) % n;

        if(selection < 0 || selection > (n*n) || real_lottery[row][colum] == -1){
            printf("Invalid input!!!!\n");
            continue;
        }
        else if(selection == 0)//the condition of selection out of range is impossible,just adjust free and choice
            break;
        else if(money_u_own < cost && free_choice <1){
            printf("You have no money!\n");
            break;
        }
        else if(free_choice >= 1){
            free_choice--;
        }
        else{
            money_u_own -= cost;
            cost += 500;
        }
        //result of prizes
        another_result_display:
        if(real_lottery[row][colum] == 1){
            printf("Fortune, fortune! You get $%d!\n", hotdog_price*100);
            money_u_own += hotdog_price*100;
        }
        else if(real_lottery[row][colum] == 2){
            printf("You get an extra choice!\n");
            free_choice++;
        }
        else if(real_lottery[row][colum] == 3){
            if(row == 0){
                if(real_lottery[n-1][colum] != -1){
                    printf("Another open on %d!\n", lottery[n-1][colum]);//up
                    real_lottery[row][colum] = -1;
                    row = n-1;
                    goto another_result_display;//it's free
                }
                else
                    printf("Bad Luck :(\n");
            }
            else if(real_lottery[row-1][colum] != -1){
                printf("Another open on %d!\n", lottery[row-1][colum]);
                real_lottery[row][colum] = -1;
                row -= 1;
                goto another_result_display;
            }
            else
                printf("Bad Luck :(\n");
        }
        else if(real_lottery[row][colum] == 4){
            if(row == n-1){
                if(real_lottery[0][colum] != -1){
                    printf("Another open on %d!\n", lottery[0][colum]);//down
                    real_lottery[row][colum] = -1;
                    row = 0;
                    goto another_result_display;
                }
                else
                    printf("Bad Luck :(\n");
            }
            else if(real_lottery[row+1][colum] != -1){
                printf("Another open on %d!\n", lottery[row+1][colum]);
                real_lottery[row][colum] = -1;
                row += 1;
                goto another_result_display;
            }
            else
                printf("Bad Luck :(\n");
        }
        else if(real_lottery[row][colum] == 5){
            if(colum == 0){
                if(real_lottery[row][n-1] != -1){
                    printf("Another open on %d!\n", lottery[row][n-1]);//left
                    real_lottery[row][colum] = -1;
                    colum = n-1;
                    goto another_result_display;
                }
                else
                    printf("Bad Luck :(\n");
            }
            else if(real_lottery[row][colum-1] != -1){
                printf("Another open on %d!\n", lottery[row][colum-1]);
                real_lottery[row][colum] = -1;
                colum -= 1;
                goto another_result_display;
            }
            else
                printf("Bad Luck :(\n");
        }
        else if(real_lottery[row][colum] == 6){
            if(colum == n-1){
                if(real_lottery[row][0] != -1){
                    printf("Another open on %d!\n", lottery[row][0]);//right
                    real_lottery[row][colum] = -1;
                    colum = 0;
                    goto another_result_display;
                }
                else
                    printf("Bad Luck :(\n");
            }
            else if(real_lottery[row][colum+1] != -1){
                printf("Another open on %d!\n", lottery[row][colum+1]);
                real_lottery[row][colum] = -1;
                colum += 1;
                goto another_result_display;
            }
            else
                printf("Bad Luck :(\n");
        }
        else if(real_lottery[row][colum] == 7){
            printf("You get a booster!!\n");
            incre_repla_booster(0);
        }
        else if(real_lottery[row][colum] == 8){
            printf("You get a booster!!\n");
            incre_repla_booster(1);
        }
        else if(real_lottery[row][colum] == 9){
            printf("You get a booster!!\n");
            incre_repla_booster(2);
        }

        real_lottery[row][colum] = -1;//-1 will print 'x'

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(real_lottery[i][j] == -1)
                    flag++;
            }
        }
        if(flag >= n*n){
            n=n+2;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    lottery[i][j] = i*n+j+1;
                    srand( time(NULL) );
                    real_lottery[i][j]= rand() % 9 + 1;
                    cost=500;
                }
            }
        }
    }
}
SSSpecial_event(){
    int gift_num;
    while(gift_num != 4){
        printf("Merry Xmas!!!!!!\n");
        printf("you have a chance to get a GIFT\n");
        printf("The prizes is so AMAZING(*O*  U)\n");
        printf("But be careful...\n");
        printf("There is a bomb hide among these gift\nand it will make your hot dog stand break up and you will go bankrupt!!!!\n");
        printf("   (1)		       (2)\n");
        printf("   0O		       QO\n");
        printf("+-------+	+-------+-------+\n");
        printf("|   |   |	|	|	|\n");
        printf("====|====	+-------|-------+\n");
        printf("|   |	|	|	|	|\n");
        printf("+-------+ 	+-------+-------+\n");
        printf("  (3)       0O\n");
        printf("	+-------+\n");
        printf("	|   |   |\n");
        printf("	====|====\n");
        printf("	|   |	|\n");
        printf("	+-------+\n");
        printf("Which gift do you want?\n");
        printf("  [1]\n");
        printf("  [2] \n");
        printf("  [3] \n");
        printf("  [4] give up\n");
        printf("Enter the number(s): ");
        scanf("%d", &gift_num);

        srand( time(NULL) );
        int y;
        y=rand() % (3-1+1) + 1;
        if(gift_num == 4){
            printf("It's a pity...have a nice day!\n");
        }
        else if(gift_num == 1){
            if(y == 1){
                printf("BOMB!!!\n");
                printf("you lose your ALL money QQ\n");
                money_u_own=0;
            }
            else{
                printf("you get $7777!!!\n");
                money_u_own += 7777;
            }
            break;
        }
        else if(gift_num == 2){
            if(y == 1){
                printf("BOMB!!!\n");
                printf("you lose your ALL money QQ\n");
                money_u_own=0;
            }
            else{
                printf("you get 3 booster!!!\n");
                incre_repla_booster(0);
                incre_repla_booster(1);
                incre_repla_booster(2);
            }
            break;
        }
        else if(gift_num == 3){
            if(y == 1){
                printf("BOMB!!!\n");
                printf("you lose your ALL money QQ\n");
                money_u_own=0;
            }
            else{
                printf("NOW your money will double!!!\n");
                printf("you get $%d!!!\n", money_u_own);
                money_u_own *= 2;
            }
            break;
        }
        else{
            printf("Invalid input!!!!\n");
            continue;
        }
    }
}
