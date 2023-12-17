#include <stdio.h>
#include <string.h>

#define S 0
#define H 1
#define D 2
#define C 3


int main()
{
    int n;
    int num;
    char color, useless;
    int array[4][13] = {0};
    int count = 0;

    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        while (1) {
            color = fgetc(stdin);
            scanf("%d%c", &num, &useless);

            if (color == 'S')
                array[S][num - 1]++;
            else if (color == 'H')
                array[H][num - 1]++;
            else if (color == 'D')
                array[D][num - 1]++;
            else if (color == 'C')
                array[C][num - 1]++;
            count++;
            if (color == '\n' || useless == '\n') break;
            //if (color == EOF || useless == EOF) break;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 12; j >= 0; j--) {
                if (array[i][j] != 0) {
                    count--;
                    if (i == S)
                        printf("S%d", j + 1);
                    else if (i == H)
                        printf("H%d", j + 1);
                    else if (i == D)
                        printf("D%d", j + 1);
                    else if (i == C)
                        printf("C%d", j + 1);

                    if (count == 0)
                        printf("\n");
                    else
                        printf(" ");

                }
            }
        }
        memset(array, 0, sizeof array);
    }
}
