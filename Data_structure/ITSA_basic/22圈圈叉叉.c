int main(){
    int num[9];
    int flag = 0;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &num[i]);
    }

    if (num[0] == num[1] && num[1] == num[2])
        flag = 1;
    else if (num[3] == num[4] && num[4] == num[5])
        flag = 1;
    else if (num[6] == num[7] && num[7] == num[8])
        flag = 1;

    if (num[0] == num[3] && num[3] == num[6])
        flag = 1;
    else if (num[1] == num[4] && num[4] == num[7])
        flag = 1;
    else if (num[2] == num[5] && num[5] == num[8])
        flag = 1;

    if (num[0] == num[4] && num[4] == num[8])
        flag = 1;
    else if (num[2] == num[4] && num[4] == num[6])
        flag = 1;

    if (flag == 1)
        printf("True\n");
    else
        printf("False\n");

}
