#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int option;
    int len;
    int crime_count[10] = {0,0};
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
        struct history detail[10];//change it into array
        int count;//I create another array to count, it won't be used.
    }criminal[10];

    while(1){
                                    //use scanf and fgets both will happen problem like this
        printf("Enter a command: ");//printf and scanf are divided.
        scanf("%d ", &option);
        /*add space to prevent fgets() from reading '\n' character, compiler think that
        there might be more space to scanf, so it will keep the name and print "Enter ..." Preferentially*/
        switch(option){
        case 1:
            printf("Enter a criminal's name: ");
            //fgets(criminal[num].name, 15, stdin);
            scanf("%s", criminal[num].name);
            /*len = strlen(criminal[num].name);
            if(criminal[num].name[len-1] == '\n'){
                criminal[num].name[len-1] = '\0';
                len--;
            }*/
            if(num < 10)
                printf("Created new criminal data (number %d).\n", num++);/* number starts from 0 */
            else
                num = 0;
            break;
        case 2:
            printf("Enter a number of the criminal: ");
            scanf("%d ", &detail_num);
            if(crime_count[detail_num] == 10)
                break;
            printf("Enter crime: ");
            //fgets(criminal[detail_num].detail[crime_count[detail_num]].crime_name, 20, stdin);
            scanf("%s", criminal[detail_num].detail[crime_count[detail_num]].crime_name);
            /*len = strlen(criminal[detail_num].detail[crime_count[detail_num]].crime_name);
            if(criminal[detail_num].detail[crime_count[detail_num]].crime_name[len-1] == '\n'){
                criminal[detail_num].detail[crime_count[detail_num]].crime_name[len-1] = '\0';
                len--;
            }*/
            printf("Enter date: ");
            scanf("%d", &criminal[detail_num].detail[crime_count[detail_num]].date);
            printf("Enter penalty: ");
            scanf("%d", &criminal[detail_num].detail[crime_count[detail_num]].penalty_months);
            crime_count[detail_num]++;
            break;
        case 3:
            printf("Enter a number of the criminal: ");
            scanf("%d", &check);
            fprintf(stderr, "%d %d\n", check, crime_count[check]);
            printf("Name: %s\n====================\n", criminal[check].name);
            for(int i = 0; i < crime_count[check]; i++){
                printf("Year: %d", criminal[check].detail[i].date);
                printf(", Crime: %s, ", criminal[check].detail[i].crime_name);
                printf("Penalty: %d months\n", criminal[check].detail[i].penalty_months);
            }
            printf("====================\n");
            break;
        default:
            break;
        }

        if(option == 0) break;
    }


    return 0;
}
