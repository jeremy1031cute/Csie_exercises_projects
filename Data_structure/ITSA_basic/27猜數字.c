int main() {
    int num;
    scanf("%d", &num);

    int x1, x2, x3, x4;
    x1 = num / 1000;
    num %= 1000;
    x2 = num / 100;
    num %= 100;
    x3 = num / 10;
    num %= 10;
    x4 = num;
    while(1) {
        int guess;
        scanf("%d", &guess);
        if (guess == 0)
            break;

        int g1, g2, g3, g4;
        g1 = guess / 1000;
        guess %= 1000;
        g2 = guess / 100;
        guess %= 100;
        g3 = guess / 10;
        guess %= 10;
        g4 = guess;
        printf("g:%d %d %d %d\n", g1, g2, g3, g4);
        int a = 0, b = 0;
        if (x1 == g1)
            a++;
        else if (x1 == g2 || x1 == g3 || x1 == g4)
            b++;
        if (x2 == g2)
            a++;
        else if (x2 == g1 || x2 == g3 || x2 == g4)
            b++;
        if (x3 == g3)
            a++;
        else if (x3 == g1 || x3 == g2 || x3 == g4)
            b++;
        if (x4 == g4)
            a++;
        else if (x4 == g1 || x4 == g2 || x4 == g3)
            b++;

        printf("%dA%dB\n", a, b);
    }
}
