int main() {
    char arr[101];
    gets(arr);
    int back_num, len;
    len = strlen(arr);
    scanf("%d", &back_num);

    for (int i = 0; i < len; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            if (arr[i]+ back_num > '9')
                printf("%c", arr[i] - ('9' - '0' + 1) + back_num);
            else
                printf("%c", arr[i]+ back_num);
        } else if (arr[i] >= 'A' && arr[i] <= 'Z') {
            if (arr[i]+ back_num > 'Z')
                printf("%c", arr[i] - ('Z' - 'A' + 1) + back_num);
            else
                printf("%c", arr[i]+ back_num);
        } else if (arr[i] >= 'a' && arr[i] <= 'z') {
            if (arr[i]+ back_num > 'z')
                printf("%c", arr[i] - ('z' - 'a' + 1) + back_num);
            else
                printf("%c", arr[i]+ back_num);
        }
        else
            printf("%c", arr[i]);
    }
    printf("\n");

}
