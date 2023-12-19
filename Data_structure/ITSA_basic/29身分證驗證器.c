int main() {
    char abc[] = "ABCDEFGHJKLMNPQRSTUVXYWZIO";
    int abc_len = strlen(abc);
    int compr[abc_len];
    compr[0] = 10;
    for (int i = 1; i < abc_len; i++) {
        compr[i] = compr[i - 1] + 1;
    }
    char id[11];
    scanf("%s", id);

    int english;
    for (int i = 0; i < abc_len; i++) {
        if (abc[i] == id[0]) {
            english = i;
            break;
        }
    }
    int x1 = compr[english] / 10, x2 = compr[english] % 10;
    //printf("eng:%d id[0]:%d x1:%d x2:%d\n", english, id[0], x1, x2);
    int p = x1 + (9 * x2) + (8 * (id[1] - '0')) + (7 * (id[2] - '0')) + (6 * (id[3] - '0')) + (5 * (id[4] - '0')) + (4 * (id[5] - '0')) + (3 * (id[6] - '0')) + (2 * (id[7] - '0')) + id[8] - '0' + id[9] - '0';
    if (p % 10 == 0)
        printf("CORRECT!!!\n");
    else
        printf("WRONG!!!\n");
}
