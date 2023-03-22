#include <stdio.h>
int main(){
    int blood=0, strength=0, level=0, monster_num, Monster_Strength, choose=1;
    printf("Welcome, Adventurer!\n");

    printf("Please enter blood, strength, level: ");
    scanf("%d%d%d",&blood,&strength,&level);

    while(choose==1){
        printf("You have %d blood and %d strength.\n",blood,strength);

        if(blood<=0){
            printf("You Dead. Bye!");
            return 0;
        }

        printf("Please choose which monster (1 to 4) you want to fight: ");
        scanf("%d",&monster_num);
        if(1<=monster_num&&monster_num<=4)
            printf("You are fighting Monster %d!\n",monster_num);
        else
            printf("No such monster, please enter 1 to 4 to choose the monster.\n");

        switch(monster_num){
            case 1:  Monster_Strength=level;
                    if (strength<=Monster_Strength){
                        blood=blood-(1+level);
                        printf("You Lose!\n");
                    }
                    else{
                        printf("You Win!\n");
                        strength++;
                    }
                      break;
            case 2:  Monster_Strength=(level%2) + 2;
                    if (strength<=Monster_Strength){
                        blood=blood-(2+level);
                        printf("You Lose!\n");
                    }
                    else{
                        printf("You Win!\n");
                        strength++;
                    }
                      break;
            case 3:  Monster_Strength=level > 3 ? level : 3;
                    if (strength<=Monster_Strength){
                        blood=blood-(3+level);
                        printf("You Lose!\n");
                    }
                    else{
                        printf("You Win!\n");
                        strength++;
                    }
                      break;
            case 4: Monster_Strength=level*4;
                    if (strength<=Monster_Strength){
                        blood=blood-(4+level);
                        printf("You Lose!\n");
                    }
                    else{
                        printf("You Win!\n");
                        strength++;
                    }
                      break;
            default:
                      break;
     }

        printf("Do you want to go on your adventure (1: Yes; 0: No) ?: ");
        scanf("%d",&choose);
        if(choose!=1){
            printf("We will miss you. Bye!");
            return 0;
        }

    }

}
