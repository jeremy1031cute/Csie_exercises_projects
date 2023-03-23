#include <stdio.h>
int SPA_num[3]={0, 0, 0};
int money_u_own=100, hotdog_price=30;
int prize_type(int x);
int flag=0;//如果表格全數被選，可刷新
int n=3;
int cost=500;
int main()
{
    int choose, free_choice=0;
    //表格事前準備、宣告
        int lottery[100][100];
        int real_lottery[100][100];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                lottery[i][j] = i*n+j+1;//有加一
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                real_lottery[i][j] = prize_type(lottery[i][j]) % 9 + 1;
            }
        }
    while(1){
        do{
            printf("Do you want to continue or exit?\n");
            printf("  [1] Continue\n");
            printf("  [2] Exit\n");
            printf("Enter the number(s): ");
            scanf("%d", &choose);
            switch(choose){
                case 2:
                    printf("Speed booster: %d\n", SPA_num[0]);
                    printf("Price booster: %d\n", SPA_num[1]);
                    printf("Area booster: %d\n", SPA_num[2]);
                    printf("Money: %d\n", money_u_own);
                    printf("Free choice: %d\n", free_choice);
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

        while(flag< n*n){
            flag=0;
            //表格列印
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

            //選擇部分
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
            else if(selection == 0)//這個時候selection超出範圍的情況已不存在，調整free與cost的條件就好
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
                        printf("Another open on %d!\n", lottery[n-1][colum]);//若選擇的cell在第一行，那它上方的cell則對應至最後一行
                        real_lottery[row][colum] = -1;
                        row = n-1;
                        goto another_result_display;//因為是免費的所以直接避開限制選擇的部分
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
                        printf("Another open on %d!\n", lottery[0][colum]);//下
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
                        printf("Another open on %d!\n", lottery[row][n-1]);//左
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
                        printf("Another open on %d!\n", lottery[row][0]);//右
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
                SPA_num[0]++;
            }
            else if(real_lottery[row][colum] == 8){
                printf("You get a booster!!\n");
                SPA_num[1]++;
            }
            else if(real_lottery[row][colum] == 9){
                printf("You get a booster!!\n");
                SPA_num[2]++;
            }

            real_lottery[row][colum] = -1;//-1會輸出x

            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if(real_lottery[i][j] == -1)
                        flag++;
                }
            }
            if(flag == n*n){
                n=n+2;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        lottery[i][j] = i*n+j+1;
                        real_lottery[i][j]= prize_type(lottery[i][j]) % 9 + 1;
                        cost=500;
                    }
                }
            }
        }
    }

    return 0;
}
int prize_type(int a){
    int b=0;
	while(a!=0){
		b=b*10+a%10;
		a=a/10;
    }
    b=(b/10)*16+b%10;
	return b;
}
