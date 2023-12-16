#include <stdio.h>

int main()
{
    int season = 0;

    scanf("%d", &season);
    if (season >= 3 && season <= 5)
        printf("Spring");
    else if (season >= 6 && season <= 8)
        printf("Summer");
    else if (season >= 9 && season <= 11)
        printf("Autumn");
    else
        printf("Winter");
    printf("\n");

    return 0;
}
