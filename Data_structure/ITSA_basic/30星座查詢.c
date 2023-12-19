int main() {
    int month, day;
    scanf("%d %d", &month, &day);
    switch (month) {
    case 1:
        if (day >= 21)
            printf("Aquarius\n");
        else
            printf("Capricorn\n");
        break;
    case 2:
        if (day < 19)
            printf("Aquarius\n");
        else
            printf("Pisces\n");
        break;
    case 3:
        if (day >= 21)
            printf("Aries\n");
        else
            printf("Pisces\n");
        break;
    case 4:
        if (day >= 21)
            printf("Taurus\n");
        else
            printf("Aries\n");
        break;
    case 5:
        if (day >= 22)
            printf("Gemini\n");
        else
            printf("Taurus\n");
        break;
    case 6:
        if (day >= 22)
            printf("Cancer\n");
        else
            printf("Gemini\n");
        break;
    case 7:
        if (day >= 23)
            printf("Leo\n");
        else
            printf("Cancer\n");
        break;
    case 8:
        if (day >= 24)
            printf("Virgo\n");
        else
            printf("Leo\n");
        break;
    case 9:
        if (day >= 24)
            printf("Libra\n");
        else
            printf("Virgo\n");
        break;
    case 10:
        if (day >= 24)
            printf("Scorpio\n");
        else
            printf("Libra\n");
        break;
    case 11:
        if (day >= 23)
            printf("Sagittarius\n");
        else
            printf("Scorpio\n");
        break;
    case 12:
        if (day >= 21)
            printf("Capricorn\n");
        else
            printf("Sagittarius\n");
        break;
    }
}

