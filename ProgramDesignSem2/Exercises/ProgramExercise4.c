#include <stdio.h>
#include <string.h>
int main(){
    int option;
    int len;
    /*option 1*/
    int num = 0;

    /*option 2*/
    int detail_num = 0;

    /*option 3*/
    int check;

    struct history{
        char crime_name[20];
        int date;
        int penalty_months;
    };

    struct data{
        char name[15];
        struct history detail;//treat "struct history" as a struct type
        int count;
    }criminal[10];

    while(1){
        printf("Enter a command: ");
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("Enter a criminal's name: ");
            fgets(criminal[num].name, 15, stdin);
            //scanf("%s", &criminal[num].name);
            len = strlen(criminal[num].name)-1;
            criminal[num].name[len] = '\0';
            if(num <= 10)
                printf("Created new criminal data (number %d).\n", num++);/* number starts from 0 */
            else
                num = 0;//i am not sure xp
            //scanf("%d", &  );
            break;
        case 2:
            printf("Enter a number of the criminal: ");
            scanf("%d", &detail_num);
            printf("Enter crime: ");
            fgets(criminal[detail_num].detail.crime_name, 20, stdin);
            len = strlen(criminal[detail_num].detail.crime_name) - 1;
            criminal[detail_num].detail.crime_name[len] = '\0';
            printf("Enter date: ");
                scanf("%d", &criminal[detail_num].detail.date);
            printf("Enter penalty: ");
                scanf("%d", &criminal[detail_num].detail.penalty_months);
            break;
        case 3:
            printf("Enter a number of the criminal: ");
            scanf("%d", &check);
            printf("Name: %s\n====================\n", criminal[check].name);
            //for(int i; i < ; i++){
                printf("Year: %d, Crime: %s, Penalty: %d months\n", criminal[check].detail.date, criminal[check].detail.crime_name, criminal[check].detail.penalty_months);
            //}
            printf("====================\n");
            break;
        default:
            break;
        }

        if(option == 0) break;
    }


    return 0;
}
